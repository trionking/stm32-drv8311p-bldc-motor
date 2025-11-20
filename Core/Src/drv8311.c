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
static void add_tspi_parity_8bit(uint8_t* tx_data);
static void add_tspi_parity_16bit(uint8_t* tx_data);
static HAL_StatusTypeDef DRV8311_WriteRegister16(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint16_t value);

// Helper function to add odd parity for 8-bit data format
// tSPI frame (8-bit): [DEV_ADDR2][R/W1][ADDR7][DATA8][PARITY1][Reserved13]
// Parity at bit 13, covers bits 14-31
static void add_tspi_parity_8bit(uint8_t* tx_data) {
    uint32_t frame = ((uint32_t)tx_data[0] << 24) |
                     ((uint32_t)tx_data[1] << 16) |
                     ((uint32_t)tx_data[2] << 8) |
                     (tx_data[3]);
    uint8_t bit_count = 0;
    int i;

    // Count set bits in bits 14-31 (DEV_ADDR + R/W + ADDR + DATA8)
    for (i = 14; i < 32; i++) {
        if ((frame >> i) & 0x00000001) {
            bit_count++;
        }
    }

    // Clear parity bit (bit 13)
    frame &= ~(1UL << 13);

    // Set parity bit to make total count odd
    if ((bit_count % 2) == 0) {
        frame |= (1UL << 13);
    }

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;
}

// Helper function to add odd parity for 16-bit data format
// tSPI frame (16-bit): [DEV_ADDR2][R/W1][ADDR7][DATA16][PARITY1][Reserved5]
// Parity at bit 5, covers bits 6-31
static void add_tspi_parity_16bit(uint8_t* tx_data) {
    uint32_t frame = ((uint32_t)tx_data[0] << 24) |
                     ((uint32_t)tx_data[1] << 16) |
                     ((uint32_t)tx_data[2] << 8) |
                     (tx_data[3]);
    uint8_t bit_count = 0;
    int i;

    // Count set bits in bits 6-31 (DEV_ADDR + R/W + ADDR + DATA16)
    for (i = 6; i < 32; i++) {
        if ((frame >> i) & 0x00000001) {
            bit_count++;
        }
    }

    // Clear parity bit (bit 5)
    frame &= ~(1UL << 5);

    // Set parity bit to make total count odd
    if ((bit_count % 2) == 0) {
        frame |= (1UL << 5);
    }

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;
}


