/**
  ******************************************************************************
  * @file           : drv8311.c
  * @brief          : DRV8311 BLDC Motor Driver implementation
  ******************************************************************************
  */

#include "drv8311.h"
#include <string.h>
#include <stdio.h>

/* Private function prototypes */
static HAL_StatusTypeDef DRV8311_SPITransfer(DRV8311_HandleTypeDef *hdrv, uint8_t *tx_data, uint8_t *rx_data, uint16_t size);
static void add_tspi_parity_16bit(uint8_t* tx_data);

// Helper function to add EVEN parity for tSPI format (DRV8311P)
// Correct tSPI frame format per datasheet:
// Bit 31: R/W (0=Write, 1=Read)
// Bit 30-27: Secondary device ID (4 bits)
// Bit 26-19: Address (8 bits)
// Bit 18-17: Reserved (00)
// Bit 16: Header Parity (covers bits 31-17)
// Bit 15-1: Data (15 bits)
// Bit 0: Data Parity (covers bits 15-1)
// Per datasheet: "The parity scheme used is EVEN parity"
static void add_tspi_parity_16bit(uint8_t* tx_data) {
    uint32_t frame = ((uint32_t)tx_data[0] << 24) |
                     ((uint32_t)tx_data[1] << 16) |
                     ((uint32_t)tx_data[2] << 8) |
                     (tx_data[3]);
    uint8_t header_bits = 0;
    uint8_t data_bits = 0;
    int i;

    // Count set bits in header (bits 31-17: R/W + DevID + Addr + Reserved)
    for (i = 17; i < 32; i++) {
        if ((frame >> i) & 0x00000001) {
            header_bits++;
        }
    }

    // Count set bits in data (bits 15-1)
    for (i = 1; i < 16; i++) {
        if ((frame >> i) & 0x00000001) {
            data_bits++;
        }
    }

    // Clear parity bits
    frame &= ~(1UL << 16);  // Header parity
    frame &= ~(1UL << 0);   // Data parity

    // Set header parity bit to make total EVEN
    if ((header_bits % 2) == 1) {
        frame |= (1UL << 16);
    }

    // Set data parity bit to make total EVEN
    if ((data_bits % 2) == 1) {
        frame |= (1UL << 0);
    }

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;
}


/**
  * @brief  Set nSLEEP pin HIGH (wake up DRV8311)
  */
void DRV8311_nSLEEP_High(void)
{
    HAL_GPIO_WritePin(DRV_NSLEEP_GPIO_Port, DRV_NSLEEP_Pin, GPIO_PIN_SET);
}

/**
  * @brief  Set nSLEEP pin LOW (sleep mode)
  */
void DRV8311_nSLEEP_Low(void)
{
    HAL_GPIO_WritePin(DRV_NSLEEP_GPIO_Port, DRV_NSLEEP_Pin, GPIO_PIN_RESET);
}

/**
  * @brief  Pulse nSLEEP to reset faults (15-50us LOW pulse)
  */
void DRV8311_nSLEEP_Pulse_Reset(void)
{
    printf("[DRV8311] Sending nSLEEP reset pulse...\r\n");

    // Set LOW for 30us (middle of 15-50us range)
    HAL_GPIO_WritePin(DRV_NSLEEP_GPIO_Port, DRV_NSLEEP_Pin, GPIO_PIN_RESET);
    for(volatile int i = 0; i < 2400; i++);  // ~30us at 480MHz

    // Set back to HIGH
    HAL_GPIO_WritePin(DRV_NSLEEP_GPIO_Port, DRV_NSLEEP_Pin, GPIO_PIN_SET);

    // Wait for wake-up (tWAKE = 1-3ms)
    HAL_Delay(5);

    printf("[DRV8311] nSLEEP reset complete\r\n");
}

