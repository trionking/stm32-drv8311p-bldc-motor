# STM32H743 + DRV8311P BLDC Motor Control Firmware

STM32H743 마이크로컨트롤러와 Texas Instruments DRV8311P 모터 드라이버를 사용한 BLDC 모터 제어 펌웨어입니다.

## 주요 특징

- **MCU**: STM32H743VIHX (ARM Cortex-M7, 480MHz)
- **모터 드라이버**: Texas Instruments DRV8311P (3상 BLDC 게이트 드라이버)
- **제어 방식**: 1상 여자 방식 (1-Phase Excitation)
- **안전 기능**: 소프트웨어 듀티 제한 (3-15%) - 600mA 모터용 과전류 보호
- **통신**: tSPI (Texas Instruments 전용 SPI) 인터페이스

## 하드웨어 구성

- **모터 드라이버**: DRV8311P (듀얼 드라이버 탑재)
- **외부 ADC**: ADS8638 (8채널 12비트 SAR ADC)
- **통신 인터페이스**: UART, FDCAN, SPI
- **PWM 타이머**: TIM1~TIM8 (모터 제어용)

## 프로젝트 구조

```
Core/
├── Inc/                    # 헤더 파일
│   ├── drv8311.h           # DRV8311 드라이버 인터페이스
│   ├── ads8638.h           # ADS8638 ADC 인터페이스
│   └── user_def.h          # 테스트 함수 선언
├── Src/                    # 소스 파일
│   ├── drv8311.c           # DRV8311 드라이버 구현
│   ├── ads8638.c           # ADS8638 ADC 구현
│   └── user_def.c          # 애플리케이션 로직 (564 lines)
.doc/                       # 개발 문서
├── DRV8311_BLDC_Motor_Control_Implementation_Guide_*.md
├── DRV8311_Low_Current_Protection_Strategy.md
└── (기타 분석 문서들)
```

## 빌드 방법

### 필수 도구

- STM32CubeIDE 1.19.0 이상
- ARM GCC toolchain (STM32CubeCLT 1.19.0)

### 빌드 명령어

```bash
cd Debug
PATH="${STM32_CUBE_CLT_PATH}/GNU-tools-for-STM32/bin:$PATH" \
  make -j all
```

빌드 결과: `Debug/bldc_h743_mot_v101.elf` (약 84KB)

## 주요 기능

### 1. 칩 진단 (test_drv8311_chip_health_check)
모터 없이 DRV8311 칩의 상태를 확인합니다.
- SPI 통신 테스트
- 레지스터 읽기/쓰기 검증
- 폴트 상태 확인

### 2. 듀티 램핑 테스트 (test_motor_tspi_pwmgen_spi1)
A상 단독으로 듀티비를 점진적으로 증가시킵니다 (3%→15%).
- 모터 회전 없음
- 안전성 검증용

### 3. 1상 여자 모터 회전 (test_motor_1phase_excitation)
A→B→C 순차적으로 여자하여 모터를 회전시킵니다.
- 듀티: 10% (매우 안전)
- 단계당 지연: 500ms
- 각 단계마다 폴트 확인

### 4. 출력 전압 측정 (test_drv8311_output_voltage)
DRV8311의 출력 전압을 측정합니다 (모터 불필요).

### 5. ADC 테스트
- **외부 ADC**: ADS8638 8채널 테스트
- **내장 ADC**: STM32 내장 ADC 테스트

## 안전 고려사항

### 소전류 모터 보호 전략

DRV8311의 하드웨어 OCP (5A/9A)가 600mA 모터에는 너무 높습니다. 따라서:

1. **소프트웨어 듀티 제한**: 3-15% 범위로 제한
2. **점진적 램핑**: 급격한 전류 증가 방지
3. **단계별 폴트 확인**: 각 동작 후 상태 확인
4. **긴급 정지**: 폴트 감지 시 즉시 모터 정지

## 개발 히스토리

전체 개발 과정은 `.doc/DRV8311_BLDC_Motor_Control_Implementation_Guide_*.md`에 상세히 기록되어 있습니다:

- **Phase 1**: DRV8311 초기화 문제 해결
- **Phase 2**: SPI 통신 안정화
- **Phase 3**: 칩 손상 및 복구
- **Phase 4**: 저전류 모터 보호 전략 수립
- **Phase 5**: 1상 여자 방식 모터 회전 성공
- **Phase 6**: 코드 정리 및 최적화 (1500→564 lines)

## 문서

- **구현 가이드**: `.doc/DRV8311_BLDC_Motor_Control_Implementation_Guide_*.md`
- **저전류 보호 전략**: `.doc/DRV8311_Low_Current_Protection_Strategy.md`
- **칩 손상 복구 보고서**: `.doc/DRV8311_Chip_Damage_Recovery_Report.md`
- **레지스터 맵**: `.doc/drv8311_register_map.md`

## 라이선스

이 프로젝트는 개발 참고용으로 제공됩니다.

## 기여

버그 리포트나 개선 제안은 Issues 탭을 이용해주세요.

## 참고 자료

- [DRV8311 데이터시트](https://www.ti.com/product/DRV8311) - Texas Instruments
- [STM32H743 레퍼런스 매뉴얼](https://www.st.com/resource/en/reference_manual/dm00176879.pdf) - STMicroelectronics
- [ADS8638 데이터시트](https://www.ti.com/product/ADS8638) - Texas Instruments

---

**상태**: ✅ 1상 여자 방식 모터 회전 성공, 코드 정리 완료
**최종 빌드**: 84,680 bytes (코드 정리 후 약 10KB 감소)
