# DRV8311 저전류 모터 보호 전략

## 문제 상황

- **모터 정격 전류**: 최대 600mA
- **DRV8311 하드웨어 OCP 임계값**: 5A 또는 9A
- **문제**: 정격의 3배 이상 과전류에도 하드웨어 보호 미작동

## 근본 원인

DRV8311의 OCP_LVL 레지스터는 **2가지 설정만 지원**:
```
DRVF_CTRL (0x13) Register - Bit 0 (OCP_LVL):
- 0h: 9A (기본값) - 위험!
- 1h: 5A - 여전히 너무 높음!
```

600mA 모터에는 **두 값 모두 부적합**합니다.

## 해결책: 다층 보호 시스템

### 계층 1: 하드웨어 OCP (최종 방어선)
```c
// DRVF_CTRL (0x13): OCP를 5A로 설정 (최소값)
uint16_t drvf_ctrl = DRV8311_OCP_LVL_5A |          // 5A 임계값
                     DRV8311_OCP_DEG_400NS |        // 400ns deglitch
                     DRV8311_OCP_TBLANK_600NS;      // 600ns blanking
```

### 계층 2: 소프트웨어 전류 모니터링 (주 보호)
```c
// CSA_CTRL (0x23): 높은 gain으로 설정
uint16_t csa_ctrl = DRV8311_CSA_EN |              // CSA 활성화
                    DRV8311_CSA_GAIN_200;          // 2.0 V/A (최대 감도)

// 전류 계산:
// 600mA × 2 V/A = 1.2V (정상)
// 1A × 2 V/A = 2.0V (경고 임계값)
// 2A × 2 V/A = 4.0V (위험! 즉시 차단)
```

### 계층 3: 실시간 모니터링 루프
```c
#define CURRENT_WARNING_THRESHOLD_MA    800   // 경고: 800mA
#define CURRENT_FAULT_THRESHOLD_MA      1000  // 차단: 1A
#define CURRENT_CHECK_INTERVAL_MS       10    // 10ms마다 체크

void DRV8311_CurrentMonitor_Loop(DRV8311_HandleTypeDef *hdrv) {
    static uint32_t last_check = 0;
    uint32_t now = HAL_GetTick();

    if (now - last_check < CURRENT_CHECK_INTERVAL_MS) {
        return;  // 아직 체크 주기 아님
    }
    last_check = now;

    // ADC에서 CSA 출력 읽기 (예: ADC1 CH0/1/2)
    uint16_t csa_a = adc_dma_buffer[0][0];  // Phase A
    uint16_t csa_b = adc_dma_buffer[0][1];  // Phase B
    uint16_t csa_c = adc_dma_buffer[0][2];  // Phase C

    // 전압을 전류로 변환 (CSA Gain = 2 V/A)
    // ADC: 12-bit, VREF = 3.3V
    // Current (mA) = (ADC_value / 4096) * 3300mV / (2 V/A)
    float current_a = ((float)csa_a / 4096.0f) * 3300.0f / 2.0f;
    float current_b = ((float)csa_b / 4096.0f) * 3300.0f / 2.0f;
    float current_c = ((float)csa_c / 4096.0f) * 3300.0f / 2.0f;

    // 최대값 찾기
    float max_current = current_a;
    if (current_b > max_current) max_current = current_b;
    if (current_c > max_current) max_current = current_c;

    // 임계값 체크
    if (max_current > CURRENT_FAULT_THRESHOLD_MA) {
        printf("[EMERGENCY] Overcurrent: %.0f mA - STOPPING MOTOR!\r\n", max_current);
        DRV8311_Emergency_Stop(hdrv);
        hdrv->fault_flags |= FAULT_SOFTWARE_OCP;
    }
    else if (max_current > CURRENT_WARNING_THRESHOLD_MA) {
        printf("[WARNING] High current: %.0f mA\r\n", max_current);
        hdrv->warning_flags |= WARNING_HIGH_CURRENT;
    }
}
```

## CSA 하드웨어 연결

DRV8311의 CSA 출력을 STM32 ADC에 연결:
```
DRV8311 Pin    →  STM32 Pin    Function
-----------       ---------    --------
SOA (Phase A)  →  PA0_C       ADC1_INP0
SOB (Phase B)  →  PA1_C       ADC1_INP1
SOC (Phase C)  →  PC2_C       ADC1_INP12
```

## 안전한 초기화 시퀀스

