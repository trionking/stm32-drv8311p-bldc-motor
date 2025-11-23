/* Includes */
#include "main.h"
#include "user_def.h"
#include "drv8311.h"
#include "ads8638.h"
#include "adc_func.h"
#include <stdio.h>

/* Externs */
extern UART_HandleTypeDef huart2;
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi4;
extern TIM_HandleTypeDef htim15;

/* putchar implementation */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 1);
    return ch;
}

/**
 * @brief  ADS8638 External ADC Test
 * @note   Tests SPI4 communication and multi-channel ADC sampling
 */
void test_ads8638(void)
{
    ADS8638_HandleTypeDef hadc_ext;
    HAL_StatusTypeDef status;
    uint8_t comm_ok;

    printf("\r\n========================================\r\n");
    printf("  ADS8638 External ADC Test (SPI4)\r\n");
    printf("  CS Pin: PD1 (SPI4_NCS)\r\n");
    printf("========================================\r\n\r\n");

    // Initialize ADS8638
    printf("Step 1: Initializing ADS8638...\r\n");
    status = ADS8638_Init(&hadc_ext, &hspi4);
    if (status != HAL_OK) {
        printf("  [ERROR] ADS8638 Initialization failed!\r\n");
        return;
    }
    printf("  ADS8638 Initialized successfully.\r\n");

    // Check Communication
    printf("Step 2: Checking communication...\r\n");
    comm_ok = ADS8638_CheckCommunication(&hadc_ext);
    if (comm_ok) {
        printf("  Communication with ADS8638 OK.\r\n");
    } else {
        printf("  [ERROR] Communication with ADS8638 FAILED!\r\n");
        return;
    }

    // Manual Mode single channel read
    printf("\nStep 3: Manual Mode - Single Channel Test...\r\n");
    uint16_t adc_value;
    for (uint8_t ch = 0; ch < 8; ch++) {
        status = ADS8638_ReadChannel(&hadc_ext, ch, &adc_value);
        float voltage = ADS8638_ConvertToVoltage(adc_value, hadc_ext.range_config[ch]);
        printf("  CH%d: %4d / %.3fV (Status=%d)\r\n", ch, adc_value, voltage, status);
        HAL_Delay(50);
    }

    // Read all channels in Auto-Scan mode
    printf("\nStep 4: Auto-Scan Mode Test...\r\n");
    ADS8638_ReadAllChannels_AutoScan(&hadc_ext); // Discard first read

    for (int i = 0; i < 3; i++) {
        status = ADS8638_ReadAllChannels_AutoScan(&hadc_ext);
        if (status != HAL_OK) {
            printf("  [ERROR] Failed to read all channels!\r\n");
            return;
        }
        printf("  Read #%d - ADC Readings (Raw / Voltage):\r\n", i+1);
        for (uint8_t ch = 0; ch < 8; ch++) {
            printf("    CH%d: %4d / %.3fV\r\n", ch, hadc_ext.adc_data[ch], hadc_ext.voltage[ch]);
        }
        HAL_Delay(500);
    }

    printf("\r\n--- ADS8638 Test Complete ---\r\n");
}

/**
 * @brief  Internal ADC Test
 * @note   Tests STM32 built-in ADC1/2/3 with DMA
 */
void test_internal_adc(void)
{
    printf("\r\n========================================\r\n");
    printf("  Internal ADC Test\r\n");
    printf("========================================\r\n\r\n");

    init_adc();
    start_adc();

    printf("Starting ADC conversion and reading values...\r\n");
    HAL_Delay(100);

    extern uint16_t adc_dma_buffer[2][8];
    extern uint16_t adc3_bdma_buffer[8];

    for (int i = 0; i < 10; i++) {
        HAL_Delay(500);
        printf("ADC1 Ch0-3: %4d %4d %4d %4d | ",
               adc_dma_buffer[0][0], adc_dma_buffer[0][1],
               adc_dma_buffer[0][2], adc_dma_buffer[0][3]);
        printf("ADC2 Ch0-3: %4d %4d %4d %4d | ",
               adc_dma_buffer[1][0], adc_dma_buffer[1][1],
               adc_dma_buffer[1][2], adc_dma_buffer[1][3]);
        printf("ADC3 Ch0-3: %4d %4d %4d %4d\r\n",
               adc3_bdma_buffer[0], adc3_bdma_buffer[1],
               adc3_bdma_buffer[2], adc3_bdma_buffer[3]);
    }

    stop_adc();
    printf("\r\nInternal ADC Test Complete.\r\n");
}

