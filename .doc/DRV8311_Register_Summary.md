# DRV8311 레지스터 요약 문서

## 문서 정보
- **칩 이름**: DRV8311
- **제조사**: Texas Instruments
- **설명**: Three-Phase PWM Motor Driver
- **작동 전압**: 3V ~ 20V
- **최대 전류**: 5A Peak

---

## 1. 개요

DRV8311은 3상 브러시리스 DC(BLDC) 모터를 구동하기 위한 통합 MOSFET 3개의 하프 H-브리지를 제공합니다. 5V, 9V, 12V, 18V DC 레일 또는 1S~4S 배터리 전원 애플리케이션에 적합합니다. 이 장치는 BLDC 모터의 3상 전류를 감지하기 위한 통합 전류 감지 기능이 있는 3개의 전류 감지 증폭기(CSA)를 통합하여 최적의 FOC 및 전류 제어 시스템 구현을 가능하게 합니다.

---

## 2. 레지스터 맵 (Register Map)

| 주소 (Offset) | 약어 (Acronym) | 레지스터 이름 | 리셋 값 | 액세스 |
|--------------|----------------|--------------|---------|--------|
| 0x00 | DEV_STS1 | Device Status 1 Register | 0x0080 | R |
| 0x04 | OT_STS | Over Temperature Status Register | 0x0000 | R |
| 0x05 | SUP_STS | Supply Status Register | 0x0000 | R |
| 0x06 | DRV_STS | Driver Status Register | 0x0000 | R |
| 0x07 | SYS_STS | System Status Register | 0x0000 | R |
| 0x0C | PWM_SYNC_PRD | PWM Sync Period Register | 0x0000 | R |
| 0x10 | FLT_MODE | Fault Mode Register | 0x0115 | R/W |
| 0x12 | SYSF_CTRL | System Fault Control Register | 0x0515 | R/W |
| 0x13 | DRVF_CTRL | Driver Fault Control Register | 0x0030 | R/W |
| 0x16 | FLT_TCTRL | Fault Timing Control Register | 0x0003 | R/W |
| 0x17 | FLT_CLR | Fault Clear Register | 0x0000 | W |
| 0x18 | PWMG_PERIOD | PWM_GEN Period Register | 0x0000 | R/W |
| 0x19 | PWMG_A_DUTY | PWM_GEN A Duty Register | 0x0000 | R/W |
| 0x1A | PWMG_B_DUTY | PWM_GEN B Duty Register | 0x0000 | R/W |
| 0x1B | PWMG_C_DUTY | PWM_GEN C Duty Register | 0x0000 | R/W |
| 0x1C | PWM_STATE | PWM State Register | 0x0777 | R/W |
| 0x1D | PWMG_CTRL | PWM_GEN Control Register | 0x0000 | R/W |
| 0x20 | PWM_CTRL1 | PWM Control Register 1 | 0x0007 | R/W |
| 0x22 | DRV_CTRL | Predriver Control Register | 0x0000 | R/W |
| 0x23 | CSA_CTRL | CSA Control Register | 0x0008 | R/W |
| 0x3F | SYS_CTRL | System Control Register | 0x0000 | R/W |

---

## 3. 레지스터 상세 설명

### 3.1 DEV_STS1 (0x00) - Device Status 1 Register
**리셋 값**: 0x0080

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | SPI_PEN이 '1'로 설정된 경우 패리티 비트 |
| 14-9 | RESERVED | R-0 | 0h | 예약됨 |
| 8 | OTP_FLT | R | 0h | OTP 읽기 오류: 0=정상, 1=오류 감지 |
| 7 | RESET | R | 1h | 전원 온 리셋 상태: 0=없음, 1=파워온 리셋 발생 |
| 6 | SPI_FLT | R | 0h | SPI 오류 상태: 0=정상, 1=SPI 통신 오류 |
| 5 | OCP | R | 0h | 드라이버 과전류 보호 상태 |
| 4-3 | RESERVED | R | 0h | 예약됨 |
| 2 | UVP | R | 0h | 저전압 상태: 0=정상, 1=저전압 감지 |
| 1 | OT | R | 0h | 과온 오류 상태: 0=정상, 1=과온 경고/차단 |
| 0 | FAULT | R | 0h | 장치 오류 상태: 0=정상, 1=오류 발생 |