/**
  * @brief  Initialize DRV8311P BLDC Motor Driver (tSPI version)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  hspi: Pointer to SPI handle
  * @param  htim: Pointer to TIM handle (TIM15 for PWM_SYNC, if used)
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Init(DRV8311_HandleTypeDef *hdrv, SPI_HandleTypeDef *hspi, TIM_HandleTypeDef *htim)
{
    HAL_StatusTypeDef status;
    uint16_t drv_ctrl_val, csa_ctrl_val, pwm_ctrl1_val;

    // Ensure nSLEEP is HIGH before initialization
    DRV8311_nSLEEP_High();
    HAL_Delay(5);  // Wait for wakeup (tWAKE = 1-3ms)

    if (hdrv == NULL || hspi == NULL) {
        return HAL_ERROR;
    }

    // Initialize handle with default values
    hdrv->hspi = hspi;
    hdrv->htim = htim;
    hdrv->pwm_mode = DRV8311_PWM_MODE_PWMGEN; // Default: PWM Generation mode (DRV8311P only supports this!)
    hdrv->slew_rate = DRV8311_DRV_SLEW_75V;  // 75 V/µs
    hdrv->deadtime = DRV8311_DRV_TDEAD_600NS; // 600ns
    hdrv->csa_gain = DRV8311_CSA_GAIN_050;   // 0.5 V/A
    hdrv->pwm_frequency = 20000;             // 20kHz default
    hdrv->pwm_duty = 0;                      // Start stopped
    hdrv->direction = 0;                     // CW

    printf("[DRV8311-%d] Initializing DRV8311P (tSPI version)...\r\n", hdrv->device_id);
    printf("[DRV8311-%d] SPI State: %d (1=Ready)\r\n", hdrv->device_id, hspi->State);

    // Step 1: Ensure CS is HIGH, wait for power-up
    HAL_GPIO_WritePin(hdrv->cs_port, hdrv->cs_pin, GPIO_PIN_SET);
    HAL_Delay(10);  // Power-up delay

    // Step 2: Unlock registers for writing
    printf("[DRV8311-%d] Unlocking registers...\r\n", hdrv->device_id);
    status = DRV8311_UnlockRegisters(hdrv);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to unlock registers\r\n");
        return status;
    }

    // Step 3: Clear all faults
    printf("[DRV8311-%d] Clearing faults...\r\n", hdrv->device_id);
    status = DRV8311_ClearFaults(hdrv);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to clear faults\r\n");
        return status;
    }
    HAL_Delay(5);

    // Step 4: Configure DRV_CTRL (0x22) - Slew Rate and Deadtime
    drv_ctrl_val = hdrv->slew_rate | hdrv->deadtime;
    printf("[DRV8311-%d] Configuring DRV_CTRL (0x22) = 0x%04X\r\n", hdrv->device_id, drv_ctrl_val);
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_DRV_CTRL, drv_ctrl_val);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to write DRV_CTRL\r\n");
        return status;
    }
    HAL_Delay(5);

    // Step 5: Configure CSA_CTRL (0x23) - Current Sense Amplifier
    csa_ctrl_val = DRV8311_CSA_EN | hdrv->csa_gain;
    printf("[DRV8311-%d] Configuring CSA_CTRL (0x23) = 0x%04X\r\n", hdrv->device_id, csa_ctrl_val);
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_CSA_CTRL, csa_ctrl_val);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to write CSA_CTRL\r\n");
        return status;
    }
    HAL_Delay(5);

    // Step 6: Configure PWM_CTRL1 (0x20) - PWM Mode
    pwm_ctrl1_val = hdrv->pwm_mode | DRV8311_SSC_DISABLE;
    printf("[DRV8311-%d] Configuring PWM_CTRL1 (0x20) = 0x%04X\r\n", hdrv->device_id, pwm_ctrl1_val);
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_CTRL1, pwm_ctrl1_val);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to write PWM_CTRL1\r\n");
        return status;
    }
    HAL_Delay(5);

    // Step 7: Configure PWM timer (if using external PWM)
    if (htim != NULL) {
        status = DRV8311_ConfigurePWM(hdrv, hdrv->pwm_frequency);
    }

    // Step 8: Read and display device status
    DRV8311_ReadDeviceStatus(hdrv);
    DRV8311_PrintDeviceStatus(hdrv);

    printf("[DRV8311-%d] Initialization complete\r\n", hdrv->device_id);
    printf("[DRV8311-%d] PWM Mode: %d, Slew: %d, Deadtime: 0x%X, CSA Gain: %d\r\n",
           hdrv->device_id, hdrv->pwm_mode, hdrv->slew_rate, hdrv->deadtime >> 4, hdrv->csa_gain);

    return HAL_OK;
}

/**
  * @brief  Reset DRV8311
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Reset(DRV8311_HandleTypeDef *hdrv)
{
    // Stop PWM
    HAL_TIM_PWM_Stop(hdrv->htim, DRV8311_PWM_SYNC_CHANNEL);

    // Clear faults
    return DRV8311_ClearFaults(hdrv);
}

/**
  * @brief  Unlock registers for writing (DRV8311P specific)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_UnlockRegisters(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Write to SYS_CTRL (0x3F) with WRITE_KEY=0x5 and REG_LOCK=0
    // Value: 0x5000 (bits 14-12 = 0x5, bit 7 = 0)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_SYS_CTRL, DRV8311_SYS_CTRL_UNLOCK);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to unlock registers\r\n");
        return status;
    }

    HAL_Delay(5);
    return HAL_OK;
}

/**
  * @brief  Clear fault flags (DRV8311P)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ClearFaults(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Write to FLT_CLR register (0x17)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_FLT_CLR, DRV8311_FLT_CLR_ALL);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to clear faults\r\n");
        return status;
    }

    HAL_Delay(5);

    // Clear the flag
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_FLT_CLR, 0x0000);

    return status;
}

/**
  * @brief  Write 16-bit register (for DRV8311P all registers)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  reg_addr: Register address
  * @param  value: 16-bit value to write
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_WriteRegister16(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint16_t value)
{
    uint8_t tx_data[4] = {0};
    uint8_t rx_data[4] = {0};
    uint8_t dev_addr = hdrv->device_id & 0x0F;  // Use device_id from handle (4-bit)

    // Correct tSPI frame format per datasheet (32-bit frame):
    // Bit 31: R/W (0=Write, 1=Read)
    // Bit 30-27: Secondary device ID (4 bits)
    // Bit 26-19: Address (8 bits)
    // Bit 18-17: Reserved (00)
    // Bit 16: Header Parity
    // Bit 15-1: Data (15 bits of 16-bit data)
    // Bit 0: Data Parity

    uint32_t frame = 0;
    frame |= (0UL << 31);                           // W=0 for write
    frame |= ((uint32_t)(dev_addr & 0x0F) << 27);  // Device ID (4 bits) at 30-27
    frame |= ((uint32_t)(reg_addr & 0xFF) << 19);  // Address (8 bits) at 26-19
    frame |= (0UL << 17);                           // Reserved bits 18-17
    // Header parity at bit 16 will be set by add_tspi_parity
    frame |= ((uint32_t)(value & 0xFFFF));         // 16-bit data at bits 15-0 (parity at bit 0)
    // Data parity at bit 0 will be set by add_tspi_parity

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;

    // Add parity to the tSPI frame (16-bit format)
    // TEMPORARILY DISABLED FOR TESTING
    // add_tspi_parity_16bit(tx_data);

    // tSPI: transfer 32-bit frame (4 bytes)
    return DRV8311_SPITransfer(hdrv, tx_data, rx_data, 4);
}

/**
  * @brief  Read 16-bit register (for DRV8311P all registers)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  reg_addr: Register address
  * @param  value: Pointer to store 16-bit read value
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ReadRegister16(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint16_t *value)
{
    uint8_t tx_data[4] = {0};
    uint8_t rx_data[4] = {0};
    HAL_StatusTypeDef status;
    uint8_t dev_addr = hdrv->device_id & 0x0F;  // Use device_id from handle (4-bit)

    // Correct tSPI frame format per datasheet (32-bit): Read command
    // Bit 31: R/W (1=Read)
    // Bit 30-27: Secondary device ID (4 bits)
    // Bit 26-19: Address (8 bits)
    // Bit 18-17: Reserved (00)
    // Bit 16: Header Parity
    // Bit 15-1: Data (0x0000 for read)
    // Bit 0: Data Parity

    uint32_t frame = 0;
    frame |= (1UL << 31);                           // R=1 for read
    frame |= ((uint32_t)(dev_addr & 0x0F) << 27);  // Device ID (4 bits) at 30-27
    frame |= ((uint32_t)(reg_addr & 0xFF) << 19);  // Address (8 bits) at 26-19
    frame |= (0UL << 17);                           // Reserved bits 18-17
    frame |= (0x0000);                              // Data = 0 for read (bits 15-0)

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;

    // TEMPORARILY DISABLED FOR TESTING
    // add_tspi_parity_16bit(tx_data);

    // Send read command
    // tSPI: transfer 32-bit frame (4 bytes)
    // DRV8311 returns data DURING the read command (single transaction)
    status = DRV8311_SPITransfer(hdrv, tx_data, rx_data, 4);
    if (status == HAL_OK) {
        // SDO output is 24 bits: 8-bit status + 16-bit data
        // In 32-bit SPI transfer, 24-bit SDO is aligned to bits 31-8:
        //   Bits 31-24: Status (8 bits S7-S0)
        //   Bits 23-8:  Data (16 bits D15-D0)
        //   Bits 7-0:   Don't care
        uint32_t rx_frame = ((uint32_t)rx_data[0] << 24) |
                            ((uint32_t)rx_data[1] << 16) |
                            ((uint32_t)rx_data[2] << 8) |
                            (rx_data[3]);

        uint8_t status_byte = (rx_frame >> 24) & 0xFF;
        *value = (uint16_t)((rx_frame >> 8) & 0xFFFF);

        printf("[DEBUG] RX Frame: 0x%08lX, Status: 0x%02X, Data: 0x%04X\r\n",
               rx_frame, status_byte, *value);
    }

    return status;
}

/**
  * @brief  Set PWM mode (DRV8311P)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  mode: 0=6PWM, 2=3PWM, 3=PWM Gen
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_SetPWMMode(DRV8311_HandleTypeDef *hdrv, uint8_t mode)
{
    uint16_t pwm_ctrl1;

    if (mode > 3) {
        return HAL_ERROR;
    }

    // Write to PWM_CTRL1 (0x20)
    pwm_ctrl1 = mode | DRV8311_SSC_DISABLE;
    hdrv->pwm_mode = mode;

    return DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_CTRL1, pwm_ctrl1);
}

/**
  * @brief  Set motor direction (for PWM Gen mode)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  direction: 0=CW, 1=CCW
  * @retval HAL status
  * @note   For external PWM mode, handle direction in MCU PWM configuration
  */
