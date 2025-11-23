#ifndef __USER_DEF_H
#define __USER_DEF_H

#include "main.h"

// Main application entry
void run_proc(void);
void init_proc(void);

// Hardware Test Functions (Non-DRV8311)
void test_ads8638(void);
void test_internal_adc(void);

// DRV8311 Motor Control Functions
void test_drv8311_chip_health_check(void);     // Chip health diagnostic (no motor required)
void test_motor_tspi_pwmgen_spi1(void);        // Progressive duty ramping test (Phase A only)
void test_drv8311_output_voltage(void);        // Output voltage measurement (no motor required)
void test_motor_1phase_excitation(void);       // 1-Phase excitation motor rotation

#endif /* __USER_DEF_H */