**설명**: 장치의 전반적인 상태를 나타내는 레지스터로, 오류, 리셋, 과전류, 과온, 저전압 등의 상태를 확인할 수 있습니다.

---

### 3.2 OT_STS (0x04) - Over Temperature Status Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-3 | RESERVED | R-0 | 0h | 예약됨 |
| 2 | OTS_AVDD | R | 0h | AVDD LDO 과온 오류 상태 |
| 1 | OTW | R | 0h | 과온 경고 상태 |
| 0 | OTSD | R | 0h | 과온 차단 오류 상태 |

**설명**: 온도 관련 상태를 모니터링하는 레지스터입니다.

---

### 3.3 SUP_STS (0x05) - Supply Status Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-6 | RESERVED | R-0 | 0h | 예약됨 |
| 5 | CSAREF_UV | R | 0h | CSA REF 저전압 오류 상태 |
| 4 | CP_UV | R | 0h | 차지 펌프 저전압 오류 상태 |
| 3 | RESERVED | R-0 | 0h | 예약됨 |
| 2 | AVDD_UV | R | 0h | AVDD LDO 저전압 오류 상태 |
| 1 | RESERVED | R-0 | 0h | 예약됨 |
| 0 | VINAVDD_UV | R | 0h | VIN_AVDD 저전압 오류 상태 |

**설명**: 전원 공급 관련 오류를 보고하는 레지스터입니다.

---

### 3.4 DRV_STS (0x06) - Driver Status Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-7 | RESERVED | R-0 | 0h | 예약됨 |
| 6 | OCPC_HS | R | 0h | OUTC 하이 사이드 MOSFET 과전류 상태 |
| 5 | OCPB_HS | R | 0h | OUTB 하이 사이드 MOSFET 과전류 상태 |
| 4 | OCPA_HS | R | 0h | OUTA 하이 사이드 MOSFET 과전류 상태 |
| 3 | RESERVED | R-0 | 0h | 예약됨 |
| 2 | OCPC_LS | R | 0h | OUTC 로우 사이드 MOSFET 과전류 상태 |
| 1 | OCPB_LS | R | 0h | OUTB 로우 사이드 MOSFET 과전류 상태 |
| 0 | OCPA_LS | R | 0h | OUTA 로우 사이드 MOSFET 과전류 상태 |

**설명**: 각 상(A, B, C)의 하이 사이드 및 로우 사이드 MOSFET에 대한 개별 과전류 플래그를 제공합니다.

---

### 3.5 SYS_STS (0x07) - System Status Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-5 | RESERVED | R-0 | 0h | 예약됨 |
| 4 | OTPLD_ERR | R | 0h | OTP 읽기 오류 |
| 3 | RESERVED | R-0 | 0h | 예약됨 |
| 2 | SPI_PARITY | R | 0h | SPI 패리티 오류 |
| 1 | BUS_CNT | R | 0h | SPI 버스 경합 오류 |
| 0 | FRM_ERR | R | 0h | SPI 프레임 오류 |

**설명**: SPI 및 OTP 오류, 버스 경합, 프레임 오류를 보고합니다.

---

### 3.6 PWM_SYNC_PRD (0x0C) - PWM Sync Period Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-12 | RESERVED | R-0 | 0h | 예약됨 |
| 11-0 | PWM_SYNC_PRD | R | 0h | PWM_SYNC 신호의 주기를 나타내는 12비트 출력 |

**설명**: 외부 MCU에서 제공하는 PWM_SYNC 신호의 주기를 12비트 값으로 제공합니다.

---