HAL_StatusTypeDef DRV8311_SetDirection(DRV8311_HandleTypeDef *hdrv, uint8_t direction)
{
    hdrv->direction = direction ? 1 : 0;

    // Direction is typically handled by phase sequence in external PWM mode
    // or by PWM_STATE register in internal PWM Gen mode
    printf("[DRV8311-%d] Direction set to: %s\r\n",
           hdrv->device_id, hdrv->direction ? "CCW" : "CW");

    return HAL_OK;
}

/**
  * @brief  Set motor speed (PWM duty cycle)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  duty_percent: Duty cycle 0-100%
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_SetSpeed(DRV8311_HandleTypeDef *hdrv, uint8_t duty_percent)
{
    uint32_t pulse;

    if (duty_percent > 100) {
        duty_percent = 100;
    }

    hdrv->pwm_duty = duty_percent;

    // Calculate pulse value
    // TIM15: Period = 999 (from main.c)
    pulse = (uint32_t)((duty_percent * 999) / 100);

    // Update PWM duty cycle
    __HAL_TIM_SET_COMPARE(hdrv->htim, DRV8311_PWM_SYNC_CHANNEL, pulse);

    return HAL_OK;
}

/**
  * @brief  Start motor
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Start(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Start PWM generation
    status = HAL_TIM_PWM_Start(hdrv->htim, DRV8311_PWM_SYNC_CHANNEL);
    if (status != HAL_OK) {
        return status;
    }

    printf("[DRV8311] Motor started (Duty: %d%%, Dir: %s)\r\n",
           hdrv->pwm_duty,
           hdrv->direction ? "CCW" : "CW");

    return HAL_OK;
}

/**
  * @brief  Stop motor
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Stop(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Stop PWM generation
    status = HAL_TIM_PWM_Stop(hdrv->htim, DRV8311_PWM_SYNC_CHANNEL);

    printf("[DRV8311] Motor stopped\r\n");

    return status;
}

/**
  * @brief  Brake motor (set all phases to low-side ON)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  * @note   Uses PWM_STATE register to short all phases to ground
  */
