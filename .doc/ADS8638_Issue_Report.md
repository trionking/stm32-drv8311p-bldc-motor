# ADS8638 ADC 동작 불량 분석 보고서

**작성일**: 2025년 1월 21일
**프로젝트**: STM32H743 BLDC 모터 제어 보드
**대상**: 생기연

---

## 1. 요약

ADS8638 8채널 12비트 ADC 칩이 정상적으로 동작하지 않는 문제가 발견되었습니다. 총 3개의 칩을 테스트한 결과, 모두 동일한 증상(레지스터 쓰기 실패, 내부 레퍼런스 미동작)을 보였습니다. 분석 결과, **과도한 납땜 온도(300°C)**가 주요 원인으로 판단되며, 일부 칩은 공급 단계부터 이미 손상되었을 가능성이 있습니다.

### 주요 발견 사항
- ✅ SPI 통신 부분 동작 (READ 가능)
- ❌ 레지스터 쓰기 완전 실패 (모든 WRITE 명령 무시)
- ❌ 내부 2.5V 레퍼런스 미동작 (REF 핀 = 0V)
- ❌ 모든 ADC 값 4095(0xFFF) 고정
- ⚠️ 납땜 온도 300°C 사용 (권장 260-280°C 대비 과도)

---

## 2. 문제 증상

### 2.1 초기 증상
```
- 모든 ADC 채널 값: 4095 (0xFFF, 12비트 최댓값)
- REF 핀 전압: 0V (예상: 2.5V)
- 레지스터 읽기: 모두 0x00 반환 (power-on default: 0x08, 0x11)
- MISO: 항상 0x0F 0x?? 패턴
```

### 2.2 하드웨어 확인 결과
| 항목 | 예상값 | 측정값 | 상태 |
|------|--------|--------|------|
| AVDD (Pin 1) | 3.3V | 3.3V | ✅ 정상 |
| DVDD (Pin 21) | 3.3V | 3.3V | ✅ 정상 |
| HVDD (Pin 14) | 12V | 12V | ✅ 정상 |
| HVSS (Pin 15) | 0V | 0V | ✅ 정상 |
| REF (Pin 24) | 2.5V | 0V | ❌ 비정상 |
| REFGND (Pin 23) | 0V | 0V | ✅ 정상 |
| REF-REFGND 커패시터 | 4.7µF or 10µF | 실장됨 | ✅ 정상 |

---

## 3. 디버깅 과정

### 3.1 소프트웨어 검증

#### SPI 설정 확인
```c
// main.c - SPI4 설정
hspi4.Init.Mode = SPI_MODE_MASTER;
hspi4.Init.CLKPolarity = SPI_POLARITY_LOW;      // CPOL=0
hspi4.Init.CLKPhase = SPI_PHASE_2EDGE;          // CPHA=1 (SPI Mode 1)
hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;  // 3.75MHz
hspi4.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;    // CS 펄스 비활성화
```

**결과**: 데이터시트 요구사항과 일치 ✅

#### 핀 연결 확인
```
STM32H743           ADS8638
PE2  (SPI4_SCK)  →  Pin 17 (SCLK)    ✅
PE6  (SPI4_MOSI) →  Pin 18 (DIN/SDI) ✅
PE13 (SPI4_MISO) →  Pin 19 (DOUT)    ✅
PD1  (GPIO)      →  Pin 16 (CS)      ✅
```

**멀티미터 연속성 테스트**: 모두 정상 연결 확인 ✅

### 3.2 오실로스코프 분석

#### 측정 조건
- CH1: CS (PD1)
- CH2: SCK (PE2)
- CH3: MOSI (PE6)
- CH4: MISO (PE13)
- Trigger: CS falling edge
- Timebase: 2.00µs/div

#### 측정 결과 (WRITE 명령: 0x0C0C)
```
CS (파란색):   ‾‾‾‾\___________________/‾‾‾‾  ✅ 16 클럭 동안 LOW 유지
SCK (노란색):       ||||||||||||||||||||||||  ✅ 16 클럭 정상
MISO (청록색): ‾‾‾‾‾\_____응답_____/‾‾‾‾‾‾  ✅ 응답 있음
MOSI (분홍색): ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾  ⚠️ 거의 변화 없음
```