### 3.7 FLT_MODE (0x10) - Fault Mode Register
**리셋 값**: 0x0115

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-9 | RESERVED | R-0 | 0h | 예약됨 |
| 8 | OTPFLT_MODE | R/W | 1h | 시스템 오류 모드 |
| 7 | SPIFLT_MODE | R/W | 0h | SPI 오류 모드 |
| 6-4 | OCP_MODE | R/W | 1h | 과전류 보호 오류 모드 (다양한 설정) |
| 3-2 | UVP_MODE | R/W | 1h | 저전압 보호 오류 모드 |
| 1-0 | OTSD_MODE | R/W | 1h | 과온 오류 모드 |

**설명**: 오류 처리 모드(래치 vs 재시도, 타이밍, 보호 활성화/비활성화)를 구성합니다.

**OCP_MODE 값**:
- 0h: 과전류 보호 비활성화
- 1h: 래치 차단
- 2h: 자동 재시도
- 3h: 래치 차단 (모든 출력 비활성화)
- 4h-7h: 다양한 재시도 옵션

---

### 3.8 SYSF_CTRL (0x12) - System Fault Control Register
**리셋 값**: 0x0515

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-11 | RESERVED | R-0 | 0h | 예약됨 |
| 10 | OTAVDD_EN | R/W | 1h | AVDD 과온 오류 활성화 |
| 9 | OTW_EN | R/W | 0h | 과온 경고 오류 활성화 |
| 8-6 | RESERVED | R-0 | 0h | 예약됨 |
| 5 | CSAREFUV_EN | R/W | 1h | CSAREF 저전압 오류 활성화 |
| 4-0 | ... | R/W | ... | 기타 오류 활성화 비트 |

**설명**: 과온 및 전류 감지 증폭기 기준 저전압에 대한 오류 활성화를 제어합니다.

---

### 3.9 DRVF_CTRL (0x13) - Driver Fault Control Register
**리셋 값**: 0x0030

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-6 | RESERVED | R-0 | 0h | 예약됨 |
| 5-4 | OCP_DEG | R/W | 3h | OCP 디글리치 시간 (0.2~1 µs 범위) |
| 3-2 | OCP_TBLANK | R/W | 0h | OCP 블랭킹 시간 (0.2~1 µs 범위) |
| 1 | RESERVED | R-0 | 0h | 예약됨 |
| 0 | OCP_LVL | R/W | 0h | OCP 레벨 설정 (0h=9A, 1h=5A) |

**설명**: 과전류 보호 타이밍 및 임계값을 설정합니다.

**OCP_DEG 값**:
- 0h: 0.2 µs
- 1h: 0.4 µs
- 2h: 0.6 µs
- 3h: 1 µs

**OCP_TBLANK 값**:
- 0h: 0.2 µs
- 1h: 0.4 µs
- 2h: 0.6 µs
- 3h: 1 µs

---

### 3.10 FLT_TCTRL (0x16) - Fault Timing Control Register
**리셋 값**: 0x0003

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-4 | RESERVED | R-0 | 0h | 예약됨 |
| 3-2 | SLOW_TRETRY | R/W | 0h | 느린 복구 재시도 시간 |
| 1-0 | FAST_TRETRY | R/W | 3h | 빠른 복구 재시도 시간 |

**설명**: 오류 후 빠른/느린 재시도에 대한 타이밍을 제어합니다.

**SLOW_TRETRY 값**:
- 0h: 0.5초
- 1h: 1초
- 2h: 2초
- 3h: 5초

**FAST_TRETRY 값**:
- 0h: 0.5ms
- 1h: 1ms
- 2h: 2ms
- 3h: 5ms

---

### 3.11 FLT_CLR (0x17) - Fault Clear Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-1 | RESERVED | R-0 | 0h | 예약됨 |
| 0 | FLT_CLR | W | 0h | 오류 지우기: 래치된 오류 비트를 지우려면 1h 작성 |

**설명**: 래치된 오류를 지웁니다. 1을 쓰면 오류가 클리어됩니다.

---

### 3.12 PWMG_PERIOD (0x18) - PWM_GEN Period Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-12 | RESERVED | R-0 | 0h | 예약됨 |
| 11-0 | PWM_PRD_OUT | R/W | 0h | 출력 PWM 신호에 대한 12비트 주기 |

