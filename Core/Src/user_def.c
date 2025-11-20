/* Includes */
#include "main.h"
#include "user_def.h"
#include "drv8311.h"
#include "ads8638.h" // Added for ADS8638_HandleTypeDef and related functions
#include "adc_func.h"  // Added for init_adc, start_adc, stop_adc
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

void test_ads8638(void)
{
    ADS8638_HandleTypeDef hadc_ext;
    HAL_StatusTypeDef status;
    uint8_t comm_ok;

    printf("\r\n========================================\r\n");
    printf("  ADS8638 External ADC Test (SPI4)\r\n");
    printf("  CS Pin: PD1 (SPI4_NCS)\r\n");
    printf("  AL_PD Pin: PC9\r\n");
    printf("========================================\r\n\r\n");

    // Check AL_PD pin state
    GPIO_PinState alpd_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
    printf("AL_PD Pin State: %s\r\n", alpd_state == GPIO_PIN_SET ? "HIGH (OK)" : "LOW (ERROR!)");
    if (alpd_state == GPIO_PIN_RESET) {
        printf("  [CRITICAL] AL_PD is LOW! ADS8638 is in power-down mode!\r\n");
        printf("  Setting AL_PD HIGH now...\r\n");
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
        HAL_Delay(100);
        alpd_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
        printf("  AL_PD Pin State after set: %s\r\n\r\n", alpd_state == GPIO_PIN_SET ? "HIGH" : "LOW");
    } else {
        printf("  AL_PD is correctly set to HIGH\r\n\r\n");
    }

    // 0. Raw SPI Test (DIAGNOSTIC)
    printf("Step 0: Raw SPI Test...\r\n");
    uint8_t tx_buf[2] = {0x00, 0x00};  // NOP command
    uint8_t rx_buf[2] = {0x00, 0x00};

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
    // No delay - just ensure CS is high
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
    // No delay - start SPI immediately
    status = HAL_SPI_TransmitReceive(&hspi4, tx_buf, rx_buf, 2, 100);
    // No delay - CS can go high immediately
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);

    printf("  Raw SPI Test: TX=[0x%02X 0x%02X] RX=[0x%02X 0x%02X] Status=%d\r\n",
           tx_buf[0], tx_buf[1], rx_buf[0], rx_buf[1], status);

    if (rx_buf[0] == 0xFF && rx_buf[1] == 0xFF) {
        printf("  [WARNING] MISO stuck HIGH (0xFFFF) - Check hardware connection!\r\n");
    } else if (rx_buf[0] == 0x00 && rx_buf[1] == 0x00) {
        printf("  [WARNING] MISO stuck LOW (0x0000) - Check hardware connection!\r\n");
    } else {
        printf("  MISO appears to be working (non-fixed pattern)\r\n");
    }

    // Additional test with different TX pattern
    printf("\n  Testing with different TX patterns...\r\n");
    tx_buf[0] = 0xAA; tx_buf[1] = 0x55;
    rx_buf[0] = 0x00; rx_buf[1] = 0x00;
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
    // No delay - start SPI immediately
    status = HAL_SPI_TransmitReceive(&hspi4, tx_buf, rx_buf, 2, 100);
    // No delay - CS can go high immediately
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
    printf("  TX=[0xAA 0x55] RX=[0x%02X 0x%02X]\r\n", rx_buf[0], rx_buf[1]);

    printf("\n  [CRITICAL] Check PE6 (SPI4_MOSI) connection to ADS8638 SDI pin!\r\n");
    printf("  If registers read 0xFF, MOSI is likely not connected.\r\n");
    printf("\r\n");

    // 1. Initialize ADS8638
    printf("Step 1: Initializing ADS8638...\r\n");
    status = ADS8638_Init(&hadc_ext, &hspi4); // Use SPI4
    if (status != HAL_OK) {
        printf("  [ERROR] ADS8638 Initialization failed!\r\n");
        return;
    }
    printf("  ADS8638 Initialized successfully.\r\n");

    // 2. Check Communication
    printf("Step 2: Checking communication...\r\n");
    comm_ok = ADS8638_CheckCommunication(&hadc_ext);
    if (comm_ok) {
        printf("  Communication with ADS8638 OK.\r\n");
    } else {
        printf("  [ERROR] Communication with ADS8638 FAILED!\r\n");
        printf("  Possible issues:\r\n");
        printf("  - MISO not connected to PA6 (SPI1_MISO)\r\n");
        printf("  - MOSI not connected to PD7 (SPI1_MOSI)\r\n");
        printf("  - SCK not connected to PA5 (SPI1_SCK)\r\n");
        printf("  - CS not connected to PD10\r\n");
        printf("  - ADS8638 power supply (AVDD/DVDD) issue\r\n");
        printf("  - SPI mode mismatch (should be Mode 1)\r\n");
        return;
    }

    // 3. Test register read/write
    printf("Step 3: Testing register access...\r\n");
    uint8_t reg_val;

    // Read Feature Select register (should be 0x00 by default)
    status = ADS8638_ReadRegister(&hadc_ext, ADS8638_REG_FEATURE_SEL, &reg_val);
    printf("  Feature Select Reg (0x03): 0x%02X (Status=%d)\r\n", reg_val, status);

    // Read Auto Sequence Enable register
    status = ADS8638_ReadRegister(&hadc_ext, ADS8638_REG_AUTO_SEQ_EN, &reg_val);
    printf("  Auto Seq Enable Reg (0x01): 0x%02X (Status=%d)\r\n", reg_val, status);

    // Try Manual Mode single channel read
    printf("\nStep 4: Manual Mode - Single Channel Test...\r\n");
    uint16_t adc_value;
    for (uint8_t ch = 0; ch < 8; ch++) {
        status = ADS8638_ReadChannel(&hadc_ext, ch, &adc_value);
        float voltage = ADS8638_ConvertToVoltage(adc_value, hadc_ext.range_config[ch]);
        printf("  CH%d: %4d / %.3fV (Status=%d)\r\n", ch, adc_value, voltage, status);
        HAL_Delay(50);
    }

    // 5. Read all channels in Auto-Scan mode
    printf("\nStep 5: Auto-Scan Mode Test...\r\n");
    printf("  (Discarding first read for sync)\r\n");
    ADS8638_ReadAllChannels_AutoScan(&hadc_ext); // Discard first read

    for (int i = 0; i < 3; i++) // Read 3 times
    {
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

void test_internal_adc(void)
{
    printf("\r\n========================================\r\n");
    printf("  Internal ADC Test\r\n");
    printf("========================================\r\n\r\n");

    init_adc();
    start_adc();

    printf("Starting ADC conversion and reading values...\r\n");
    HAL_Delay(100);

    // Assuming adc_dma_buffer is externed or accessible
    extern uint16_t adc_dma_buffer[2][8];
    extern uint16_t adc3_bdma_buffer[8];

    for (int i = 0; i < 10; i++) // Read 10 times
    {
        HAL_Delay(500); // Wait for some conversions
        printf("ADC1 Ch0-3: %4d %4d %4d %4d | ", adc_dma_buffer[0][0], adc_dma_buffer[0][1], adc_dma_buffer[0][2], adc_dma_buffer[0][3]);
        printf("ADC2 Ch0-3: %4d %4d %4d %4d | ", adc_dma_buffer[1][0], adc_dma_buffer[1][1], adc_dma_buffer[1][2], adc_dma_buffer[1][3]);
        printf("ADC3 Ch0-3: %4d %4d %4d %4d\r\n", adc3_bdma_buffer[0], adc3_bdma_buffer[1], adc3_bdma_buffer[2], adc3_bdma_buffer[3]);
    }

    stop_adc();
    printf("\r\nInternal ADC Test Complete.\r\n");
}

void test_motor_run_spi1(void)
{
    DRV8311_HandleTypeDef hdrv;
    HAL_StatusTypeDef status;
    uint8_t reg_value;

    printf("\r\n========================================\r\n");
    printf("  DRV8311 Motor Run Test (SPI1) - Robust\r\n");
    printf("  Device on PD10\r\n");
    printf("========================================\r\n\r\n");

    // 1. Initialize Handle
    hdrv.device_id = 1; // Assuming this is the first DRV8311
    hdrv.cs_port = GPIOD;
    hdrv.cs_pin = GPIO_PIN_14;
    hdrv.hspi = &hspi1; // Use SPI1
    hdrv.htim = &htim15;

    // Hardware Check
    printf(">>> Hardware Check <<<\r\n");
    printf("1. Check VDRAIN (VM) voltage: Must be 8V-48V\r\n");
    printf("2. Check VCC = 3.3V\r\n");
    printf("3. Check nSLEEP = HIGH (connected to 3.3V)\r\n");
    printf("4. For SPI test only: Disconnect motor from ABC outputs\r\n");
    printf("Waiting 3 seconds...\r\n\r\n");
    HAL_Delay(3000);

    // Read all registers first (0x00-0x06)
    printf("Step 0: Reading standard registers (0x00-0x06)...\r\n");
    for (uint8_t addr = 0x00; addr <= 0x06; addr++) {
        status = DRV8311_ReadRegister(&hdrv, addr, &reg_value);
        printf("  Reg 0x%02X = 0x%02X\r\n", addr, reg_value);
        HAL_Delay(10);
    }
    printf("\r\n");

    // Read extended registers for tSPI PWM control (0x07-0x0F)
    printf("Step 0b: Reading extended tSPI PWM registers (0x07-0x0F)...\r\n");
    for (uint8_t addr = 0x07; addr <= 0x0F; addr++) {
        status = DRV8311_ReadRegister(&hdrv, addr, &reg_value);
        printf("  Reg 0x%02X = 0x%02X", addr, reg_value);

        // Try to identify the register based on common patterns
        if (addr >= 0x07 && addr <= 0x09) {
            printf("  (Possibly PWM Duty - Phase A/B/C?)");
        } else if (addr >= 0x0A && addr <= 0x0B) {
            printf("  (Possibly PWM Frequency?)");
        } else if (addr == 0x0C) {
            printf("  (Possibly PWM Control?)");
        }
        printf("\r\n");
        HAL_Delay(10);
    }
    printf("\r\n");

    // 2. Disable VDS sensing to prevent startup faults
    printf("Step 1: Disabling VDS monitoring...\r\n");
    // OCP_CONTROL (0x05), VDS_OCP_MODE = 00 (VDS sensing disabled)
    status = DRV8311_WriteRegister(&hdrv, 0x05, 0x00);
    if (status != HAL_OK) {
        printf("  [ERROR] SPI write failed!\r\n");
        return;
    }
    HAL_Delay(5); // Short delay for register write

    // 3. VERIFY the write by reading back the register
    printf("Step 2: Verifying VDS is disabled...\r\n");
    status = DRV8311_ReadRegister(&hdrv, 0x05, &reg_value);
    printf("  OCP Control Register (0x05) read back as: 0x%02X\r\n", reg_value);
    if ((reg_value & 0x30) != 0) { // Check VDS_OCP_MODE bits
        printf("  [ERROR] Failed to disable VDS monitoring!\r\n");
        return;
    }
    printf("  VDS monitoring successfully disabled.\r\n");

    // 4. Now, clear any faults
    printf("Step 3: Clearing faults...\r\n");
    DRV8311_ClearFaults(&hdrv);
    HAL_Delay(100);

    // 5. Check if faults are cleared
    if (DRV8311_IsFault(&hdrv)) {
        printf("  [ERROR] Faults could not be cleared! Final check:\r\n");
        DRV8311_PrintFaultStatus(&hdrv);
        return;
    }
    printf("  No faults detected. Ready to run.\r\n\r\n");

    // 6. Start motor
    printf("--- Starting Motor Sequence ---\r\n");
    printf("Starting motor at 20%% speed (CW)...\r\n");
    DRV8311_SetDirection(&hdrv, 0); // 0 for CW
    DRV8311_SetSpeed(&hdrv, 20);
    DRV8311_Start(&hdrv);
    HAL_Delay(5000);

    printf("Increasing speed to 40%%...\r\n");
    DRV8311_SetSpeed(&hdrv, 40);
    HAL_Delay(5000);

    printf("Stopping motor...\r\n");
    DRV8311_Stop(&hdrv);
    HAL_Delay(1000);

    printf("\r\n--- Test Complete ---\r\n");
}

void test_motor_run_spi2(void)
{
    DRV8311_HandleTypeDef hdrv;
    HAL_StatusTypeDef status;
    uint8_t reg_value;

    printf("\r\n========================================\r\n");
    printf("  DRV8311 Motor Run Test (SPI2) - Robust\r\n");
    printf("  Device on PE11\r\n");
    printf("========================================\r\n\r\n");

    // 1. Initialize Handle
    hdrv.device_id = 4;
    hdrv.cs_port = GPIOE;
    hdrv.cs_pin = GPIO_PIN_11;
    hdrv.hspi = &hspi2;
    hdrv.htim = &htim15;

    // 2. Disable VDS sensing to prevent startup faults
    printf("Step 1: Disabling VDS monitoring...\r\n");
    // OCP_CONTROL (0x05), VDS_OCP_MODE = 00 (VDS sensing disabled)
    status = DRV8311_WriteRegister(&hdrv, 0x05, 0x00);
    if (status != HAL_OK) {
        printf("  [ERROR] SPI write failed!\r\n");
        return;
    }
    HAL_Delay(5); // Short delay for register write

    // 3. VERIFY the write by reading back the register
    printf("Step 2: Verifying VDS is disabled...\r\n");
    status = DRV8311_ReadRegister(&hdrv, 0x05, &reg_value);
    printf("  OCP Control Register (0x05) read back as: 0x%02X\r\n", reg_value);
    if ((reg_value & 0x30) != 0) { // Check VDS_OCP_MODE bits
        printf("  [ERROR] Failed to disable VDS monitoring!\r\n");
        return;
    }
    printf("  VDS monitoring successfully disabled.\r\n");

    // 4. Now, clear any faults
    printf("Step 3: Clearing faults...\r\n");
    DRV8311_ClearFaults(&hdrv);
    HAL_Delay(100);

    // 5. Check if faults are cleared
    if (DRV8311_IsFault(&hdrv)) {
        printf("  [ERROR] Faults could not be cleared! Final check:\r\n");
        DRV8311_PrintFaultStatus(&hdrv);
        return;
    }
    printf("  No faults detected. Ready to run.\r\n\r\n");

    // 6. Start motor
    printf("--- Starting Motor Sequence ---\r\n");
    printf("Starting motor at 20%% speed (CW)...\r\n");
    DRV8311_SetDirection(&hdrv, 0); // 0 for CW
    DRV8311_SetSpeed(&hdrv, 20);
    DRV8311_Start(&hdrv);
    HAL_Delay(5000);

    printf("Increasing speed to 40%%...\r\n");
    DRV8311_SetSpeed(&hdrv, 40);
    HAL_Delay(5000);

    printf("Stopping motor...\r\n");
    DRV8311_Stop(&hdrv);
    HAL_Delay(1000);

    printf("\r\n--- Test Complete ---\r\n");
}

void test_motor_tspi_pwmgen_spi1(void)
{
    DRV8311_HandleTypeDef hdrv;
    HAL_StatusTypeDef status;
    uint8_t reg_value;

    printf("\r\n========================================\r\n");
    printf("  DRV8311 tSPI PWM Generation Test (SPI1)\r\n");
    printf("  Device on PD14\r\n");
    printf("  Internal PWM Mode - No external PWM needed!\r\n");
    printf("========================================\r\n\r\n");

    // 1. Initialize Handle
    hdrv.device_id = 1;
    hdrv.cs_port = GPIOD;
    hdrv.cs_pin = GPIO_PIN_14;
    hdrv.hspi = &hspi1;
    hdrv.htim = &htim15;

    // Hardware Check
    printf(">>> Hardware Check <<<\r\n");
    printf("1. Check VDRAIN (VM) voltage: Must be 8V-48V\r\n");
    printf("2. Check VCC = 3.3V\r\n");
    printf("3. Check nSLEEP = HIGH (connected to 3.3V)\r\n");
    printf("4. Motor connected to A/B/C outputs\r\n");
    printf("5. NO external PWM needed for tSPI mode!\r\n");
    printf("Waiting 3 seconds...\r\n\r\n");
    HAL_Delay(3000);

    // Read basic status registers first (0x00-0x06)
    printf("Step 0: Reading basic status registers (0x00-0x06)...\r\n");
    for (uint8_t addr = 0x00; addr <= 0x06; addr++) {
        status = DRV8311_ReadRegister(&hdrv, addr, &reg_value);
        printf("  Reg 0x%02X = 0x%02X", addr, reg_value);
        if (addr == 0x00) {
            printf(" (DEV_STS1)");
            if (reg_value == 0x00) {
                printf(" *** ERROR: Chip not responding! ***");
                printf("\r\n  CHECK:");
                printf("\r\n    1. nSLEEP pin = HIGH (3.3V)?");
                printf("\r\n    2. VDRAIN voltage = 8-48V?");
                printf("\r\n    3. VCC = 3.3V?");
                printf("\r\n    4. Chip power-on?");
            } else {
                if (reg_value & 0x80) printf(" [RESET=1]");
                if (reg_value & 0x01) printf(" [FAULT=1]");
            }
        }
        printf("\r\n");
        HAL_Delay(10);
    }
    printf("\r\n");

    // Read extended registers for tSPI PWM control (0x07-0x0F)
    printf("Step 0a: Reading extended tSPI PWM registers (0x07-0x0F)...\r\n");
    for (uint8_t addr = 0x07; addr <= 0x0F; addr++) {
        status = DRV8311_ReadRegister(&hdrv, addr, &reg_value);
        printf("  Reg 0x%02X = 0x%02X\r\n", addr, reg_value);
        HAL_Delay(10);
    }
    printf("\r\n");

    // Read PWM control registers
    printf("Step 0b: Reading PWM control registers...\r\n");
    for (uint8_t addr = 0x18; addr <= 0x20; addr++) {
        status = DRV8311_ReadRegister(&hdrv, addr, &reg_value);
        printf("  Reg 0x%02X = 0x%02X\r\n", addr, reg_value);
        HAL_Delay(10);
    }
    printf("\r\n");

    // 2. Disable VDS sensing
    printf("Step 1: Disabling VDS monitoring...\r\n");
    status = DRV8311_WriteRegister(&hdrv, 0x05, 0x00);
    if (status != HAL_OK) {
        printf("  [ERROR] SPI write failed!\r\n");
        return;
    }
    HAL_Delay(5);

    // 3. Clear faults
    printf("Step 2: Clearing faults...\r\n");
    status = DRV8311_WriteRegister(&hdrv, DRV8311_REG_FLT_CLR, 0x01);
    HAL_Delay(100);

    // 4. Enable tSPI PWM Generation Mode
    printf("Step 3: Enabling tSPI PWM Generation Mode...\r\n");
    status = DRV8311_EnablePWMGeneration(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to enable PWM generation mode!\r\n");
        return;
    }

    // Verify registers were written
    printf("Step 3b: Verifying register writes...\r\n");
    DRV8311_ReadRegister(&hdrv, DRV8311_REG_SYS_CTRL, &reg_value);
    printf("  SYS_CTRL (0x3F) = 0x%02X (should show unlocked)\r\n", reg_value);
    DRV8311_ReadRegister(&hdrv, DRV8311_REG_PWM_CTRL1, &reg_value);
    printf("  PWM_CTRL1 (0x20) = 0x%02X (should be 0x07)\r\n", reg_value);
    DRV8311_ReadRegister(&hdrv, DRV8311_REG_PWM_STATE, &reg_value);
    printf("  PWM_STATE (0x1C) = 0x%02X (should be 0x77 or higher)\r\n", reg_value);
    printf("\r\n");

    // 5. Set PWM Period (e.g., 200 for ~20kHz with internal clock)
    printf("Step 4: Setting PWM Period...\r\n");
    status = DRV8311_SetPWMPeriod(&hdrv, 200);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to set PWM period!\r\n");
        return;
    }

    // 6. Start motor with 20% duty
    printf("\r\n--- Starting Motor Sequence ---\r\n");
    printf("Starting motor at 20%% duty...\r\n");

    // For open loop, set duty cycle for 6-step commutation
    // Phase A: 20%, B: 0%, C: 0% (simple test pattern)
    uint16_t period = 200;
    uint16_t duty_20 = (period * 20) / 100;

    status = DRV8311_SetPWMDuty(&hdrv, duty_20, 0, 0);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to set PWM duty!\r\n");
        return;
    }

    // Start internal PWM generation
    printf("Starting internal PWM generation...\r\n");
    status = DRV8311_StartPWMGen(&hdrv);
    if (status != HAL_OK) {
        printf("  [ERROR] Failed to start PWM generation!\r\n");
        return;
    }
    HAL_Delay(5000);

    // Increase duty to 40%
    printf("Increasing duty to 40%%...\r\n");
    uint16_t duty_40 = (period * 40) / 100;
    DRV8311_SetPWMDuty(&hdrv, duty_40, 0, 0);
    HAL_Delay(5000);

    // Stop motor
    printf("Stopping motor...\r\n");
    DRV8311_StopPWMGen(&hdrv);
    HAL_Delay(1000);

    printf("\r\n--- tSPI PWM Generation Test Complete ---\r\n");
}

/* Main Application Logic */
void init_proc(void)
{
}

void run_proc(void)
{
    init_proc();
    test_ads8638();
    //test_motor_run_spi1();  // DRV8311P: tSPI config + STM32 external PWM
    //test_motor_tspi_pwmgen_spi1();  // Only works on DRV8311S (SPI version with internal PWM gen)
    //test_motor_run_spi2();
    while(1)
    {

    }
}