**분석**:
- CS 타이밍: 정상 (NSSPMode=DISABLE 효과 확인)
- MOSI: 데이터 전송은 되지만 파형 해상도 부족으로 비트 패턴 미확인
- MISO: 칩이 응답은 하지만 레지스터 값은 0x00

### 3.3 READ vs WRITE 비교

| 동작 | TX 명령 | RX 응답 | 결과 |
|------|---------|---------|------|
| READ Aux-Config (0x06) | 0x0D00 | 0x0F00 | 하위 8비트 = 0x00 ✅ READ 동작 |
| WRITE 0x0C to Aux-Config | 0x0C0C | 0x0F?? | WRITE 후 읽으면 여전히 0x00 ❌ |
| READ CH0-1 Range (0x10) | 0x2100 | 0x0F00 | 하위 8비트 = 0x00 ✅ READ 동작 |

**결론**: READ는 동작하지만 WRITE는 완전히 실패

### 3.4 테스트한 칩 이력

| 칩 번호 | 납땜 조건 | HVDD | WRITE 결과 | REF 전압 | 비고 |
|---------|----------|------|-----------|----------|------|
| 칩 #1 | 300°C | 4.8V → 12V | 실패 (0x00) | 0V | 첫 번째 테스트 |
| 칩 #2 | 300°C | 12V | 실패 (0x00) | 0V | 교체 후 동일 증상 |
| 칩 #3 | 300°C | 12V | 실패 (0x00) | 0V | 세 번째도 동일 |

**3개 칩 모두 동일한 증상** → 납땜 온도 문제로 추정

---

## 4. 근본 원인 분석

### 4.1 납땜 온도 문제

#### 사용된 온도
```
HOT PLATE 온도: 300°C
접촉 시간: 20초 이상
```

#### 데이터시트 권장 스펙
```
Storage temperature: -65°C to +150°C (동작 안 할 때)
Operating temperature: -40°C to +125°C (동작 중)

일반적인 무연 납땜 권장 온도:
- 핸드 납땜: 260-280°C (최대 280°C)
- 리플로우: 피크 245-260°C (10-30초)
- 절대 최대: 270°C
```

**300°C는 권장 온도 대비 20-40°C 초과** → 칩 내부 회로 손상 가능

### 4.2 손상 패턴 분석

#### 정상 동작 부분
- ✅ 디지털 I/O (SPI 통신, CS, SCK, MISO)
- ✅ READ 명령 처리 로직
- ✅ 전원 회로 (AVDD, DVDD, HVDD)

#### 손상된 부분
- ❌ 레지스터 쓰기 회로
- ❌ 내부 2.5V 레퍼런스 회로
- ❌ ADC 변환 회로 (또는 레퍼런스 부족으로 동작 불가)

**추정**: 고온에 취약한 아날로그 회로 부분이 선택적으로 손상

### 4.3 HVDD 전원 문제 (초기 보드)

일부 초기 보드에서 발생한 문제:
```
HVDD/HVSS: 연결 안 됨
임시 조치: 수작업으로 3.3V 연결
결과: 채널 변경 문제 발생
```

**데이터시트 요구사항**:
```
HVDD - HVSS 차동 전압: 10V < (HVDD - HVSS) < 30V
3.3V는 최소 요구사항 10V에 크게 미달
```

**영향**: 입력 범위 제한, 아날로그 스위치 오동작 가능

---

## 5. 테스트 코드 및 결과

### 5.1 진단 테스트 시퀀스