HAL_StatusTypeDef DRV8311_Brake(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;
    uint16_t pwm_state;

    // Set all phases to LS_ON (0x2) for braking
    // Bits 10-8: PWMC_STATE = 2 (LS ON)
    // Bits 6-4: PWMB_STATE = 2 (LS ON)
    // Bits 2-0: PWMA_STATE = 2 (LS ON)
    pwm_state = (DRV8311_PWM_STATE_LS_ON << 8) |
                (DRV8311_PWM_STATE_LS_ON << 4) |
                (DRV8311_PWM_STATE_LS_ON << 0);

    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_STATE, pwm_state);

    printf("[DRV8311-%d] Brake applied\r\n", hdrv->device_id);

    return status;
}

/**
  * @brief  Coast motor (set all phases to Hi-Z)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  * @note   Uses PWM_STATE register to set high impedance
  */
HAL_StatusTypeDef DRV8311_Coast(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;
    uint16_t pwm_state;

    // Set all phases to High-Z (0x0)
    pwm_state = 0x0000;

    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_STATE, pwm_state);

    printf("[DRV8311-%d] Coast mode\r\n", hdrv->device_id);

    return status;
}

/**
  * @brief  Read device status (DEV_STS1)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ReadDeviceStatus(DRV8311_HandleTypeDef *hdrv)
{
    return DRV8311_ReadRegister16(hdrv, DRV8311_REG_DEV_STS1, &hdrv->dev_status);
}

/**
  * @brief  Read driver status (DRV_STS)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ReadDriverStatus(DRV8311_HandleTypeDef *hdrv)
{
    return DRV8311_ReadRegister16(hdrv, DRV8311_REG_DRV_STS, &hdrv->drv_status);
}

/**
  * @brief  Check if fault occurred
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval 1 if fault, 0 if no fault
  */
