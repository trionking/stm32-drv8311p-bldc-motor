# DRV8311P 칩 손상 및 복구 보고서

**작성일**: 2025-01-22
**대상 시스템**: STM32H743 + DRV8311P BLDC 모터 드라이버
**모터 정격**: 600mA 최대 출력

---

## 📋 요약

- **문제**: 2상 여자 방식 테스트 중 과전류(2A) 발생으로 DRV8311P 칩 손상
- **원인**: 하드웨어 OCP 임계값(9A/5A)이 600mA 모터에 부적합
- **조치**: 칩 교체 + 소프트웨어 duty 제한 구현
- **결과**: 칩 교체 완료, 안전 코드 적용으로 정상 제어 가능

---

## 🔴 발생한 문제

### 증상
```
- 2상 여자 방식 테스트 중 최대 전류(2A) 발생
- MCU 리셋 후에도 2A 전류 지속 흐름
- DRV8311 레지스터 읽기 시 모두 0x0000 반환
- Fault 플래그 미작동
- 칩 복구 불가능 → 하드웨어 손상 확인
```

### 발생 시점의 코드
```c
// 위험했던 코드:
Period = 200
Duty_A = 120 (60%)  // 2개 상에
Duty_B = 120 (60%)  // 동시 인가!
Duty_C = 0

→ 과도한 전류 발생 (2A)
→ OCP 미작동 (임계값 9A)
→ MOSFET 과열/손상
→ 칩 고장 (stuck-on 상태)
```

---

## 🔍 근본 원인 분석

### 하드웨어 OCP의 한계

DRV8311의 DRVF_CTRL 레지스터 (0x13):
```
┌──────────┬──────────┬─────────────────┐
│ OCP_LVL  │ 임계값   │ 600mA 모터 대비 │
├──────────┼──────────┼─────────────────┤
│ 0 (기본) │ 9A       │ 정격의 15배!    │
│ 1        │ 5A       │ 정격의 8배!     │
└──────────┴──────────┴─────────────────┘
```

**결론**: 하드웨어 OCP는 저전류 모터(600mA)를 보호할 수 없음!

### 손상 시나리오
```
1. 60% duty를 2상에 동시 인가
2. 전류 급증 (2A = 정격의 3.3배)
3. 하드웨어 OCP 미작동 (임계값 9A)
4. MOSFET 과열 (수십 μs 내)
5. MOSFET 소손 → stuck-on 상태
6. 2A 전류 지속 흐름
7. SPI 통신 불가 (칩 내부 손상)
```

---

## ✅ 적용한 해결 방안

### 1. 칩 교체
- 손상된 DRV8311P 칩 교체
- 새 칩의 정상 동작 확인

### 2. 칩 상태 확인 테스트 구현

**함수**: `test_drv8311_chip_health_check()`

**주요 검사 항목**:
- nSLEEP 리셋 동작
- SPI 통신 확인 (Status byte = 0xFE 확인)
- 레지스터 읽기/쓰기 테스트
- Fault 상태 확인

**판정 기준**:
```c
✅ 정상: Status = 0xFE, SPI HAL_OK
❌ 비정상: Status = 0xFF, Data = 0xFFFF, SPI Error
```

### 3. 안전한 모터 제어 코드 작성

**함수**: `test_motor_tspi_pwmgen_spi1()` (개선)

**핵심 안전 장치**:
```c
// 1. 매우 낮은 duty부터 시작
#define DUTY_START_PERCENT      3     // 3% (안전)
#define DUTY_MAX_PERCENT        15    // 15% 상한선
#define DUTY_INCREMENT_PERCENT  2     // 2%씩 점진 증가

// 2. 단상만 구동 (전류 분산 방지)
DRV8311_SetPWMDuty(&hdrv, current_duty, 0, 0);  // A상만

// 3. 각 단계마다 1초 대기 (육안 관찰 시간)
HAL_Delay(1000);

// 4. Fault 체크
DRV8311_ReadRegister16(&hdrv, DRV8311_REG_DEV_STS1, &dev_sts1);
if (dev_sts1 & DRV8311_STS1_FAULT) {
    printf("  [FAULT] Stopping at %d%%!\r\n", duty_percent);
    break;
}
```

### 4. 헤더 파일 개선

**파일**: `drv8311.h`

추가된 레지스터 정의:
```c
// FLT_MODE Register (0x10)
#define DRV8311_OCP_MODE_LATCH          (0x1 << 4)
#define DRV8311_OCP_MODE_AUTO_RETRY     (0x2 << 4)
#define DRV8311_UVP_MODE_ENABLE         (0x1 << 2)
#define DRV8311_OTSD_MODE_ENABLE        (0x1 << 0)

// DRVF_CTRL Register (0x13)
#define DRV8311_OCP_LVL_9A              (0x0 << 0)  // DANGEROUS!
#define DRV8311_OCP_LVL_5A              (0x1 << 0)  // Safer
#define DRV8311_OCP_DEG_1US             (0x3 << 4)
#define DRV8311_OCP_TBLANK_600NS        (0x2 << 2)

// SYSF_CTRL Register (0x12)
#define DRV8311_OTAVDD_EN               (1 << 10)
#define DRV8311_OTW_EN                  (1 << 9)
#define DRV8311_CSAREFUV_EN             (1 << 5)
```

---

## 📊 개선 효과

| 항목 | 이전 | 개선 후 |
|------|------|---------|
| 시작 Duty | 60% (위험) | 3% (안전) |
| 최대 Duty | 제한 없음 | 15% 상한선 |
| Duty 증가 | 급격 | 2%씩 점진 |
| 과전류 보호 | 없음 (9A OCP) | 소프트웨어 제한 |
| 테스트 방식 | 2상 동시 | 1상 순차 |
| 관찰 시간 | 없음 | 각 단계 1초 |
| Fault 체크 | 미흡 | 매 단계 체크 |