/**
  * @brief  Initialize DRV8311 BLDC Motor Driver
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  hspi: Pointer to SPI handle (SPI1)
  * @param  htim: Pointer to TIM handle (TIM15 for PWM_SYNC)
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Init(DRV8311_HandleTypeDef *hdrv, SPI_HandleTypeDef *hspi, TIM_HandleTypeDef *htim)
{
    HAL_StatusTypeDef status;

    if (hdrv == NULL || hspi == NULL || htim == NULL) {
        return HAL_ERROR;
    }

    // Initialize handle
    hdrv->hspi = hspi;
    hdrv->htim = htim;
    hdrv->pwm_mode = 1;           // Default: 3PWM mode
    hdrv->gate_drive_hs = 0x77;   // Medium drive strength
    hdrv->gate_drive_ls = 0x77;   // Medium drive strength
    hdrv->pwm_frequency = 20000;  // 20kHz default
    hdrv->pwm_duty = 0;           // Start stopped
    hdrv->direction = 0;          // CW

    // Check SPI state
    printf("[DRV8311-%d] SPI1 State: %d (1=Ready, 2=Busy)\r\n", hdrv->device_id, hspi->State);
    printf("[DRV8311-%d] SPI1 ErrorCode: 0x%08X\r\n", hdrv->device_id, (unsigned int)hspi->ErrorCode);

    // Ensure CS is HIGH initially
    HAL_GPIO_WritePin(hdrv->cs_port, hdrv->cs_pin, GPIO_PIN_SET);
    HAL_Delay(10);

    // Clear any faults
    status = DRV8311_ClearFaults(hdrv);
    if (status != HAL_OK) {
        return status;
    }

    HAL_Delay(10);

    // Configure gate drive strength
    status = DRV8311_WriteRegister(hdrv, DRV8311_REG_GATE_DRIVE_HS, hdrv->gate_drive_hs);
    if (status != HAL_OK) {
        return status;
    }

    status = DRV8311_WriteRegister(hdrv, DRV8311_REG_GATE_DRIVE_LS, hdrv->gate_drive_ls);
    if (status != HAL_OK) {
        return status;
    }

    // Set PWM mode (3PWM)
    status = DRV8311_SetPWMMode(hdrv, hdrv->pwm_mode);
    if (status != HAL_OK) {
        return status;
    }

    // Disable VDS overcurrent protection (for testing)
    printf("[DRV8311-%d] Disabling VDS OCP for testing...\r\n", hdrv->device_id);
    status = DRV8311_WriteRegister(hdrv, 0x05, 0x00);  // OCP Control = 0 (disable)
    if (status != HAL_OK) {
        return status;
    }
    HAL_Delay(10);

    // Clear faults again after disabling OCP
    status = DRV8311_ClearFaults(hdrv);
    if (status != HAL_OK) {
        return status;
    }

    // Configure PWM timer (TIM15)
    status = DRV8311_ConfigurePWM(hdrv, hdrv->pwm_frequency);

    printf("[DRV8311-%d] Initialized successfully\r\n", hdrv->device_id);
    printf("[DRV8311-%d] PWM Mode: %s\r\n", hdrv->device_id, hdrv->pwm_mode == 1 ? "3PWM" : "Other");
    printf("[DRV8311-%d] PWM Frequency: %d Hz\r\n", hdrv->device_id, hdrv->pwm_frequency);

    return status;
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
  * @brief  Clear fault flags
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ClearFaults(DRV8311_HandleTypeDef *hdrv)
{
    uint8_t ctrl_reg = DRV8311_CTRL_CLR_FLT;
    HAL_StatusTypeDef status;

    status = DRV8311_WriteRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, ctrl_reg);
    HAL_Delay(5);

    // Clear the flag
    ctrl_reg = 0x00;
    status = DRV8311_WriteRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, ctrl_reg);

    return status;
}

/**
  * @brief  Write to DRV8311 register (8-bit format for basic registers 0x00-0x06)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  reg_addr: Register address
  * @param  value: 8-bit value to write
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_WriteRegister(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint8_t value)
{
    uint8_t tx_data[4] = {0};
    uint8_t rx_data[4] = {0};
    uint8_t dev_addr = 0x00;

    // tSPI frame format for 8-bit data (32-bit frame):
    // Bits 31-30: Device Address
    // Bit 29: R/W (0=Write)
    // Bits 28-22: Register Address (7 bits)
    // Bits 21-14: Data (8 bits)
    // Bit 13: Parity
    // Bits 12-0: Reserved (0)

    uint32_t frame = 0;
    frame |= ((uint32_t)(dev_addr & 0x03) << 30);
    frame |= (0UL << 29);  // Write
    frame |= ((uint32_t)(reg_addr & 0x7F) << 22);
    frame |= ((uint32_t)value << 14);  // 8-bit data at bits 21-14

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;

    // Add parity at bit 13 for 8-bit data
    add_tspi_parity_8bit(tx_data);

    return DRV8311_SPITransfer(hdrv, tx_data, rx_data, 4);
}

/**
  * @brief  Read from DRV8311 register
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  reg_addr: Register address (0x00 - 0x06)
  * @param  value: Pointer to store read value
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ReadRegister(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint8_t *value)
{
    uint8_t tx_data[4] = {0};
    uint8_t rx_data[4] = {0};
    HAL_StatusTypeDef status;
    uint8_t dev_addr = 0x00;  // AD0=0, AD1=0

    // tSPI frame format (32-bit): Read command
    // Bits 31-30: Device Address
    // Bit 29: R/W (1=Read)
    // Bits 28-22: Register Address
    // Bits 21-14: Data (0x00 for read)
    // Bit 13: Parity
    // Bits 12-0: Reserved

    uint32_t frame = 0;
    frame |= ((uint32_t)(dev_addr & 0x03) << 30);  // Device address
    frame |= (1UL << 29);                           // R=1 for read
    frame |= ((uint32_t)(reg_addr & 0x7F) << 22);  // Register address
    frame |= (0UL << 14);                           // Data = 0 for read

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;

    add_tspi_parity_8bit(tx_data);

    // Send read command
    status = DRV8311_SPITransfer(hdrv, tx_data, rx_data, 4);
    if (status != HAL_OK) {
        return status;
    }

    // tSPI returns data on NEXT transaction
    // Send NOP to get the actual read result
    tx_data[0] = 0x00;
    tx_data[1] = 0x00;
    tx_data[2] = 0x00;
    tx_data[3] = 0x00;

    add_tspi_parity_8bit(tx_data);

    status = DRV8311_SPITransfer(hdrv, tx_data, rx_data, 4);
    if (status == HAL_OK) {
        // tSPI Response Format Analysis:
        // RX: [0xFF][STATUS][DATA_HIGH][DATA_LOW]
        // Byte 0: 0xFF (always)
        // Byte 1: Previous fault status (0x81)
        // Byte 2-3: Actual register data

        uint32_t rx_frame = ((uint32_t)rx_data[0] << 24) |
                            ((uint32_t)rx_data[1] << 16) |
                            ((uint32_t)rx_data[2] << 8) |
                            (rx_data[3]);

        // Extract data from Byte 2 (bits 15-8 of the frame)
        *value = rx_data[2];

        printf("[DEBUG] RX Frame: 0x%08lX, Byte2=0x%02X, Byte3=0x%02X, Extracted=0x%02X\r\n",
               rx_frame, rx_data[2], rx_data[3], *value);
    }

    return status;
}

/**
  * @brief  Set PWM mode
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  mode: 0=6PWM, 1=3PWM, 2=1PWM
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_SetPWMMode(DRV8311_HandleTypeDef *hdrv, uint8_t mode)
{
    uint8_t ctrl_reg = 0;

    if (mode > 2) {
        return HAL_ERROR;
    }

    ctrl_reg = (mode << 4);  // PWM_MODE bits [5:4]
    hdrv->pwm_mode = mode;

    return DRV8311_WriteRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, ctrl_reg);
}

/**
  * @brief  Set motor direction
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  direction: 0=CW, 1=CCW
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_SetDirection(DRV8311_HandleTypeDef *hdrv, uint8_t direction)
{
    uint8_t ctrl_reg;
    HAL_StatusTypeDef status;

    hdrv->direction = direction ? 1 : 0;

    // Read current control register
    status = DRV8311_ReadRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, &ctrl_reg);
    if (status != HAL_OK) {
        return status;
    }

    // Modify direction bit
    if (hdrv->direction) {
        ctrl_reg |= DRV8311_CTRL_PWM_DIR;
    } else {
        ctrl_reg &= ~DRV8311_CTRL_PWM_DIR;
    }

    return DRV8311_WriteRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, ctrl_reg);
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
  * @brief  Brake motor (short all phases)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Brake(DRV8311_HandleTypeDef *hdrv)
{
    uint8_t ctrl_reg;
    HAL_StatusTypeDef status;

    status = DRV8311_ReadRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, &ctrl_reg);
    if (status != HAL_OK) {
        return status;
    }

    ctrl_reg |= DRV8311_CTRL_BRAKE;
    status = DRV8311_WriteRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, ctrl_reg);

    printf("[DRV8311] Brake applied\r\n");

    return status;
}

/**
  * @brief  Coast motor (high impedance)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_Coast(DRV8311_HandleTypeDef *hdrv)
{
    uint8_t ctrl_reg;
    HAL_StatusTypeDef status;

    status = DRV8311_ReadRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, &ctrl_reg);
    if (status != HAL_OK) {
        return status;
    }

    ctrl_reg |= DRV8311_CTRL_COAST;
    status = DRV8311_WriteRegister(hdrv, DRV8311_REG_DRIVER_CONTROL, ctrl_reg);

    printf("[DRV8311] Coast mode\r\n");

    return status;
}

/**
  * @brief  Read fault status
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef DRV8311_ReadFaultStatus(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    status = DRV8311_ReadRegister(hdrv, DRV8311_REG_FAULT_STATUS1, &hdrv->fault_status1);
    if (status != HAL_OK) {
        return status;
    }

    status = DRV8311_ReadRegister(hdrv, DRV8311_REG_FAULT_STATUS2, &hdrv->fault_status2);

    return status;
}

/**
  * @brief  Check if fault occurred
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval 1 if fault, 0 if no fault
  */