**설명**: 내부 PWM 생성 모드에서 PWM 주기를 설정합니다.

---

### 3.13 PWMG_A_DUTY (0x19) - PWM_GEN A Duty Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-12 | RESERVED | R-0 | 0h | 예약됨 |
| 11-0 | PWM_DUTY_OUTA | R/W | 0h | 상 A 출력에 대한 12비트 듀티 사이클 |

**설명**: A상 출력의 듀티 사이클을 설정합니다.

---

### 3.14 PWMG_B_DUTY (0x1A) - PWM_GEN B Duty Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-12 | RESERVED | R-0 | 0h | 예약됨 |
| 11-0 | PWM_DUTY_OUTB | R/W | 0h | 상 B 출력에 대한 12비트 듀티 사이클 |

**설명**: B상 출력의 듀티 사이클을 설정합니다.

---

### 3.15 PWMG_C_DUTY (0x1B) - PWM_GEN C Duty Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-12 | RESERVED | R-0 | 0h | 예약됨 |
| 11-0 | PWM_DUTY_OUTC | R/W | 0h | 상 C 출력에 대한 12비트 듀티 사이클 |

**설명**: C상 출력의 듀티 사이클을 설정합니다.

---

### 3.16 PWM_STATE (0x1C) - PWM State Register
**리셋 값**: 0x0777

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-11 | RESERVED | R-0 | 0h | 예약됨 |
| 10-8 | PWMC_STATE | R/W | 7h | 상 C 드라이버 출력 제어 (8개 설정 포함 비트필드) |
| 7 | RESERVED | R-0 | 0h | 예약됨 |
| 6-4 | PWMB_STATE | R/W | 7h | 상 B 드라이버 출력 제어 (8개 설정 포함 비트필드) |
| 3 | RESERVED | R-0 | 0h | 예약됨 |
| 2-0 | PWMA_STATE | R/W | 7h | 상 A 드라이버 출력 제어 (8개 설정 포함 비트필드) |

**설명**: 각 상의 PWM 드라이브 상태를 설정합니다 (High/Low/Off/PWM 출력 조합).

**PWM_STATE 값** (각 상별로):
- 0h: High-Z (오프)
- 1h: 하이 사이드 온
- 2h: 로우 사이드 온
- 3h: PWM 모드
- 4h-7h: 다양한 조합

---

### 3.17 PWMG_CTRL (0x1D) - PWM_GEN Control Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-11 | RESERVED | R-0 | 0h | 예약됨 |
| 10 | PWM_EN | R/W | 0h | 3X 내부 모드 PWM 생성 활성화 |
| 9-8 | PWMCNTR_MODE | R/W | 0h | PWM 생성 카운터 모드 |
| 7-5 | PWM_OSC_SYNC | R/W | 0h | 오실레이터 동기화 및 PWM_SYNC 제어 |
| 4-2 | SPICLK_FREQ_SYNC | R/W | 0h | 오실레이터 동기화를 위한 SPI 클록 주파수 |
| 1-0 | SPISYNC_ACRCY | R/W | 0h | 동기화를 위한 SPI 클록 사이클 수 |

**설명**: 내부 PWM 생성에 대한 마스터 제어(활성화, 카운터 모드, 동기화, 오실레이터 보정).

**PWMCNTR_MODE 값**:
- 0h: 업 & 다운
- 1h: 업
- 2h: 다운
- 3h: 동작 없음

---

### 3.18 PWM_CTRL1 (0x20) - PWM Control Register 1
**리셋 값**: 0x0007

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-3 | RESERVED | R-0 | 0h | 예약됨 |
| 2 | SSC_DIS | R/W | 1h | 스프레드 스펙트럼 변조 비활성화 |
| 1-0 | PWM_MODE | R/W | 3h | PWM 모드 선택 |

**설명**: 스프레드 스펙트럼 활성화/비활성화, PWM 모드 선택.

**PWM_MODE 값**:
- 0h/1h: 6x PWM 모드
- 2h: 3x PWM 모드
- 3h: PWM 생성 모드

---