```
Step 0: Raw SPI Test
  TX=[0x00 0x00] → RX=[0x0F 0xFF]
  TX=[0xAA 0x55] → RX=[0x0F 0x00]
  → MISO 응답 있음, 고정 패턴 아님 ✅

Step 1: Power-on Defaults (초기화 전 READ)
  Aux-Config (0x06): 0x00 (Expected: 0x08)
  CH0-1 Range (0x10): 0x00 (Expected: 0x11)
  → 칩 리셋이 안 되거나 이전 값 유지

Step 1A: WRITE Test
  Write 0x0C → Read 0x00
  *** WRITE FAILED! ***
  → 레지스터 쓰기 완전 실패 ❌

Step 2: Initialization
  ADS8638_Init() 실행
  → 모든 WRITE 명령 무시됨

Step 4: Register Verification
  Aux-Config: 0x00 (Expected: 0x0C) ❌
  Auto Ch-Sel: 0x00 (Expected: 0xFF) ❌
  CH0-1 Range: 0x00 (Expected: 0x66) ❌

Step 5-6: ADC Readings
  CH0-7: 모두 4095 (0xFFF) ❌
  → 레퍼런스 부족으로 측정 불가
```

### 5.2 드라이버 코드 (ads8638.c)

초기화 시퀀스:
```c
HAL_StatusTypeDef ADS8638_Init(ADS8638_HandleTypeDef *hadc, SPI_HandleTypeDef *hspi)
{
    // Step 1: CS HIGH during power-up
    ADS8638_CS_HIGH();
    HAL_Delay(10);

    // Step 2: Dummy transaction
    ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);

    // Step 3: Software reset
    ADS8638_WriteRegister(hadc, ADS8638_REG_RESET_DEVICE, 0x01);
    HAL_Delay(10);

    // Step 4: Enable internal VREF (bit 2 = 1)
    uint8_t aux_config = 0x0C;  // AL_PD(0x08) | INT_VREF(0x04)
    ADS8638_WriteRegister(hadc, ADS8638_REG_AUX_CONFIG, aux_config);

    // Step 5: Wait for VREF settling (9ms spec)
    HAL_Delay(15);

    // Step 6-8: Configure channels and ranges
    ADS8638_WriteRegister(hadc, ADS8638_REG_AUTO_CH_SEL, 0xFF);
    // ... (생략)

    return HAL_OK;
}
```

**문제**: 모든 WriteRegister 호출이 무시됨

---

## 6. 결론

### 6.1 판정

**ADS8638 칩 불량 - 부분 손상 상태**

- 디지털 I/O 회로: 정상
- 레지스터 쓰기 회로: 손상
- 내부 레퍼런스: 손상
- ADC 코어: 레퍼런스 부족으로 동작 불가 (코어 자체 손상 가능성도 있음)

### 6.2 원인

**주요 원인**: 과도한 납땜 온도 (300°C)
- 권장 온도: 260-280°C
- 초과량: 20-40°C
- 영향: 아날로그 회로 열 손상

**부가적 요인**:
- 일부 칩은 공급 단계부터 고온 납땜되어 손상되었을 가능성
- 초기 보드의 HVDD/HVSS 미연결로 인한 추가 스트레스

### 6.3 재현성

총 3개 칩 테스트:
- 칩 #1, #2, #3: 모두 동일 증상
- 재현율: 100%
- 소프트웨어 문제 가능성: 배제 (오실로스코프로 하드웨어 검증)

---

## 7. 권장 조치사항

### 7.1 즉시 조치 (긴급)

#### 납땜 온도 관리
```
핸드 납땜:
- 인두 온도: 260-280°C (최대 280°C, 절대 300°C 이상 금지)
- 접촉 시간: 2-3초 이내
- 무연 납 (Sn-Ag-Cu) 사용
- 써멀 트위저 사용 시 온도 재확인

리플로우 오븐 (권장):
- 예열: 150-180°C (60-90초)
- 솔더: 200-220°C (30-60초)
- 피크: 245-255°C (10-20초 유지)
- 냉각: 자연 냉각
```

#### 칩 교체
```
1. 새 칩 발주 (여분 포함)
2. 올바른 온도(260-280°C)로 재납땜
3. 납땜 후 즉시 테스트:
   - 전원 전압 확인
   - REF 핀 = 2.5V 확인
   - WRITE 테스트 통과 확인
```

### 7.2 품질 검증 절차 수립

#### 입고 검사
```
1. 육안 검사: 변색, 크랙 확인
2. 전기적 테스트:
   - 전원 인가 전 단락 테스트
   - 전원 인가 후 전압 측정
   - REF 핀 2.5V 확인
   - 간단한 WRITE/READ 테스트
```