/**
 * @brief  DRV8311P Chip Health Check (NO MOTOR REQUIRED)
 * @note   Tests SPI communication and register access
 */
void test_drv8311_chip_health_check(void)
{
    DRV8311_HandleTypeDef hdrv = {0};
    HAL_StatusTypeDef status;
    uint16_t reg_value;
    uint8_t test_passed = 0;
    uint8_t test_failed = 0;

    printf("\r\n");
    printf("========================================\r\n");
    printf("  DRV8311P Chip Health Check\r\n");
    printf("  ** NO MOTOR REQUIRED **\r\n");
    printf("  Testing SPI Communication Only\r\n");
    printf("========================================\r\n\r\n");

    // Initialize handle
    hdrv.device_id = 0;
    hdrv.cs_port = GPIOD;
    hdrv.cs_pin = GPIO_PIN_10;
    hdrv.hspi = &hspi1;
    hdrv.htim = &htim15;

    printf(">>> Test 1: nSLEEP Reset <<<\r\n");
    DRV8311_nSLEEP_Pulse_Reset();
    HAL_Delay(100);
    printf("  [PASS] nSLEEP reset pulse sent\r\n\r\n");
    test_passed++;

    printf(">>> Test 2: Reading DEV_STS1 (Power-On Status) <<<\r\n");
    status = DRV8311_ReadRegister16(&hdrv, DRV8311_REG_DEV_STS1, &reg_value);
    printf("  DEV_STS1 (0x00) = 0x%04X\r\n", reg_value);

    if (status != HAL_OK) {
        printf("  [FAIL] SPI communication error!\r\n");
        test_failed++;
    } else if (reg_value == 0xFFFF) {
        printf("  [FAIL] MISO stuck HIGH (reads 0xFFFF)\r\n");
        test_failed++;
    } else {
        printf("  [PASS] Chip is responding!\r\n");
        test_passed++;
    }
    printf("\r\n");

    if (status != HAL_OK || reg_value == 0xFFFF) {
        printf("========================================\r\n");
        printf("  CRITICAL: Communication FAILED!\r\n");
        printf("========================================\r\n");
        return;
    }

    printf(">>> Test 3: Register Unlock Test <<<\r\n");
    status = DRV8311_UnlockRegisters(&hdrv);
    if (status == HAL_OK) {
        HAL_Delay(10);
        DRV8311_ReadRegister16(&hdrv, DRV8311_REG_SYS_CTRL, &reg_value);
        printf("  SYS_CTRL (0x3F) = 0x%04X\r\n", reg_value);
        if ((reg_value & 0x0080) == 0) {
            printf("  [PASS] Registers unlocked\r\n");
            test_passed++;
        } else {
            printf("  [FAIL] Registers still locked\r\n");
            test_failed++;
        }
    } else {
        printf("  [FAIL] Unlock command failed\r\n");
        test_failed++;
    }
    printf("\r\n");

    printf(">>> Test 4: Fault Clear Test <<<\r\n");
    status = DRV8311_ClearFaults(&hdrv);
    if (status == HAL_OK) {
        printf("  [PASS] Fault clear command successful\r\n");
        test_passed++;
    } else {
        printf("  [FAIL] Fault clear command failed\r\n");
        test_failed++;
    }
    printf("\r\n");

    // Summary
    printf("========================================\r\n");
    printf("  TEST SUMMARY\r\n");
    printf("========================================\r\n");
    printf("  Tests Passed: %d\r\n", test_passed);
    printf("  Tests Failed: %d\r\n", test_failed);
    printf("\r\n");

    if (test_failed == 0) {
        printf("  CHIP IS HEALTHY!\r\n");
        printf("  Safe to proceed with motor tests.\r\n");
    } else {
        printf("  CHIP HAS ISSUES!\r\n");
        printf("  Review failures before motor tests.\r\n");
    }
    printf("========================================\r\n");
}