### 3.19 DRV_CTRL (0x22) - Predriver Control Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-8 | RESERVED | R-0 | 0h | 예약됨 |
| 7 | DLYCMP_EN | R/W | 0h | 드라이버 지연 보상 활성화 |
| 6-4 | TDEAD_CTRL | R/W | 0h | 데드타임 삽입 제어 |
| 3-2 | RESERVED | R-0 | 0h | 예약됨 |
| 1-0 | SLEW_RATE | R/W | 0h | 슬루 레이트 설정 |

**설명**: 게이트 드라이버 매개변수(지연 보상, 데드타임, 슬루 레이트)를 제어합니다.

**TDEAD_CTRL 값**:
- 0h: 데드타임 없음
- 1h: 200ns
- 2h: 400ns
- 3h: 600ns
- 4h: 800ns
- 5h: 1000ns
- 6h: 1200ns
- 7h: 1400ns

**SLEW_RATE 값**:
- 0h: 35 V/µs
- 1h: 75 V/µs
- 2h: 140 V/µs
- 3h: 230 V/µs

---

### 3.20 CSA_CTRL (0x23) - CSA Control Register
**리셋 값**: 0x0008

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-4 | RESERVED | R-0 | 0h | 예약됨 |
| 3 | CSA_EN | R/W | 1h | 전류 감지 증폭기 활성화 |
| 2 | RESERVED | R-0 | 0h | 예약됨 |
| 1-0 | CSA_GAIN | R/W | 0h | 전류 감지 증폭기 게인 |

**설명**: 전류 감지 증폭기 활성화 및 프로그래밍 가능한 게인을 제어합니다.

**CSA_GAIN 값**:
- 0h: 0.25 V/A
- 1h: 0.5 V/A
- 2h: 1 V/A
- 3h: 2 V/A

---

### 3.21 SYS_CTRL (0x3F) - System Control Register
**리셋 값**: 0x0000

| 비트 | 필드명 | 타입 | 리셋 | 설명 |
|------|--------|------|------|------|
| 15 | Parity_bit | R | 0h | 패리티 비트 |
| 14-12 | WRITE_KEY | W | 0h | 이 레지스터에 특정한 쓰기 키 (0x5) |
| 11-8 | RESERVED | R-0 | 0h | 예약됨 |
| 7 | REG_LOCK | R/W | 0h | 레지스터 잠금 비트 |
| 6 | SPI_PEN | R/W | 0h | SPI 및 tSPI 모두에 대한 패리티 활성화 |
| 5-0 | RESERVED | R-0 | 0h | 예약됨 |

**설명**: 레지스터 잠금, SPI/tSPI에 대한 패리티 활성화, 레지스터 잠금을 위한 쓰기 액세스 키를 제어합니다.

---

## 4. 주요 기능 그룹별 레지스터

### 4.1 상태 모니터링 레지스터
- **DEV_STS1** (0x00): 전체 장치 상태
- **OT_STS** (0x04): 온도 상태
- **SUP_STS** (0x05): 전원 공급 상태
- **DRV_STS** (0x06): 드라이버 상태
- **SYS_STS** (0x07): 시스템 상태

### 4.2 오류 제어 레지스터
- **FLT_MODE** (0x10): 오류 모드 설정
- **SYSF_CTRL** (0x12): 시스템 오류 제어
- **DRVF_CTRL** (0x13): 드라이버 오류 제어
- **FLT_TCTRL** (0x16): 오류 타이밍 제어
- **FLT_CLR** (0x17): 오류 클리어

### 4.3 PWM 제어 레지스터
- **PWM_SYNC_PRD** (0x0C): PWM 동기화 주기
- **PWMG_PERIOD** (0x18): PWM 생성 주기
- **PWMG_A_DUTY** (0x19): A상 듀티 사이클
- **PWMG_B_DUTY** (0x1A): B상 듀티 사이클
- **PWMG_C_DUTY** (0x1B): C상 듀티 사이클
- **PWM_STATE** (0x1C): PWM 상태
- **PWMG_CTRL** (0x1D): PWM 생성 제어
- **PWM_CTRL1** (0x20): PWM 제어 1