uint8_t DRV8311_IsFault(DRV8311_HandleTypeDef *hdrv)
{
    DRV8311_ReadDeviceStatus(hdrv);
    return (hdrv->dev_status & DRV8311_STS1_FAULT) ? 1 : 0;
}

/**
  * @brief  Print device status to console
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval None
  */
void DRV8311_PrintDeviceStatus(DRV8311_HandleTypeDef *hdrv)
{
    printf("\r\n[DRV8311-%d] Device Status (DEV_STS1): 0x%04X\r\n",
           hdrv->device_id, hdrv->dev_status);

    if (hdrv->dev_status & DRV8311_STS1_FAULT) {
        printf("  - FAULT: Device fault detected\r\n");
    }
    if (hdrv->dev_status & DRV8311_STS1_OT) {
        printf("  - OT: Overtemperature warning/shutdown\r\n");
    }
    if (hdrv->dev_status & DRV8311_STS1_UVP) {
        printf("  - UVP: Undervoltage protection (CP, AVDD, or VIN_AVDD)\r\n");
    }
    if (hdrv->dev_status & DRV8311_STS1_OCP) {
        printf("  - OCP: Overcurrent protection\r\n");
    }
    if (hdrv->dev_status & DRV8311_STS1_SPI_FLT) {
        printf("  - SPI_FLT: SPI communication fault\r\n");
    }
    if (hdrv->dev_status & DRV8311_STS1_RESET) {
        printf("  - RESET: Power-on reset condition (clear with CLR_FLT)\r\n");
    }
    if (hdrv->dev_status & DRV8311_STS1_OTP_FLT) {
        printf("  - OTP_FLT: OTP read fault\r\n");
    }

    if (hdrv->dev_status == 0) {
        printf("  - No Faults\r\n");
    }
}

/**
  * @brief  Configure PWM timer
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  frequency_hz: PWM frequency in Hz
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ConfigurePWM(DRV8311_HandleTypeDef *hdrv, uint16_t frequency_hz)
{
    // TIM15 is already configured in main.c
    // Prescaler = 239, Period = 999
    // Frequency = 240MHz / (240 * 1000) = 1kHz
    //
    // To change frequency, would need to reconfigure timer
    // For now, just use the existing configuration

    hdrv->pwm_frequency = frequency_hz;

    return HAL_OK;
}

/**
  * @brief  tSPI transfer wrapper for DRV8311P
  * @note   DRV8311PRRWR uses tSPI with 32-bit (4-byte) frames
  *         Format: [DEV_ADDR2][R/W1][ADDR7][DATA8][PARITY1][Reserved13]
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  tx_data: Transmit data buffer (4 bytes)
  * @param  rx_data: Receive data buffer (4 bytes)
  * @param  size: Number of bytes (always 4 for tSPI)
  * @retval HAL status
  */
static HAL_StatusTypeDef DRV8311_SPITransfer(DRV8311_HandleTypeDef *hdrv, uint8_t *tx_data, uint8_t *rx_data, uint16_t size)
{
    HAL_StatusTypeDef status;

    // CS Low
    HAL_GPIO_WritePin(hdrv->cs_port, hdrv->cs_pin, GPIO_PIN_RESET);

    // Small delay for CS setup time (tCSS min = 50ns per datasheet)
    for(volatile int i=0; i<10; i++);

    // tSPI: Send 4 bytes and receive 4 bytes simultaneously
    status = HAL_SPI_TransmitReceive(hdrv->hspi, tx_data, rx_data, size, 100);

    // Small delay before CS high (tCSH min = 50ns per datasheet)
    for(volatile int i=0; i<10; i++);

    // CS High
    HAL_GPIO_WritePin(hdrv->cs_port, hdrv->cs_pin, GPIO_PIN_SET);

    // Debug output (4 bytes for tSPI)
    printf("[tSPI_DBG-%d] TX: 0x%02X 0x%02X 0x%02X 0x%02X -> RX: 0x%02X 0x%02X 0x%02X 0x%02X (Status: %d)\r\n",
           hdrv->device_id,
           tx_data[0], tx_data[1], tx_data[2], tx_data[3],
           rx_data[0], rx_data[1], rx_data[2], rx_data[3],
           status);

    return status;
}


