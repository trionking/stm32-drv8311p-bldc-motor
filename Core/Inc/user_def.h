#ifndef __USER_DEF_H
#define __USER_DEF_H

#include "main.h"

// Main application entry
void run_proc(void);
void init_proc(void);

// Original Test Functions
void test_uart2(void);
void test_adc(void);
void test_spi_raw(void);
void test_ads8638(void);
void test_spi4_loopback(void);
void test_spi4_pins(void);
void test_drv8311(void);
void test_drv8311_pwm_only(void);
void test_spi1_pins(void);
void test_spi1_basic(void);
void test_dual_drv8311(void);

// Added Test Functions
void test_spi2_basic(void);
void test_pe15_toggle(void);
void test_nsleep_toggle(void);
void test_motor_run_spi2(void);
void test_motor_tspi_pwmgen_spi1(void);

#endif /* __USER_DEF_H */