uint8_t DRV8311_IsFault(DRV8311_HandleTypeDef *hdrv)
{
    DRV8311_ReadFaultStatus(hdrv);
    return (hdrv->fault_status1 & DRV8311_FAULT1_FAULT) ? 1 : 0;
}

/**
  * @brief  Print fault status to console
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval None
  */
void DRV8311_PrintFaultStatus(DRV8311_HandleTypeDef *hdrv)
{
    printf("\r\n[DRV8311] Fault Status:\r\n");
    printf("  Status1: 0x%02X\r\n", hdrv->fault_status1);

    if (hdrv->fault_status1 & DRV8311_FAULT1_VDS_OCP) {
        printf("  - VDS Overcurrent\r\n");
    }
    if (hdrv->fault_status1 & DRV8311_FAULT1_GDF) {
        printf("  - Gate Drive Fault\r\n");
    }
    if (hdrv->fault_status1 & DRV8311_FAULT1_UVLO) {
        printf("  - Undervoltage Lockout\r\n");
    }
    if (hdrv->fault_status1 & DRV8311_FAULT1_OTSD) {
        printf("  - Overtemperature Shutdown\r\n");
    }
    if (hdrv->fault_status1 & DRV8311_FAULT1_VCP_UV) {
        printf("  - Charge Pump Undervoltage\r\n");
    }
    if (hdrv->fault_status1 & DRV8311_FAULT1_OCP) {
        printf("  - Overcurrent Protection\r\n");
    }
    if (hdrv->fault_status1 & DRV8311_FAULT1_SPI_FLT) {
        printf("  - SPI Fault\r\n");
    }

    if (hdrv->fault_status1 == 0) {
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
  * @brief  Write 16-bit register (for tSPI PWM registers)
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @param  reg_addr: Register address
  * @param  value: 16-bit value to write (bits 15-0, bit 15 will be parity)
  * @retval HAL status
  */
static HAL_StatusTypeDef DRV8311_WriteRegister16(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint16_t value)
{
    uint8_t tx_data[4] = {0};
    uint8_t rx_data[4] = {0};
    uint8_t dev_addr = 0x00;

    // tSPI frame format for 16-bit data (32-bit frame):
    // Bits 31-30: Device Address
    // Bit 29: R/W (0=Write)
    // Bits 28-22: Register Address (7 bits)
    // Bits 21-6: Data (16 bits) ← Extended for 16-bit registers
    // Bit 5: Parity
    // Bits 4-0: Reserved (0)

    uint32_t frame = 0;
    frame |= ((uint32_t)(dev_addr & 0x03) << 30);  // Device address bits 31-30
    frame |= (0UL << 29);                           // W=0 for write
    frame |= ((uint32_t)(reg_addr & 0x7F) << 22);  // Register address bits 28-22
    frame |= ((uint32_t)(value & 0xFFFF) << 6);    // 16-bit data bits 21-6
    // Parity bit 5 will be set by add_tspi_parity
    // Reserved bits 4-0 are 0

    tx_data[0] = (frame >> 24) & 0xFF;
    tx_data[1] = (frame >> 16) & 0xFF;
    tx_data[2] = (frame >> 8) & 0xFF;
    tx_data[3] = frame & 0xFF;

    // Add parity to the tSPI frame (16-bit format)
    add_tspi_parity_16bit(tx_data);

    return DRV8311_SPITransfer(hdrv, tx_data, rx_data, 4);
}

/**
  * @brief  Unlock registers for writing
  * @param  hdrv: Pointer to DRV8311 handle structure
  * @retval HAL status
  */
static HAL_StatusTypeDef DRV8311_UnlockRegisters(DRV8311_HandleTypeDef *hdrv)
{
    HAL_StatusTypeDef status;

    // Write to SYS_CTRL (0x3F) with WRITE_KEY=0x5 and REG_LOCK=0
    // Value: (0x5 << 12) | (0 << 7) = 0x5000
    status = DRV8311_WriteRegister16(hdrv, DRV8311_REG_SYS_CTRL, 0x5000);
    if (status != HAL_OK) {
        printf("[ERROR] Failed to unlock registers\r\n");
        return status;
    }

    printf("[DRV8311-%d] Registers unlocked\r\n", hdrv->device_id);
    HAL_Delay(5);
    return HAL_OK;
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