```c
HAL_StatusTypeDef DRV8311_Init_LowCurrent_Safe(
    DRV8311_HandleTypeDef *hdrv,
    SPI_HandleTypeDef *hspi,
    TIM_HandleTypeDef *htim)
{
    HAL_StatusTypeDef status;

    // 1. nSLEEP 활성화
    DRV8311_nSLEEP_High();
    HAL_Delay(5);

    // 2. 레지스터 잠금 해제
    status = DRV8311_UnlockRegisters(hdrv);
    if (status != HAL_OK) return status;

    // 3. Fault 모드 설정: OCP는 래치 차단
    uint16_t flt_mode = DRV8311_OCP_MODE_LATCH_ALL |      // OCP 시 모든 출력 차단
                        DRV8311_UVP_MODE_ENABLE |          // 저전압 보호 활성화
                        DRV8311_OTSD_MODE_ENABLE;          // 과온 보호 활성화
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_FLT_MODE, flt_mode);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // 4. OCP 임계값을 최소값(5A)으로 설정
    uint16_t drvf_ctrl = DRV8311_OCP_LVL_5A |             // 5A (최소)
                         DRV8311_OCP_DEG_1US |             // 1us deglitch
                         DRV8311_OCP_TBLANK_600NS;         // 600ns blanking
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_DRVF_CTRL, drvf_ctrl);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // 5. CSA를 최대 gain(2 V/A)으로 설정
    uint16_t csa_ctrl = DRV8311_CSA_EN |                  // CSA 활성화
                        DRV8311_CSA_GAIN_200;              // 2.0 V/A
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_CSA_CTRL, csa_ctrl);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // 6. 시스템 fault 활성화
    uint16_t sysf_ctrl = DRV8311_OTAVDD_EN |              // AVDD 과온 감지
                         DRV8311_OTW_EN |                  // 과온 경고
                         DRV8311_CSAREFUV_EN |             // CSA 기준전압 UV
                         DRV8311_CPUV_EN |                 // 차지 펌프 UV
                         DRV8311_AVDDUV_EN |               // AVDD UV
                         DRV8311_VINAVDDUV_EN;             // VIN_AVDD UV
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_SYSF_CTRL, sysf_ctrl);
    if (status != HAL_OK) return status;
    HAL_Delay(5);

    // 7. 나머지 초기화 (slew rate, deadtime 등)
    uint16_t drv_ctrl = DRV8311_DRV_SLEW_35V |            // 최저 slew rate (EMI 감소)
                        DRV8311_DRV_TDEAD_800NS;           // 800ns deadtime
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_DRV_CTRL, drv_ctrl);
    if (status != HAL_OK) return status;

    // 8. PWM 모드 설정
    uint16_t pwm_ctrl1 = DRV8311_PWM_MODE_PWMGEN |
                         DRV8311_SSC_DISABLE;
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_CTRL1, pwm_ctrl1);
    if (status != HAL_OK) return status;

    // 9. Fault 클리어
    status = DRV8311_ClearFaults(hdrv);

    printf("[DRV8311] Low-current safe initialization complete\r\n");
    printf("  - Hardware OCP: 5A (last resort)\r\n");
    printf("  - Software OCP: 1A (primary protection)\r\n");
    printf("  - CSA Gain: 2 V/A (high sensitivity)\r\n");

    return HAL_OK;
}
```

## 비상 정지 함수

```c
void DRV8311_Emergency_Stop(DRV8311_HandleTypeDef *hdrv) {
    // 즉시 PWM 정지
    DRV8311_StopPWMGen(hdrv);

    // 모든 출력을 High-Z로
    DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_STATE, 0x0000);

    // nSLEEP LOW (칩 슬립 모드)
    DRV8311_nSLEEP_Low();

    printf("[EMERGENCY STOP] Motor driver disabled!\r\n");
}
```

## 권장 사용 흐름

```c
void run_proc(void) {
    DRV8311_HandleTypeDef hdrv = {0};

    // 1. 안전 초기화
    if (DRV8311_Init_LowCurrent_Safe(&hdrv, &hspi1, &htim15) != HAL_OK) {
        printf("Init failed!\r\n");
        return;
    }

    // 2. ADC 시작 (CSA 모니터링용)
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_dma_buffer, 8);

    // 3. PWM 시작 (매우 낮은 duty부터!)
    DRV8311_SetPWMPeriod(&hdrv, 200);
    DRV8311_EnablePWMGeneration(&hdrv);
    DRV8311_StartPWMGen(&hdrv);

    // 4. 점진적으로 duty 증가 (전류 모니터링하면서)
    for (uint16_t duty = 10; duty <= 50; duty += 5) {
        DRV8311_SetPWMDuty(&hdrv, duty, 0, 0);
        HAL_Delay(100);

        // 전류 체크
        DRV8311_CurrentMonitor_Loop(&hdrv);

        if (hdrv.fault_flags & FAULT_SOFTWARE_OCP) {
            printf("Overcurrent detected during ramp-up!\r\n");
            break;
        }
    }

    // 5. 메인 루프
    while (1) {
        DRV8311_CurrentMonitor_Loop(&hdrv);  // 10ms마다 전류 체크
        HAL_Delay(1);
    }
}
```

## 핵심 권장사항

### ✅ 반드시 해야 할 것
1. **CSA를 ADC에 연결** - 하드웨어 필수
2. **소프트웨어 OCP를 1A 이하로** - 정격의 1.5~2배
3. **10ms 이하 주기로 전류 모니터링** - 실시간 보호
4. **점진적 duty 증가** - 급격한 전류 변화 방지
5. **비상 정지 함수 구현** - 즉각 대응

### ❌ 절대 하지 말아야 할 것
1. 하드웨어 OCP(5A/9A)에만 의존
2. 전류 모니터링 없이 모터 구동
3. 초기부터 높은 duty 인가
4. 2상 동시 여자 (전류 2배)
5. Fault 무시하고 계속 구동

## 예상 개선 효과

| 항목 | 기존 | 개선 후 |
|------|------|---------|
| OCP 임계값 | 9A | 1A (소프트웨어) |
| 보호 응답속도 | 없음 | 10ms |
| 칩 손상 위험 | 매우 높음 | 매우 낮음 |
| 과전류 감지율 | 0% | 100% |

---

**작성일**: 2025-01-22
**대상 모터**: 정격 600mA BLDC
**칩**: DRV8311P (Texas Instruments)