/**
  * @brief  Enable tSPI PWM Generation Mode
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_EnablePWMGeneration(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    printf("[DRV8311-%d] Enabling tSPI PWM Generation Mode...\r\n", hdrv->device_id);

    // 0. Unlock registers first!
    status = DRV8311_UnlockRegisters(hdrv);
    if (status != HAL_OK) {
        return status;
    }

    // 1. Set PWM_MODE to PWM Generation Mode (bits 1-0 = 3, bit 2 = SSC_DIS)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_CTRL1, 0x0007);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to set PWM_MODE\r\n");
        return status;
    }
    HAL_Delay(5);

    // 2. Set PWM_STATE to PWM mode for all phases (0x0777)
    // Bits 10-8: PWMC_STATE = 7 (PWM mode)
    // Bits 6-4: PWMB_STATE = 7 (PWM mode)
    // Bits 2-0: PWMA_STATE = 7 (PWM mode)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWM_STATE, 0x0777);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to set PWM_STATE\r\n");
        return status;
    }
    HAL_Delay(5);

    printf("[DRV8311-%d] tSPI PWM Generation Mode enabled\r\n", hdrv->device_id);
    return HAL_OK;
}

/**
  * @brief  Set PWM Period for internal PWM generation
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  period: PWM period value (12-bit, 0-4095)
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_SetPWMPeriod(DRV8311_HandleTypeDef *hdrv, uint16_t period)
{
    HAL_StatusTypeDef status;

    if (period > 4095) {
        period = 4095;  // 12-bit max
    }

    // Write period to PWMG_PERIOD register (0x18) - 16-bit register
    // Bits 11-0: PWM_PRD_OUT (12-bit period value)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWMG_PERIOD, period & 0x0FFF);
    if (status != HAL_OK) return status;

    printf("[DRV8311-%d] PWM Period set to %d\r\n", hdrv->device_id, period);
    return HAL_OK;
}

/**
  * @brief  Set PWM Duty Cycle for each phase
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  duty_a: Phase A duty (12-bit, 0-4095)
  * @param  duty_b: Phase B duty (12-bit, 0-4095)
  * @param  duty_c: Phase C duty (12-bit, 0-4095)
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_SetPWMDuty(DRV8311_HandleTypeDef *hdrv, uint16_t duty_a, uint16_t duty_b, uint16_t duty_c)
{
    HAL_StatusTypeDef status;

    if (duty_a > 4095) duty_a = 4095;
    if (duty_b > 4095) duty_b = 4095;
    if (duty_c > 4095) duty_c = 4095;

    // Write Phase A duty (16-bit register, bits 11-0 = duty)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWMG_A_DUTY, duty_a & 0x0FFF);
    if (status != HAL_OK) return status;

    // Write Phase B duty
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWMG_B_DUTY, duty_b & 0x0FFF);
    if (status != HAL_OK) return status;

    // Write Phase C duty
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWMG_C_DUTY, duty_c & 0x0FFF);
    if (status != HAL_OK) return status;

    printf("[DRV8311-%d] PWM Duty set: A=%d, B=%d, C=%d\r\n", hdrv->device_id, duty_a, duty_b, duty_c);
    return HAL_OK;
}

/**
  * @brief  Start Internal PWM Generation
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_StartPWMGen(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Enable PWM generation by setting PWM_EN bit in PWMG_CTRL (0x1D)
    // Bit 10: PWM_EN (16-bit register)
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWMG_CTRL, 0x0400);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to start PWM generation\r\n");
        return status;
    }

    printf("[DRV8311-%d] Internal PWM Generation started\r\n", hdrv->device_id);
    return HAL_OK;
}

/**
  * @brief  Stop Internal PWM Generation
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_StopPWMGen(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Disable PWM generation by clearing PWM_EN bit
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_PWMG_CTRL, 0x0000);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to stop PWM generation\r\n");
        return status;
    }

    printf("[DRV8311-%d] Internal PWM Generation stopped\r\n", hdrv->device_id);
    return HAL_OK;
}