### 4.4 드라이버 제어 레지스터
- **DRV_CTRL** (0x22): 프리드라이버 제어
- **CSA_CTRL** (0x23): 전류 감지 증폭기 제어

### 4.5 시스템 제어 레지스터
- **SYS_CTRL** (0x3F): 시스템 제어

---

## 5. 초기화 시퀀스 권장사항

1. **전원 공급 후 대기**: 장치가 안정화될 때까지 최소 1ms 대기
2. **상태 확인**: DEV_STS1 레지스터를 읽어 RESET 비트가 설정되었는지 확인
3. **오류 모드 설정**: FLT_MODE 레지스터를 구성하여 원하는 오류 처리 동작 설정
4. **드라이버 매개변수 설정**: 
   - DRV_CTRL에서 데드타임 및 슬루 레이트 설정
   - DRVF_CTRL에서 과전류 보호 임계값 및 타이밍 설정
5. **전류 감지 구성**: CSA_CTRL에서 적절한 게인 설정
6. **PWM 모드 선택**: PWM_CTRL1에서 원하는 PWM 모드 선택
7. **PWM 매개변수 설정**: 주기 및 듀티 사이클 레지스터 구성 (내부 생성 모드를 사용하는 경우)
8. **오류 클리어**: FLT_CLR 레지스터에 1을 써서 시작 오류 지우기
9. **동작 시작**: PWM 신호 적용 또는 내부 PWM 생성 활성화

---

## 6. 참고 사항

### 6.1 SPI 통신
- 모든 레지스터는 SPI 인터페이스를 통해 액세스됩니다
- 선택적 패리티 비트(비트 15)는 SPI_PEN이 설정된 경우 활성화됩니다
- 프레임 오류, 패리티 오류, 버스 경합은 SYS_STS 레지스터에 보고됩니다

### 6.2 오류 처리
- 오류는 FLT_MODE 레지스터의 설정에 따라 래치되거나 자동 재시도될 수 있습니다
- 래치된 오류는 FLT_CLR 레지스터에 쓰기를 통해 지워야 합니다
- 재시도 타이밍은 FLT_TCTRL 레지스터에서 구성할 수 있습니다

### 6.3 전류 감지
- 3개의 통합 전류 감지 증폭기가 각 상의 전류를 모니터링합니다
- 게인은 CSA_CTRL 레지스터를 통해 프로그래밍 가능합니다 (0.25~2 V/A)
- FOC 및 전류 제어 알고리즘에 유용합니다

### 6.4 PWM 모드
- **6x PWM 모드**: 6개의 독립적인 PWM 입력
- **3x PWM 모드**: 3개의 PWM 입력 (하이 사이드만)
- **내부 PWM 생성 모드**: 레지스터를 통해 완전히 제어되는 PWM 생성

---

## 7. 문서 작성 정보
- **작성일**: 2025년
- **출처**: DRV8311 데이터시트 (Texas Instruments, SLVSFN2B)
- **섹션**: Section 9. DRV8311 Registers (페이지 52-74)

---

## 부록 A: 레지스터 액세스 타입

| 타입 | 설명 |
|------|------|
| R | 읽기 전용 |
| W | 쓰기 전용 |
| R/W | 읽기/쓰기 가능 |
| R-0 | 읽기 전용, 리셋 시 0 |

---

## 부록 B: 약어

| 약어 | 의미 |
|------|------|
| BLDC | Brushless DC Motor |
| CSA | Current Sense Amplifier |
| FOC | Field Oriented Control |
| OCP | Over Current Protection |
| OTSD | Over Temperature Shutdown |
| OTW | Over Temperature Warning |
| OTP | One Time Programmable |
| PWM | Pulse Width Modulation |
| SPI | Serial Peripheral Interface |
| UVP | Under Voltage Protection |
| MOSFET | Metal-Oxide-Semiconductor Field-Effect Transistor |
| HS | High Side |
| LS | Low Side |

---

*본 문서는 DRV8311 모터 드라이버 IC의 레지스터 참조를 위한 요약 문서입니다.*