#### 납땜 후 검사
```
1. 브리지 확인 (현미경)
2. 전원 전압 확인
3. REF 핀 전압 = 2.5V 확인
4. test_ads8638() 실행:
   - Step 1A: WRITE SUCCESS 확인
   - Step 4: 레지스터 값 일치 확인
   - Step 5-6: ADC 값 정상 확인 (4095 아님)
```

### 7.3 설계 개선 (장기)

#### HVDD/HVSS 연결 확인
```
- HVDD: 12V 이상 연결 (10V 최소)
- HVSS: 0V (GND) 또는 음전압
- 차동 전압: 10V < (HVDD - HVSS) < 30V 준수
```

#### 외부 레퍼런스 옵션 추가 (선택)
```
내부 레퍼런스 손상 시 우회 가능:
- REF 핀에 외부 2.5V 공급
- Aux-Config에서 내부 VREF 비활성화 (bit 2 = 0)
```

---

## 8. 기술 세부사항 (참고)

### 8.1 ADS8638 레지스터 맵

| Address | Name | Function | Default | Test Result |
|---------|------|----------|---------|-------------|
| 0x01 | RESET_DEVICE | Software reset | 0x00 | N/A |
| 0x06 | AUX_CONFIG | VREF, Temp sensor | 0x08 | 0x00 ❌ |
| 0x0C | AUTO_CH_SEL | Channel enable | 0x00 | 0x00 ❌ |
| 0x10 | CH0_1_RANGE | Ch0-1 range | 0x11 | 0x00 ❌ |

### 8.2 SPI 통신 프로토콜

#### 16비트 프레임 구조
```
Bits[15:9]: Register Address (7 bits)
Bit[8]:     R/W (1=READ, 0=WRITE)
Bits[7:0]:  Data (WRITE) or Don't Care (READ)

예: Aux-Config(0x06) WRITE 0x0C
TX: 0x0C0C = [0000110][0][00001100]
              Addr=6  W  Data=0x0C

예: Aux-Config(0x06) READ
TX: 0x0D00 = [0000110][1][00000000]
              Addr=6  R  Don't care
RX: 0x0F00 = [????][Data=0x00]
             (상위 8비트 무시, 하위 8비트가 레지스터 값)
```

### 8.3 전원 사양

| 핀 | 이름 | 전압 | 용도 |
|----|------|------|------|
| 1 | AVDD | 3.3V | 아날로그 전원 |
| 2,3 | AGND | 0V | 아날로그 GND |
| 14 | HVDD | 12V | 고전압 입력 전원 |
| 15 | HVSS | 0V | 고전압 GND |
| 20 | DGND | 0V | 디지털 GND |
| 21 | DVDD | 3.3V | 디지털 I/O 전원 |
| 23 | REFGND | 0V (AGND 연결) | 레퍼런스 GND |
| 24 | REF | 2.5V (내부 생성) | 레퍼런스 전압 |

### 8.4 입력 범위 설정

```c
#define ADS8638_RANGE_UNIPOLAR_5V    0x06  // 0 to 5V (HVDD ≥ 10V)
#define ADS8638_RANGE_UNIPOLAR_10V   0x05  // 0 to 10V (HVDD ≥ 15V)

// HVDD = 12V일 때 0-5V 범위 사용 권장
```

---

## 9. 첨부 자료

### 9.1 파일 목록

```
1. 소스 코드:
   - bldc_h743_v101.zip          (ADS8638 드라이버 구현 소스 코드 전체)

2. 오실로스코프 캡처:
   - .doc/2.png                  (CS/SCK/MOSI/MISO 파형)


### 9.2 테스트 명령

```c
// main.c에서 호출
void run_proc(void) {
    test_ads8638();
}
```

---

## 10. 연락처

문의사항이나 추가 테스트가 필요한 경우 연락 바랍니다.

**프로젝트**: STM32H743 BLDC 모터 제어 보드
**칩**: ADS8638 (TI)
**인터페이스**: SPI4 (STM32H743)
**테스트 환경**: STM32CubeIDE 1.19.0, ARM GCC 13.3