---

## 🎯 현재 상태

### ✅ 완료된 작업
1. 손상 원인 분석 완료
2. DRV8311P 칩 교체 완료
3. 칩 상태 확인 테스트 구현 및 PASS 확인
4. 안전한 모터 제어 코드 작성
5. 레지스터 정의 추가
6. 문서화 작성

### ⚠️ 남은 작업
1. CSA(Current Sense Amplifier) 출력을 ADC에 연결
2. 실시간 전류 모니터링 구현
3. 소프트웨어 OCP 구현 (임계값 1A)
4. 최적 duty 값 실험적 결정
5. 모터 회전 방향 및 속도 제어 검증

---

## 📝 권장 사용 절차

### 1. 칩 상태 확인
```c
void run_proc(void) {
    // 모터 연결 전 필수 체크!
    test_drv8311_chip_health_check();

    // 결과가 "CHIP IS HEALTHY!" 인지 확인
}
```

### 2. 모터 테스트 (PASS 확인 후에만)
```c
void run_proc(void) {
    test_drv8311_chip_health_check();

    // Health check PASS 확인 후:
    test_motor_tspi_pwmgen_spi1();  // 안전 코드
}
```

### 3. 실행 중 모니터링
```
각 duty 단계마다 확인:
□ 모터 코일 온도 (손으로 만져서 뜨거우면 중단)
□ 모터 회전 여부
□ 비정상 소음/진동
□ 보드 발열
□ UART 출력의 Fault 메시지

이상 징후 → 즉시 전원 차단!
```

---

## 💡 핵심 교훈

### 1. 하드웨어 보호의 한계
- DRV8311의 OCP는 고전력 모터용 (5A~9A)
- 저전류 모터(600mA)에는 **소프트웨어 보호 필수**
- 하드웨어 스펙만 믿고 사용하면 칩 손상 가능

### 2. 점진적 접근의 중요성
- 처음부터 높은 duty 인가 금지
- 3% → 5% → 7% ... 15% 점진 증가
- 각 단계마다 충분한 관찰 시간 필요

### 3. 다층 보호 시스템
```
Layer 1: 하드웨어 OCP (5A) - 최종 방어선
Layer 2: 소프트웨어 Duty 제한 (15%) - 주 보호
Layer 3: 실시간 Fault 체크 - 즉각 대응
Layer 4: 육안 모니터링 - 인간 판단
```

### 4. 테스트 전 검증
- 모터 연결 전 칩 상태 확인 필수
- SPI 통신 정상 확인
- 레지스터 읽기/쓰기 테스트

---

## 🔧 향후 개선 계획

### 단기 (CSA 없이)
- [x] Duty 기반 전류 제한 (완료)
- [ ] 최적 duty 범위 실험
- [ ] 모터 회전 방향 제어
- [ ] 속도 제어 알고리즘

### 중기 (CSA 연결 후)
- [ ] CSA 출력을 STM32 ADC에 연결
- [ ] 실시간 전류 측정 (10ms 주기)
- [ ] 소프트웨어 OCP 구현 (1A 임계값)
- [ ] 전류 프로파일 로깅

### 장기
- [ ] 센서리스 BLDC 제어 알고리즘
- [ ] FOC (Field Oriented Control) 구현
- [ ] 온도 센서 추가
- [ ] CAN 통신을 통한 원격 모니터링

---

## 📚 참고 문서

- `.doc/DRV8311_Register_Summary.md` - 레지스터 맵 상세
- `.doc/DRV8311_Low_Current_Protection_Strategy.md` - 저전류 모터 보호 전략
- DRV8311P 데이터시트 (Texas Instruments SLVSFN2B)

---

## 🔗 관련 파일

### 수정된 파일
- `Core/Src/user_def.c` - 안전 테스트 함수 추가
  - `test_drv8311_chip_health_check()` - 칩 상태 확인
  - `test_motor_tspi_pwmgen_spi1()` - 안전한 모터 제어 (개선)

- `Core/Inc/user_def.h` - 함수 프로토타입 추가

- `Core/Inc/drv8311.h` - 레지스터 정의 추가
  - FLT_MODE, DRVF_CTRL, SYSF_CTRL 레지스터

### 주요 함수

#### 1. 칩 상태 확인
```c
void test_drv8311_chip_health_check(void)
```
- 7가지 테스트 수행
- 모터 연결 불필요
- PASS/FAIL 판정

#### 2. 안전한 모터 테스트
```c
void test_motor_tspi_pwmgen_spi1(void)
```
- 3%~15% duty 점진 증가
- 단상만 구동
- 매 단계 fault 체크

---

## ⚠️ 주의사항

### 절대 금지 사항
1. ❌ Health check 없이 모터 구동
2. ❌ 처음부터 높은 duty 인가
3. ❌ 2상 이상 동시 구동 (전류 주의)
4. ❌ Fault 무시하고 계속 구동
5. ❌ 육안 모니터링 없이 장시간 테스트

### 필수 확인 사항
1. ✅ VDRAIN 전압 (8V~48V)
2. ✅ VCC 전압 (3.3V)
3. ✅ nSLEEP 핀 상태 (HIGH)
4. ✅ SPI 통신 정상 (Status = 0xFE)
5. ✅ 모터 정격 확인 (600mA)

---

**작성자**: Claude Code
**검토**: 사용자
**버전**: 1.0
**상태**: 칩 교체 완료, 안전 코드 적용, 정상 동작 확인
