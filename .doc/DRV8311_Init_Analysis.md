# DRV8311PRRWR 초기화 코드 분석 및 개선 사항

## 개요
- **사용 IC**: DRV8311PRRWR (tSPI 버전)
- **분석 일자**: 2025-11-21
- **참조 문서**: DRV8311 Datasheet SLVSFN2B

## 1. 현재 코드의 주요 문제점

### 1.1 잘못된 레지스터 주소 사용

#### 문제
현재 `drv8311.h`에서 정의된 기본 레지스터 주소(0x02-0x06)는 **DRV8311P 데이터시트에 존재하지 않음**:

```c
// 현재 코드 (잘못됨)
#define DRV8311_REG_DRIVER_CONTROL      0x02  // ❌ 데이터시트에 없음
#define DRV8311_REG_GATE_DRIVE_HS       0x03  // ❌ 데이터시트에 없음
#define DRV8311_REG_GATE_DRIVE_LS       0x04  // ❌ 데이터시트에 없음
#define DRV8311_REG_OCP_CONTROL         0x05  // ❌ 데이터시트에 없음
#define DRV8311_REG_CSA_CONTROL         0x06  // ❌ 데이터시트에 없음
```

#### 데이터시트 확인 결과
DRV8311P의 실제 레지스터 맵:

| Register Name | Offset | Size | Description |
|--------------|--------|------|-------------|
| DEV_STS1 | 0x00 | 16-bit | Device Status 1 (Read-only) |
| OT_STS | 0x04 | 16-bit | Temperature Status |
| SUP_STS | 0x05 | 16-bit | Supply Status |
| DRV_STS | 0x06 | 16-bit | Driver Status |
| SYS_STS | 0x07 | 16-bit | System Status |
| FLT_MODE | 0x10 | 16-bit | Fault Mode Configuration |
| SYSF_CTRL | 0x12 | 16-bit | System Fault Control |
| DRVF_CTRL | 0x13 | 16-bit | Driver Fault Control |
| PWM_CTRL1 | 0x20 | 16-bit | PWM Control 1 |
| **DRV_CTRL** | **0x22** | **16-bit** | **Predriver Control** |
| **CSA_CTRL** | **0x23** | **16-bit** | **Current Sense Amplifier Control** |
| **SYS_CTRL** | **0x3F** | **16-bit** | **System Control (Unlock Required)** |

### 1.2 레지스터 Lock/Unlock 메커니즘 미비

#### 문제
DRV8311P는 **16비트 레지스터 쓰기 시 SYS_CTRL(0x3F) 레지스터를 통한 unlock이 필요**:

```c
// SYS_CTRL Register (0x3F)
// Bits 14-12: WRITE_KEY = 0x5 (필수)
// Bit 7: REG_LOCK = 0 (unlock)
```

현재 코드는 `DRV8311_EnablePWMGeneration()`에서만 unlock을 수행하지만, **초기화 시 DRV_CTRL(0x22), CSA_CTRL(0x23) 등의 16비트 레지스터를 설정할 때도 unlock이 필요**.

#### 영향
- GATE_DRIVE, OCP_CONTROL 설정이 실제로 적용되지 않을 수 있음
- 레지스터 쓰기 실패 시 SPI 통신 오류 발생 가능

### 1.3 초기화 시퀀스 문제

#### 현재 초기화 순서 (drv8311.c:90-163)
```c
HAL_StatusTypeDef DRV8311_Init(...)
{
    1. CS를 HIGH로 설정
    2. Fault Clear (0x02 레지스터 사용 - ❌ 잘못된 주소)
    3. Gate Drive 설정 (0x03, 0x04 - ❌ 잘못된 주소)
    4. PWM Mode 설정 (0x02 - ❌ 잘못된 주소)
    5. VDS OCP 비활성화 (0x05 - ❌ 잘못된 주소)
    6. PWM Timer 설정
}
```