/**
 * @brief  DRV8311 Motor Control: Progressive Duty Ramping Test
 * @note   Tests Phase A output with gradually increasing duty (3% to 15%)
 */
void test_motor_tspi_pwmgen_spi1(void)
{
    DRV8311_HandleTypeDef hdrv = {0};
    HAL_StatusTypeDef status;
    uint16_t dev_sts1;

    printf("\r\n========================================\r\n");
    printf("  DRV8311 Progressive Duty Ramp Test\r\n");
    printf("  Phase A Only - Safe Low Current Test\r\n");
    printf("========================================\r\n\r\n");

    // Initialize handle
    hdrv.device_id = 0;
    hdrv.cs_port = GPIOD;
    hdrv.cs_pin = GPIO_PIN_10;
    hdrv.hspi = &hspi1;
    hdrv.htim = &htim15;

    printf(">>> Hardware Reset <<<\r\n");
    DRV8311_nSLEEP_Pulse_Reset();
    HAL_Delay(100);

    printf(">>> Initializing DRV8311 <<<\r\n");
    status = DRV8311_Init(&hdrv, &hspi1, &htim15);
    if (status != HAL_OK) {
        printf("  [ERROR] Init failed!\r\n");
        return;
    }
    printf("  Initialization complete\r\n\r\n");

    // Enable PWM Generation Mode
    printf(">>> Enabling PWM Generation <<<\r\n");
    status = DRV8311_EnablePWMGeneration(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to enable PWM!\r\n");
        return;
    }

    uint16_t period = 200;
    status = DRV8311_SetPWMPeriod(&hdrv, period);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to set period!\r\n");
        return;
    }

    // Clear faults
    DRV8311_ClearFaults(&hdrv);
    HAL_Delay(100);

    // Start PWM generation
    printf(">>> Starting PWM Generation <<<\r\n");
    status = DRV8311_StartPWMGen(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to start PWM!\r\n");
        return;
    }
    HAL_Delay(100);

    // Progressive duty ramp
    #define DUTY_START_PERCENT      3
    #define DUTY_MAX_PERCENT        15
    #define DUTY_INCREMENT_PERCENT  2

    printf("\n--- Progressive Duty Ramp Test ---\r\n");
    uint8_t duty_percent = DUTY_START_PERCENT;

    while (duty_percent <= DUTY_MAX_PERCENT) {
        uint16_t current_duty = (period * duty_percent) / 100;
        printf("\n[Test] Phase A @ %d%% duty (value=%d)\r\n", duty_percent, current_duty);

        DRV8311_SetPWMDuty(&hdrv, current_duty, 0, 0);
        HAL_Delay(1000);

        // Check for faults
        DRV8311_ReadRegister16(&hdrv, DRV8311_REG_DEV_STS1, &dev_sts1);
        if (dev_sts1 & DRV8311_STS1_FAULT) {
            printf("  [FAULT] DEV_STS1: 0x%04X - STOPPING!\r\n", dev_sts1);
            break;
        }

        printf("  [OK] No fault detected\r\n");
        duty_percent += DUTY_INCREMENT_PERCENT;
    }

    // Turn off
    printf("\nTurning off all phases...\r\n");
    DRV8311_SetPWMDuty(&hdrv, 0, 0, 0);
    HAL_Delay(500);

    DRV8311_StopPWMGen(&hdrv);
    printf("\r\n--- Test Complete ---\r\n");
}

/**
 * @brief  DRV8311P Output Voltage Test (NO MOTOR REQUIRED)
 * @note   Tests PWM output on U, V, W pins with multimeter/oscilloscope
 */
