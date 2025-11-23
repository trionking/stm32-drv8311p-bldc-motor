# DRV8311 BLDC 모터 제어 구현 가이드

**작성일**: 2025-01-22
**코드 정리**: 2025-01-23
**대상 시스템**: STM32H743 + DRV8311P BLDC 모터 드라이버
**모터 정격**: 600mA 최대 출력
**상태**: ✅ 1상 여자 방식 모터 회전 성공, 코드 정리 완료

---

## 📋 목차

1. [프로젝트 개요](#프로젝트-개요)
2. [하드웨어 구성](#하드웨어-구성)
3. [개발 과정 타임라인](#개발-과정-타임라인)
4. [핵심 기술 문서](#핵심-기술-문서)
5. [구현된 기능](#구현된-기능)
6. [테스트 결과](#테스트-결과)
7. [핵심 교훈](#핵심-교훈)
8. [향후 개선 계획](#향후-개선-계획)

---

## 프로젝트 개요

### 목표
STM32H743 마이크로컨트롤러와 DRV8311P 모터 드라이버를 사용하여 600mA 정격 BLDC 모터를 안전하게 제어

### 주요 도전 과제
- DRV8311의 하드웨어 OCP(5A/9A)가 저전류 모터(600mA)에 부적합
- 소프트웨어 기반 보호 시스템 필요
- 칩 손상 사고 경험 후 안전 메커니즘 구축
- 개발 과정에서 누적된 불필요한 코드 정리

### 최종 성과
✅ 1상 여자 방식으로 모터 회전 성공
✅ 안전한 duty 제한 구현 (3%~15%)
✅ 실시간 fault 감지 시스템 구축
✅ 칩 상태 진단 도구 개발
✅ 코드 정리 완료 (핵심 기능 7개만 유지, 약 10KB 감소)

---

## 하드웨어 구성

### 메인 컴포넌트

#### STM32H743VIHX
- **MCU**: ARM Cortex-M7, 480MHz
- **역할**: 모터 제어 알고리즘 실행, PWM 생성, 상태 모니터링

#### DRV8311P (Texas Instruments)
- **타입**: 3상 BLDC 게이트 드라이버 IC
- **특징**:
  - 통합 벅 레귤레이터
  - tSPI 인터페이스 (SPI 기반 제어)
  - 내부 PWM 생성 기능 (PWM Generation Mode)
  - 하드웨어 보호: OCP, OVP, UVLO, 과온도 보호
- **전원**:
  - VCC: 3.3V (로직)
  - VDRAIN: 8V~48V (모터 구동)

#### BLDC 모터
- **정격 전류**: 최대 600mA
- **타입**: 3상 무브러시 DC 모터

### 핀 연결

#### SPI1 통신 (DRV8311 제어)
```
STM32          DRV8311P
------         --------
PA5   (SCK) → SCLK
PA6   (MISO)← SDO
PD7   (MOSI)→ SDI
PD10  (CS)  → nSCS
```

#### 제어 신호
```
STM32          DRV8311P
------         --------
PE4         → nSLEEP (칩 활성화)
TIM15_CH1   → PWM_SYNC (동기화, 선택사항)
```

#### 모터 출력
```
DRV8311P → Motor
--------    -----
OUT_A    → Phase U
OUT_B    → Phase V
OUT_C    → Phase W
```

---

## 개발 과정 타임라인

### Phase 1: 초기 테스트 및 문제 발생

#### 시도한 방식
- **2상 여자 방식** 테스트
- Phase A = 60%, Phase B = 60% 동시 인가

#### 발생한 문제
```
증상:
- 2A 과전류 발생 (정격의 3.3배)
- MCU 리셋 후에도 2A 전류 지속
- 모든 레지스터 읽기 시 0x0000 반환
- Fault 플래그 미작동
- 칩 복구 불가능 → 하드웨어 손상 확인
```

#### 손상 메커니즘
```
1. 60% duty를 2상에 동시 인가
2. 전류 급증 (2A)
3. 하드웨어 OCP 미작동 (임계값 9A >> 2A)
4. MOSFET 과열 (수십 μs 내)
5. MOSFET 소손 → stuck-on 상태
6. 2A 전류 지속 흐름
7. SPI 통신 불가 (칩 내부 손상)
```

**결론**: 하드웨어 OCP만으로는 저전류 모터 보호 불가능!

---

### Phase 2: 근본 원인 분석

#### DRV8311 하드웨어 OCP의 한계

**DRVF_CTRL 레지스터 (0x13) - OCP_LVL 비트**:
```
┌──────────┬──────────┬─────────────────┐
│ OCP_LVL  │ 임계값   │ 600mA 모터 대비 │
├──────────┼──────────┼─────────────────┤
│ 0 (기본) │ 9A       │ 정격의 15배!    │
│ 1        │ 5A       │ 정격의 8배!     │
└──────────┴──────────┴─────────────────┘
```

**핵심 발견**:
- DRV8311은 고전력 모터용으로 설계됨
- 저전류 모터(600mA)에는 **소프트웨어 보호 필수**
- 하드웨어 스펙만 믿고 사용하면 칩 손상 위험

#### 생성된 문서
- `.doc/DRV8311_Chip_Damage_Recovery_Report.md` - 사고 보고서
- `.doc/DRV8311_Low_Current_Protection_Strategy.md` - 보호 전략

---

### Phase 3: 칩 교체 및 검증

#### 조치 사항
1. ✅ 손상된 DRV8311P 칩 교체
2. ✅ 새 칩 정상 동작 확인 필요

#### 칩 상태 확인 테스트 개발

**함수**: `test_drv8311_chip_health_check()`

**검사 항목**:
```c
1. nSLEEP 리셋 동작 확인
2. SPI 통신 상태 (Status byte = 0xFE?)
3. 레지스터 읽기/쓰기 테스트
4. Device ID 확인
5. Fault 상태 확인
6. 레지스터 잠금/해제 테스트
7. PWM 제어 레지스터 접근 확인
```

**판정 기준**:
```c
✅ 정상:
   - SPI Status = 0xFE (통신 정상)
   - HAL_OK 반환
   - 레지스터 읽기/쓰기 성공

❌ 비정상:
   - SPI Status = 0xFF
   - 모든 데이터 = 0xFFFF (MISO stuck high)
   - SPI Error
```

**중요한 수정**:
- 초기에 DEV_STS1 = 0x0000을 에러로 오판
- **수정**: 0x0000 + Status=0xFE는 정상! (폴트 없음)
- 실제 에러는 0xFFFF 또는 SPI HAL Error

---

### Phase 4: 안전한 제어 코드 개발

#### 소프트웨어 보호 전략

**다층 보호 시스템**:
```
Layer 1: 하드웨어 OCP (5A)     - 최종 방어선
Layer 2: 소프트웨어 Duty 제한  - 주 보호 (3~15%)
Layer 3: 실시간 Fault 체크     - 즉각 대응
Layer 4: 육안 모니터링         - 인간 판단
```

#### 구현된 안전 파라미터

```c
// user_def.c - test_motor_tspi_pwmgen_spi1()
#define DUTY_START_PERCENT      3     // 3%부터 시작 (매우 안전)
#define DUTY_MAX_PERCENT        15    // 절대 15% 이상 금지
#define DUTY_INCREMENT_PERCENT  2     // 2%씩 점진 증가
```

**점진적 Duty 램핑**:
```
3% (duty=6) → 대기 1초 → Fault 체크
5% (duty=10) → 대기 1초 → Fault 체크
7% (duty=14) → 대기 1초 → Fault 체크
...
15% (duty=30) → 대기 1초 → Fault 체크
→ 종료
```

**각 단계마다**:
- 단상만 구동 (전류 집중 방지)
- DEV_STS1 레지스터 읽어서 Fault 체크
- 이상 발견 시 즉시 중단
- 사용자가 육안으로 모터/보드 상태 확인

---

### Phase 5: 1상 여자 방식 모터 제어 구현

#### 동기
- 점진적 duty 테스트는 성공했으나 모터가 회전하지 않음
- 실제 모터 회전 테스트 필요
- **1상 여자 방식**: 가장 간단하고 안전한 BLDC 제어 방법

#### 구현 사항

**함수**: `test_motor_1phase_excitation()`

**제어 원리**:
```
Step 1: Phase A = 10%, B = 0%,  C = 0%   (500ms)
Step 2: Phase A = 0%,  B = 10%, C = 0%   (500ms)
Step 3: Phase A = 0%,  B = 0%,  C = 10%  (500ms)
→ 1회전 완료 (3 steps)
→ 이 과정을 10번 반복
```

**안전 파라미터**:
```c
#define MOTOR_DUTY_PERCENT      10    // 10% duty (안전)
#define STEP_DELAY_MS          500    // 500ms per step
#define NUM_ROTATIONS           10    // 10회 완전 회전
```

**특징**:
- 한 번에 **1개 상만** 활성화 → 최소 전류
- 각 단계마다 **Fault 체크**
- 천천히 회전 (1.5초/회전) → 육안 확인 가능
- 토크가 약하지만 **매우 안전**

---

### Phase 6: 코드 정리 및 최적화

#### 동기
- 개발 과정에서 누적된 초기 테스트 함수들이 다수 존재
- 중복된 함수 정의로 인한 빌드 에러 발생
- 유지보수성 향상 및 코드 크기 감소 필요

#### 정리 내용

**제거된 함수** (초기 개발/디버깅용):
- `test_drv8311()` - 초기 기본 테스트
- `test_drv8311_pwm_only()` - PWM 기본 테스트
- `test_dual_drv8311()` - 듀얼 드라이버 테스트
- `test_motor_run_spi1()` - 초기 모터 구동 테스트
- `test_motor_run_spi2()` - SPI2 모터 테스트
- `test_drv8311_spi_modes()` - SPI 모드 진단
- `test_drv8311_nsleep_scan()` - nSLEEP 핀 스캔
- `test_drv8311_device_id_scan()` - Device ID 스캔
- 기타 핀 테스트 함수들

**유지된 핵심 함수** (7개):
1. `test_ads8638()` - 외부 ADC 테스트
2. `test_internal_adc()` - 내부 ADC 테스트
3. `test_drv8311_chip_health_check()` - 칩 상태 진단
4. `test_motor_tspi_pwmgen_spi1()` - Duty 램핑 테스트
5. `test_drv8311_output_voltage()` - 출력 전압 측정
6. `test_motor_1phase_excitation()` - 1상 여자 모터 회전
7. `run_proc()` / `init_proc()` - 메인 진입점

**개선 효과**:
```
파일 크기:
- user_def.h: 20 lines (이전: ~43 lines)
- user_def.c: 564 lines (이전: ~1500 lines)

빌드 크기:
- 코드: 84,680 bytes (이전: ~95KB)
- 약 10KB 감소 (10.8% 감소)

기타:
- 중복 함수 제거로 빌드 에러 해결
- 깔끔한 코드 구조
- 유지보수성 향상
```

---

## 핵심 기술 문서

### DRV8311 초기화 시퀀스

```c
// 1. nSLEEP 활성화
DRV8311_nSLEEP_High();
HAL_Delay(5);

// 2. 레지스터 잠금 해제
DRV8311_WriteRegister16(&hdrv, DRV8311_REG_SYS_CTRL, 0x0005);  // Write key

// 3. tSPI PWM Generation Mode 활성화
uint16_t pwm_ctrl1 = DRV8311_PWM_MODE_PWMGEN |    // PWM 생성 모드
                     DRV8311_SSC_DISABLE;          // Spread spectrum OFF
DRV8311_WriteRegister16(&hdrv, DRV8311_REG_PWM_CTRL1, pwm_ctrl1);

// 4. PWM State 설정 (모든 출력 활성화)
uint16_t pwm_state = 0x77;  // A/B/C 모두 High+Low 활성화
DRV8311_WriteRegister16(&hdrv, DRV8311_REG_PWM_STATE, pwm_state);

// 5. PWM Period 설정
DRV8311_SetPWMPeriod(&hdrv, 200);  // ~20kHz

// 6. PWM 시작
DRV8311_StartPWMGen(&hdrv);

// 7. Duty 설정
DRV8311_SetPWMDuty(&hdrv, duty_a, duty_b, duty_c);
```

### 주요 레지스터 맵

#### SYS_CTRL (0x3F) - 시스템 제어
```c
#define DRV8311_SYS_CTRL_UNLOCK_KEY   0x0005  // 쓰기 허용
#define DRV8311_SYS_CTRL_LOCK_KEY     0x0006  // 쓰기 차단
```

#### PWM_CTRL1 (0x20) - PWM 모드 설정
```c
#define DRV8311_PWM_MODE_6PWM         (0x0 << 0)  // 외부 6-PWM
#define DRV8311_PWM_MODE_3PWM         (0x1 << 0)  // 외부 3-PWM
#define DRV8311_PWM_MODE_PWMGEN       (0x7 << 0)  // 내부 PWM 생성
```

#### PWM_STATE (0x1C) - 출력 상태
```c
// Bit [7:6]: Phase C (11 = High+Low 활성)
// Bit [5:4]: Phase B (11 = High+Low 활성)
// Bit [3:2]: Phase A (11 = High+Low 활성)
// Bit [1:0]: Reserved

#define PWM_STATE_ALL_ACTIVE   0x77  // 모든 상 활성화
```

#### DEV_STS1 (0x00) - 디바이스 상태
```c
#define DRV8311_STS1_FAULT            (1 << 10)  // 폴트 발생
#define DRV8311_STS1_OCP              (1 << 6)   // 과전류 보호
#define DRV8311_STS1_OVP              (1 << 5)   // 과전압 보호
#define DRV8311_STS1_OTSD             (1 << 4)   // 과온도 차단
```

---

## 구현된 기능

### 1. 칩 상태 확인 (`test_drv8311_chip_health_check`)

**목적**: 모터 연결 없이 칩 통신 및 레지스터 접근 검증

**테스트 항목**:
1. nSLEEP 리셋 동작
2. SPI 통신 확인
3. Device ID 읽기
4. Fault 상태 확인
5. 레지스터 잠금 해제
6. PWM 제어 레지스터 접근
7. 쓰기 보호 확인

**사용 시기**:
- 새 칩 교체 후 첫 테스트
- 통신 이상 의심 시
- 정기 점검

**실행 방법**:
```c
void run_proc(void) {
    test_drv8311_chip_health_check();
    while(1);
}
```

**예상 출력**:
```
========================================
  DRV8311P Chip Health Check
  (No motor connection required)
========================================

>>> Test 1: nSLEEP Reset <<<
  nSLEEP pulsed LOW for 10ms
  [PASS] nSLEEP reset OK

>>> Test 2: SPI Communication <<<
  SPI Status: 0xFE
  [PASS] SPI communication OK

>>> Test 3: Device ID <<<
  DEV_STS1: 0x0000
  [PASS] Chip is responding!

... (7개 테스트 수행)

========================================
  RESULT: CHIP IS HEALTHY! ✓
  You can proceed with motor tests.
========================================
```

---

### 2. 점진적 Duty 테스트 (`test_motor_tspi_pwmgen_spi1`)

**목적**: Phase A 출력을 점진적으로 증가시키며 안전성 확인

**동작**:
- Phase A만 활성화
- 3% → 5% → 7% → ... → 15% 점진 증가
- 각 단계마다 1초 대기 및 Fault 체크

**특징**:
- 모터가 회전하지 않음 (단상 출력)
- PWM 출력 전압 확인용
- Fault 감지 시스템 검증

**실행 방법**:
```c
void run_proc(void) {
    test_motor_tspi_pwmgen_spi1();
    while(1);
}
```

---

### 3. 1상 여자 모터 회전 (`test_motor_1phase_excitation`)

**목적**: 실제 모터를 회전시켜 전체 시스템 동작 확인

**제어 방식**: 1-Phase Excitation
```
Sequence: A → B → C → A (forward)
각 상: 10% duty, 500ms 유지
10회 완전 회전 수행
```

**안전 장치**:
- 매우 낮은 duty (10%)
- 각 상마다 Fault 체크
- 긴 스텝 시간 (500ms) - 육안 확인 가능
- 3초 카운트다운 (준비 시간)

**예상 동작**:
- 모터가 천천히 회전 (1.5초/회전)
- 부드럽지는 않지만 회전 확인 가능
- 토크가 약함 (무부하 테스트 권장)

**실행 방법**:
```c
void run_proc(void) {
    test_motor_1phase_excitation();
    while(1);
}
```

**예상 출력**:
```
========================================
  1-Phase Excitation Motor Test
  600mA Motor - Ultra Safe Mode
========================================

=== 1-Phase Excitation Parameters ===
Duty: 10% (value=20)
Step delay: 500 ms
Rotations: 10
Sequence: A → B → C → A (forward)

WARNING: Monitor motor for:
  - Excessive heat
  - Unusual noise
  - Vibration
Starting in 3 seconds...

>>> Starting Motor Rotation <<<

[Rotation 1/10]
  Step 1: Phase A ON  (B=0, C=0)
  Step 2: Phase B ON  (A=0, C=0)
  Step 3: Phase C ON  (A=0, B=0)

[Rotation 2/10]
  Step 1: Phase A ON  (B=0, C=0)
  ...

>>> Test Complete - No Faults! <<<
>>> Stopping Motor <<<
Motor stopped
========================================
```

---

### 4. 출력 전압 테스트 (`test_drv8311_output_voltage`)

**목적**: 모터 없이 U/V/W 출력 전압 확인

**동작**:
- Phase A에 5%, 10%, 15%, 20% duty 순차 인가
- 각 duty에서 5초 유지 (멀티미터 측정 시간)

**측정 방법**:
```
멀티미터 설정:
- Black probe: GND
- Red probe: OUT_A (또는 OUT_B, OUT_C)
- DC 전압 모드

예상 전압 (VDRAIN = 12V 기준):
- 5% duty  → ~0.6V
- 10% duty → ~1.2V
- 15% duty → ~1.8V
- 20% duty → ~2.4V
```

---

## 테스트 결과

### ✅ Health Check 결과
```
Status: PASS
- SPI 통신: 정상 (0xFE)
- Device ID: 읽기 성공
- 레지스터 접근: 정상
- 결론: 새 칩 정상 동작 확인
```

### ✅ 점진적 Duty 테스트 결과
```
Status: PASS
- 3% ~ 15% duty 램핑 성공
- 모든 단계에서 Fault 없음
- Phase A 출력 전압 확인
- 결론: PWM 생성 정상
```

### ✅ 1상 여자 모터 회전 결과
```
Status: SUCCESS! 🎉
- 모터 회전 확인
- 10회 완전 회전 완료
- Fault 발생 없음
- 코일 과열 없음
- 결론: 모터 제어 시스템 정상 동작
```

---

## 핵심 교훈

### 1. 하드웨어 보호의 한계
```
❌ 잘못된 가정: "하드웨어 OCP가 있으니 안전하겠지"
✅ 현실: DRV8311의 OCP(5A/9A)는 고전력 모터용
✅ 교훈: 저전류 모터에는 소프트웨어 보호 필수!
```

### 2. 점진적 접근의 중요성
```
❌ 위험한 방법: 처음부터 높은 duty 인가
✅ 안전한 방법: 3% → 5% → 7% ... 점진 증가
✅ 이점: 각 단계에서 관찰하며 이상 조기 발견
```

### 3. 다층 보호 시스템
```
Layer 1: 하드웨어 OCP (5A)          - 최종 방어선
Layer 2: 소프트웨어 Duty 제한 (15%) - 주 보호
Layer 3: 실시간 Fault 체크          - 즉각 대응
Layer 4: 육안 모니터링              - 인간 판단

→ 한 층이 실패해도 다른 층이 보호!
```

### 4. 테스트 전 검증
```
✅ 모터 연결 전 Health Check 필수
✅ SPI 통신 정상 확인
✅ 레지스터 읽기/쓰기 테스트
✅ 저전류부터 시작

→ 문제를 조기에 발견하여 칩 손상 방지
```

### 5. 문서화의 중요성
```
✅ 사고 보고서 작성 (원인 분석)
✅ 보호 전략 문서화
✅ 테스트 결과 기록
✅ 코드 주석

→ 같은 실수 반복 방지, 지식 축적
```

---

## 향후 개선 계획

### 단기 (CSA 없이 가능)

#### 1. 2상 여자 방식 구현
```c
// Step 1: A=10%, B=10%, C=0%
// Step 2: B=10%, C=10%, A=0%
// Step 3: C=10%, A=10%, B=0%
// → 1상 여자보다 토크 증가
```

**예상 개선**:
- 더 부드러운 회전
- 토크 증가 (~1.5배)
- 여전히 안전 (duty 10% 유지)

#### 2. 속도 제어 구현
```c
// STEP_DELAY_MS를 동적으로 조정
void set_motor_speed(uint16_t rpm) {
    uint16_t delay = calculate_step_delay(rpm);
    // 현재: 500ms = ~40 RPM
    // 목표: 100ms = ~200 RPM
}
```

#### 3. 방향 제어 구현
```c
// Forward:  A → B → C
// Reverse:  A → C → B
void set_motor_direction(bool forward);
```

#### 4. Duty 최적화
```c
// 현재: 10% 고정
// 개선: 부하에 따라 5%~20% 동적 조정
void optimize_duty_for_load(void);
```

---

### 중기 (CSA 연결 필요)

#### 1. 실시간 전류 모니터링
```
하드웨어 연결:
- DRV8311 SOA → STM32 ADC1_INP0  (Phase A)
- DRV8311 SOB → STM32 ADC1_INP1  (Phase B)
- DRV8311 SOC → STM32 ADC1_INP12 (Phase C)

CSA 설정:
- Gain: 2 V/A (최대 감도)
- 전류 계산: I = (ADC × 3.3V / 4096) / 2
```

#### 2. 소프트웨어 OCP 구현
```c
#define CURRENT_WARNING_MA   800   // 경고
#define CURRENT_FAULT_MA    1000   // 차단

void current_monitor_loop(void) {
    float current = read_phase_current();
    if (current > CURRENT_FAULT_MA) {
        emergency_stop();
    }
}
```

**예상 효과**:
- 600mA 초과 즉시 감지
- 응답 속도: ~10ms
- 칩 손상 위험 대폭 감소

#### 3. 전류 프로파일 로깅
```c
// 각 duty/속도에서 전류 기록
typedef struct {
    uint8_t duty_percent;
    uint16_t speed_rpm;
    float current_avg_ma;
    float current_peak_ma;
} CurrentProfile;

CurrentProfile profile_table[20];
```

---

### 장기 (고급 제어 알고리즘)

#### 1. 센서리스 BLDC 제어
- **BEMF (역기전력) 감지**로 로터 위치 추정
- 홀 센서 없이 정밀 제어
- 더 부드러운 회전

#### 2. FOC (Field Oriented Control)
- **벡터 제어** 방식
- 최대 효율, 최소 토크 리플
- 산업용 수준 성능

#### 3. 폐루프 속도 제어
```c
// PID 제어기로 정밀 속도 제어
void pid_speed_control(uint16_t target_rpm) {
    float error = target_rpm - current_rpm;
    float duty_adjust = pid_calculate(error);
    set_duty(duty_adjust);
}
```

#### 4. 통신 인터페이스
- **CAN-FD** 또는 **UART** 명령어 파싱
- 원격 모터 제어
- 실시간 모니터링 데이터 전송

---

## 코드 파일 구조

### 최종 파일 구조 (2025-01-23 정리 완료)

#### `Core/Inc/user_def.h` (20 lines)
**최종 함수 목록** (핵심 기능만 유지):
```c
// Main application entry
void run_proc(void);
void init_proc(void);

// Hardware Test Functions (Non-DRV8311)
void test_ads8638(void);              // ADS8638 외부 ADC 테스트
void test_internal_adc(void);         // STM32 내부 ADC 테스트

// DRV8311 Motor Control Functions
void test_drv8311_chip_health_check(void);     // 칩 상태 진단 (모터 불필요)
void test_motor_tspi_pwmgen_spi1(void);        // Duty 램핑 테스트 (Phase A만)
void test_drv8311_output_voltage(void);        // 출력 전압 측정 (모터 불필요)
void test_motor_1phase_excitation(void);       // 1상 여자 모터 회전
```

#### `Core/Src/user_def.c` (564 lines)
**유지된 함수** (총 7개):
```c
// 라인 위치 (정리 후):
// - test_ads8638():                      ~28줄
// - test_internal_adc():                 ~250줄
// - test_motor_tspi_pwmgen_spi1():       ~282줄
// - test_drv8311_chip_health_check():    ~548줄
// - test_drv8311_output_voltage():       ~1051줄
// - test_motor_1phase_excitation():      ~1236줄
// - run_proc():                          ~1210줄
```

**제거된 함수** (초기 개발/디버깅용):
```c
// ❌ test_drv8311() - 초기 테스트
// ❌ test_drv8311_pwm_only() - PWM 기본 테스트
// ❌ test_dual_drv8311() - 듀얼 드라이버 테스트
// ❌ test_motor_run_spi1() - 초기 모터 테스트
// ❌ test_motor_run_spi2() - SPI2 테스트
// ❌ test_drv8311_spi_modes() - SPI 모드 스캔
// ❌ test_drv8311_nsleep_scan() - nSLEEP 핀 스캔
// ❌ test_drv8311_device_id_scan() - Device ID 스캔
// ❌ test_spi1_pins(), test_spi2_basic() 등 기타 핀 테스트
```

**주요 개선 사항**:
- ✅ 코드 정리: 불필요한 함수 제거로 코드 크기 약 10KB 감소
- ✅ Duty 루프 버그 수정 (duty_percent 기반 제어)
- ✅ 안전 파라미터 추가 (3%~15% 제한)
- ✅ 실시간 Fault 체크
- ✅ 중복 함수 제거
- ✅ 상세한 주석 및 문서화

#### `Core/Inc/drv8311.h`
```c
// 추가된 레지스터 정의:
// - FLT_MODE (0x10): Fault 모드 설정
// - DRVF_CTRL (0x13): OCP 임계값 설정
// - SYSF_CTRL (0x12): 시스템 Fault 제어
```

### 빌드 결과 (정리 후)
```
코드 크기: 84,680 bytes (정리 전: ~95KB)
데이터: 1,760 bytes
BSS: 5,184 bytes
총 크기: 91,624 bytes
경고/에러: 없음
```

---

## 참고 문서

### 프로젝트 문서 (.doc 폴더)
1. `DRV8311_Chip_Damage_Recovery_Report.md` - 칩 손상 사고 보고서
2. `DRV8311_Low_Current_Protection_Strategy.md` - 저전류 모터 보호 전략
3. `DRV8311_Register_Summary.md` - 레지스터 맵 상세
4. `DRV8311_BLDC_Motor_Control_Implementation_Guide.md` - 본 문서

### 외부 자료
- DRV8311P 데이터시트: Texas Instruments SLVSFN2B
- STM32H743 레퍼런스 매뉴얼: STMicroelectronics RM0433
- AN-1276: Sensored BLDC Motor Control (Texas Instruments)

---

## 빌드 및 실행

### 빌드 방법

```bash
# Windows (Git Bash)
cd Debug
PATH="/c/ST/STM32CubeCLT_1.19.0/GNU-tools-for-STM32/bin:$PATH" \
  "/c/ST/STM32CubeIDE_1.19.0/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.make.win32_2.2.0.202409170845/tools/bin/make.exe" \
  -j all
```

**출력**: `Debug/bldc_h743_mot_v101.elf`

### 플래싱 방법

```bash
# ST-Link 사용
STM32_Programmer_CLI.exe -c port=SWD -w Debug/bldc_h743_mot_v101.elf -v -rst
```

### 테스트 선택

`Core/Src/user_def.c`의 `run_proc()` 함수에서 원하는 테스트 선택:

```c
void run_proc(void) {
    init_proc();

    // 옵션 1: 칩 상태 확인 (모터 불필요)
    //test_drv8311_chip_health_check();

    // 옵션 2: Duty 램핑 테스트 (Phase A만)
    //test_motor_tspi_pwmgen_spi1();

    // 옵션 3: 모터 회전 테스트 (1상 여자)
    test_motor_1phase_excitation();  // ← 현재 활성화

    while(1);
}
```

---

## 안전 주의사항

### ⚠️ 절대 금지 사항
1. ❌ Health check 없이 모터 구동
2. ❌ 처음부터 높은 duty 인가 (>15%)
3. ❌ 2상 이상 동시 구동 (전류 주의!)
4. ❌ Fault 무시하고 계속 구동
5. ❌ 육안 모니터링 없이 장시간 테스트

### ✅ 필수 확인 사항
1. ✅ VDRAIN 전압 (8V~48V 범위)
2. ✅ VCC 전압 (3.3V)
3. ✅ nSLEEP 핀 상태 (HIGH = 활성)
4. ✅ SPI 통신 정상 (Status = 0xFE)
5. ✅ 모터 정격 확인 (600mA)
6. ✅ 보드 온도 (손으로 만져서 뜨거우면 중단)

### 🔥 긴급 정지 절차
```
이상 징후 발견 시:
1. 즉시 VDRAIN 전원 차단!
2. nSLEEP를 LOW로 (DRV8311 비활성화)
3. MCU 리셋
4. 상태 확인 (Health check 재실행)
5. 문제 분석 후 재시도
```

---

## 결론

### 주요 성과
✅ **칩 손상 사고 극복**: 근본 원인 분석 및 대책 수립
✅ **안전 시스템 구축**: 다층 보호, 점진적 테스트
✅ **모터 회전 성공**: 1상 여자 방식으로 안전하게 구동
✅ **코드 정리 완료**: 핵심 기능만 유지, 코드 크기 10KB 감소
✅ **문서화 완료**: 지식 축적 및 재발 방지

### 최종 시스템 구성
**파일 구조** (정리 완료):
- `user_def.h`: 20 lines (핵심 함수 7개만 유지)
- `user_def.c`: 564 lines (불필요한 함수 제거)
- **빌드 크기**: 84,680 bytes (약 10KB 감소)

**핵심 기능** (7개):
1. `test_drv8311_chip_health_check()` - 칩 진단 (모터 불필요)
2. `test_motor_tspi_pwmgen_spi1()` - Duty 램핑 테스트
3. `test_drv8311_output_voltage()` - 출력 전압 측정
4. `test_motor_1phase_excitation()` - 1상 여자 모터 회전 ✅
5. `test_ads8638()` - 외부 ADC 테스트
6. `test_internal_adc()` - 내부 ADC 테스트
7. `run_proc()` / `init_proc()` - 메인 진입점

### 핵심 메시지
> **"하드웨어 스펙을 맹신하지 말고, 실제 사용 환경에 맞는 소프트웨어 보호를 구현하라"**

DRV8311은 훌륭한 모터 드라이버 IC이지만, **고전력 모터**를 위해 설계되었습니다.
**저전류 모터(600mA)**를 사용할 때는 반드시:
- ✅ Duty 제한 (3%~15%)
- ✅ 점진적 램핑
- ✅ 실시간 Fault 모니터링
- ✅ 깔끔한 코드 구조 (불필요한 부분 제거)
- ✅ (가능하면) CSA 기반 전류 측정

이러한 보호 장치와 체계적인 코드 관리를 통해 안전하고 안정적인 모터 제어 시스템을 구축할 수 있습니다.

---

**작성자**: Claude Code
**프로젝트**: STM32H743 + DRV8311P BLDC 모터 제어
**버전**: 1.1 (코드 정리 완료)
**최종 업데이트**: 2025-01-23
**상태**: ✅ 1상 여자 방식 모터 회전 성공, 코드 정리 완료