#### 권장 초기화 순서 (DRV8311P 기준)
```c
1. Power-up 대기 (최소 10ms)
2. SYS_CTRL(0x3F) 레지스터 unlock: 0x5000
3. Fault Clear via FLT_CLR(0x17)
4. DRV_CTRL(0x22) 설정:
   - SLEW_RATE 설정 (bits 1-0)
   - TDEAD_CTRL 설정 (bits 6-4)
5. CSA_CTRL(0x23) 설정:
   - CSA_EN (bit 3)
   - CSA_GAIN (bits 1-0)
6. PWM_CTRL1(0x20) 설정:
   - PWM_MODE 선택 (bits 1-0)
   - SSC_DIS (bit 2)
7. (tSPI PWM Generation 모드 사용 시)
   - PWM_STATE(0x1C) 설정
   - PWMG_PERIOD(0x18) 설정
   - PWMG_CTRL(0x1D) 설정
8. 최종 Fault Status 확인
```

## 2. DRV_CTRL Register (0x22) 분석

### 레지스터 구조
```
Bits 15:    Parity_bit (R)
Bits 14-12: RESERVED
Bits 11-8:  RESERVED
Bit 7:      DLYCMP_EN (Driver Delay Compensation Enable)
Bits 6-4:   TDEAD_CTRL (Deadtime insertion control)
            - 0h = No deadtime (Handshake Only)
            - 1h = 200ns
            - 2h = 400ns
            - 3h = 600ns
            - 4h = 800ns
            - 5h = 1us
            - 6h = 1.2us
            - 7h = 1.4us
Bits 3-2:   RESERVED
Bits 1-0:   SLEW_RATE (Slew rate settings)
            - 0h = 35 V/µs
            - 1h = 75 V/µs
            - 2h = 180 V/µs
            - 3h = 230 V/µs
```

### 권장 설정값
```c
// 중간 Slew Rate + 600ns Deadtime
#define DRV_CTRL_DEFAULT  0x0031  // TDEAD=3 (600ns), SLEW=1 (75V/us)
```

## 3. CSA_CTRL Register (0x23) 분석

### 레지스터 구조
```
Bit 3:     CSA_EN (Current Sense Amplifier Enable)
           - 0h = Disabled
           - 1h = Enabled
Bits 1-0:  CSA_GAIN (Current Sense Amplifier Gain)
           - 0h = 0.25 V/A
           - 1h = 0.5 V/A
           - 2h = 1 V/A
           - 3h = 2 V/A
```

### 권장 설정값
```c
// CSA 활성화 + 0.5V/A 게인
#define CSA_CTRL_DEFAULT  0x0009  // CSA_EN=1, GAIN=1 (0.5 V/A)
```

## 4. tSPI 통신 프로토콜

### tSPI Frame Format (32-bit)
```
8비트 데이터 레지스터 (0x00-0x06):
Bits 31-30: Device Address (2 bits)
Bit 29:     R/W (0=Write, 1=Read)
Bits 28-22: Register Address (7 bits)
Bits 21-14: Data (8 bits)
Bit 13:     Parity (Odd parity)
Bits 12-0:  Reserved

16비트 데이터 레지스터 (0x10 이상):
Bits 31-30: Device Address (2 bits)
Bit 29:     R/W (0=Write, 1=Read)
Bits 28-22: Register Address (7 bits)
Bits 21-6:  Data (16 bits)
Bit 5:      Parity (Odd parity)
Bits 4-0:   Reserved
```

### 현재 구현 상태
✅ Parity 계산 함수 구현됨 (`add_tspi_parity_8bit()`, `add_tspi_parity_16bit()`)
✅ 16비트 레지스터 쓰기 함수 구현됨 (`DRV8311_WriteRegister16()`)
✅ SPI Transfer 타이밍 적절함 (CS setup/hold time)

## 5. 개선 권장 사항