void test_drv8311_output_voltage(void)
{
    DRV8311_HandleTypeDef hdrv = {0};
    HAL_StatusTypeDef status;
    uint16_t period = 200;

    printf("\r\n");
    printf("========================================\r\n");
    printf("  DRV8311P Output Voltage Test\r\n");
    printf("  ** NO MOTOR REQUIRED **\r\n");
    printf("  Measure voltage on U, V, W pins\r\n");
    printf("========================================\r\n\r\n");

    // Initialize handle
    hdrv.device_id = 0;
    hdrv.cs_port = GPIOD;
    hdrv.cs_pin = GPIO_PIN_10;
    hdrv.hspi = &hspi1;
    hdrv.htim = &htim15;

    printf(">>> Initializing DRV8311 <<<\r\n");
    DRV8311_nSLEEP_Pulse_Reset();
    HAL_Delay(100);

    status = DRV8311_Init(&hdrv, &hspi1, &htim15);
    if (status != HAL_OK) {
        printf("  [ERROR] Init failed!\r\n");
        return;
    }

    // Enable PWM Generation Mode
    status = DRV8311_EnablePWMGeneration(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to enable PWM!\r\n");
        return;
    }

    status = DRV8311_SetPWMPeriod(&hdrv, period);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to set period!\r\n");
        return;
    }

    // Start PWM
    status = DRV8311_StartPWMGen(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to start PWM!\r\n");
        return;
    }

    // Test different duty cycles
    uint8_t duty_percentages[] = {5, 10, 15, 20};
    float vdrain = 12.0f;  // Adjust based on your power supply

    printf("\nTesting Phase A with different duties...\r\n");
    printf("(Assuming VDRAIN = %.1fV)\r\n\r\n", vdrain);

    for (int i = 0; i < 4; i++) {
        uint8_t duty_pct = duty_percentages[i];
        uint16_t duty_val = (period * duty_pct) / 100;
        float expected_voltage = (vdrain * duty_pct) / 100.0f;

        printf(">>> Phase A @ %d%% duty <<<\r\n", duty_pct);
        printf("  Expected: ~%.2fV DC average\r\n", expected_voltage);
        printf("  Holding for 5 seconds...\r\n");

        DRV8311_SetPWMDuty(&hdrv, duty_val, 0, 0);
        HAL_Delay(5000);

        DRV8311_SetPWMDuty(&hdrv, 0, 0, 0);
        HAL_Delay(1000);
    }

    // Stop PWM
    DRV8311_StopPWMGen(&hdrv);
    printf("\r\n--- Test Complete ---\r\n");
}

/**
 * @brief  1-Phase Excitation Motor Test
 * @note   Simplest BLDC control - only ONE phase active at a time
 *         Sequence: A → B → C → A (forward)
 */