### 5.1 긴급 수정 필요 (Critical)
1. **레지스터 주소 수정**: 0x02-0x06 레지스터 제거 및 올바른 주소 사용
2. **초기화 함수 재작성**: 올바른 레지스터와 순서로 초기화
3. **Unlock 메커니즘 추가**: 모든 16비트 레지스터 쓰기 전에 SYS_CTRL unlock

### 5.2 기능 개선 (Recommended)
1. **Fault 처리 강화**: DEV_STS1, DRV_STS 등의 상태 레지스터 정기 모니터링
2. **Deadtime 설정 추가**: DRV_CTRL(0x22)의 TDEAD_CTRL 설정
3. **Slew Rate 조정 옵션**: EMI/전력 효율 최적화를 위한 설정 가능
4. **CSA 게인 동적 조정**: 전류 감지 범위에 따른 게인 변경

### 5.3 문서화 필요
1. DRV8311P 전용 레지스터 맵 문서 작성
2. 초기화 시퀀스 플로우차트 작성
3. Fault 처리 가이드 작성

## 6. 수정된 초기화 코드 예시

```c
HAL_StatusTypeDef DRV8311_Init(DRV8311_HandleTypeDef *hdrv,
                                SPI_HandleTypeDef *hspi,
                                TIM_HandleTypeDef *htim)
{
    HAL_StatusTypeDef status;

    // Initialize handle
    hdrv->hspi = hspi;
    hdrv->htim = htim;

    // CS HIGH
    HAL_GPIO_WritePin(hdrv->cs_port, hdrv->cs_pin, GPIO_PIN_SET);
    HAL_Delay(10);  // Power-up delay

    // Step 1: Unlock registers
    status = DRV8311_WriteRegister16(hdrv, 0x3F, 0x5000);  // SYS_CTRL unlock
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // Step 2: Clear faults via FLT_CLR(0x17)
    status = DRV8311_WriteRegister16(hdrv, 0x17, 0x0001);  // Clear all faults
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // Step 3: Configure DRV_CTRL (0x22)
    // TDEAD_CTRL=3 (600ns), SLEW_RATE=1 (75V/us)
    status = DRV8311_WriteRegister16(hdrv, 0x22, 0x0031);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // Step 4: Configure CSA_CTRL (0x23)
    // CSA_EN=1, GAIN=1 (0.5V/A)
    status = DRV8311_WriteRegister16(hdrv, 0x23, 0x0009);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // Step 5: Configure PWM_CTRL1 (0x20)
    // PWM_MODE=2 (3-PWM), SSC_DIS=1
    status = DRV8311_WriteRegister16(hdrv, 0x20, 0x0006);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // Step 6: Configure PWM timer
    status = DRV8311_ConfigurePWM(hdrv, hdrv->pwm_frequency);

    printf("[DRV8311-%d] Initialized successfully\r\n", hdrv->device_id);
    return status;
}
```

## 7. 참고 자료

- DRV8311 Datasheet: SLVSFN2B (September 2021, Revised February 2022)
- 변환된 데이터시트: `.doc/drv8311_registers.md`
- 현재 드라이버 코드: `Core/Src/drv8311.c`, `Core/Inc/drv8311.h`

## 8. 결론

현재 DRV8311 드라이버 코드는 **DRV8311H/S (하드웨어 PWM 버전)의 레지스터 맵을 가정**하여 작성되었으나, 실제 사용 중인 IC는 **DRV8311PRRWR (tSPI 버전)**입니다.

두 버전은 레지스터 맵이 완전히 다르므로, **전면적인 코드 재작성이 필요**합니다. 특히:

1. 기본 제어 레지스터 (0x02-0x06) 삭제
2. 16비트 레지스터 (0x10 이상) 사용
3. SYS_CTRL unlock 메커니즘 추가
4. 올바른 초기화 시퀀스 적용

위 개선사항을 적용하면 DRV8311PRRWR의 모든 기능을 정상적으로 사용할 수 있습니다.