void test_motor_1phase_excitation(void)
{
    printf("\r\n");
    printf("========================================\r\n");
    printf("  1-Phase Excitation Motor Test\r\n");
    printf("  600mA Motor - Ultra Safe Mode\r\n");
    printf("========================================\r\n\r\n");

    HAL_StatusTypeDef status;
    DRV8311_HandleTypeDef hdrv = {0};
    uint16_t dev_sts1 = 0;

    // Initialize handle
    hdrv.device_id = 0;
    hdrv.cs_port = GPIOD;
    hdrv.cs_pin = GPIO_PIN_10;
    hdrv.hspi = &hspi1;
    hdrv.htim = &htim15;

    printf(">>> Hardware Reset <<<\r\n");
    DRV8311_nSLEEP_Pulse_Reset();
    HAL_Delay(100);

    printf(">>> Initializing DRV8311 <<<\r\n");
    status = DRV8311_Init(&hdrv, &hspi1, &htim15);
    if (status != HAL_OK) {
        printf("  [ERROR] Init failed!\r\n");
        return;
    }
    printf("  Initialization OK\r\n\r\n");

    // Enable PWM Generation Mode
    printf(">>> Enabling tSPI PWM Generation <<<\r\n");
    status = DRV8311_EnablePWMGeneration(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to enable PWM!\r\n");
        return;
    }

    // Set PWM Period
    uint16_t period = 200;
    status = DRV8311_SetPWMPeriod(&hdrv, period);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to set period!\r\n");
        return;
    }

    // Safety parameters
    #define MOTOR_DUTY_PERCENT      10
    #define STEP_DELAY_MS          500
    #define NUM_ROTATIONS           10

    uint16_t duty_value = (period * MOTOR_DUTY_PERCENT) / 100;

    printf("=== 1-Phase Excitation Parameters ===\r\n");
    printf("Duty: %d%% (value=%d)\r\n", MOTOR_DUTY_PERCENT, duty_value);
    printf("Step delay: %d ms\r\n", STEP_DELAY_MS);
    printf("Rotations: %d\r\n", NUM_ROTATIONS);
    printf("Sequence: A → B → C → A (forward)\r\n\r\n");

    // Clear faults
    DRV8311_ClearFaults(&hdrv);
    HAL_Delay(100);

    // Start PWM generation
    printf(">>> Starting PWM Generation <<<\r\n");
    status = DRV8311_StartPWMGen(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to start PWM!\r\n");
        return;
    }
    HAL_Delay(100);

    // 1-Phase Excitation Sequence
    printf("\r\n>>> Starting Motor Rotation <<<\r\n\r\n");

    for (int rotation = 0; rotation < NUM_ROTATIONS; rotation++) {
        printf("[Rotation %d/%d]\r\n", rotation + 1, NUM_ROTATIONS);

        // Step 1: Phase A
        printf("  Step 1: Phase A ON  (B=0, C=0)\r\n");
        DRV8311_SetPWMDuty(&hdrv, duty_value, 0, 0);
        HAL_Delay(STEP_DELAY_MS);

        DRV8311_ReadRegister16(&hdrv, DRV8311_REG_DEV_STS1, &dev_sts1);
        if (dev_sts1 & DRV8311_STS1_FAULT) {
            printf("  [FAULT] at Phase A - DEV_STS1: 0x%04X\r\n", dev_sts1);
            goto motor_stop;
        }

        // Step 2: Phase B
        printf("  Step 2: Phase B ON  (A=0, C=0)\r\n");
        DRV8311_SetPWMDuty(&hdrv, 0, duty_value, 0);
        HAL_Delay(STEP_DELAY_MS);

        DRV8311_ReadRegister16(&hdrv, DRV8311_REG_DEV_STS1, &dev_sts1);
        if (dev_sts1 & DRV8311_STS1_FAULT) {
            printf("  [FAULT] at Phase B - DEV_STS1: 0x%04X\r\n", dev_sts1);
            goto motor_stop;
        }

        // Step 3: Phase C
        printf("  Step 3: Phase C ON  (A=0, B=0)\r\n");
        DRV8311_SetPWMDuty(&hdrv, 0, 0, duty_value);
        HAL_Delay(STEP_DELAY_MS);

        DRV8311_ReadRegister16(&hdrv, DRV8311_REG_DEV_STS1, &dev_sts1);
        if (dev_sts1 & DRV8311_STS1_FAULT) {
            printf("  [FAULT] at Phase C - DEV_STS1: 0x%04X\r\n", dev_sts1);
            goto motor_stop;
        }

        printf("\r\n");
    }

    printf(">>> Test Complete - No Faults! <<<\r\n\r\n");

motor_stop:
    // Turn off all phases
    printf(">>> Stopping Motor <<<\r\n");
    DRV8311_SetPWMDuty(&hdrv, 0, 0, 0);
    HAL_Delay(500);

    DRV8311_StopPWMGen(&hdrv);
    printf("Motor stopped\r\n");
    printf("========================================\r\n\r\n");
}

/* Main Application Logic */
void init_proc(void)
{
    // Add initialization code here if needed
}

void run_proc(void)
{
    init_proc();

    // STEP 1: Health check (no motor required)
    // test_drv8311_chip_health_check();

    // STEP 2: If health check passes, proceed with motor tests
    // test_motor_tspi_pwmgen_spi1();     // Progressive duty test
    test_motor_1phase_excitation();       // 1-Phase excitation motor rotation

    while(1)
    {
        // Idle loop
    }
}
