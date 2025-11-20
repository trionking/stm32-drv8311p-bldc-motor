/**
  ******************************************************************************
  * @file           : ads8638.c
  * @brief          : ADS8638 12-bit 8-channel SAR ADC driver implementation
  ******************************************************************************
  */

#include "ads8638.h"
#include <string.h>

/* Private function prototypes */
// ADS8638_SendCommand is now public (declared in ads8638.h)

/**
  * @brief  Initialize ADS8638 ADC
  * @param  hadc: Pointer to ADS8638 handle structure
  * @param  hspi: Pointer to SPI handle
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_Init(ADS8638_HandleTypeDef *hadc, SPI_HandleTypeDef *hspi)
{
    HAL_StatusTypeDef status;

    if (hadc == NULL || hspi == NULL) {
        return HAL_ERROR;
    }

    hadc->hspi = hspi;

    // Enhanced power-up sequence for ADS8638
    // Step 0: Enable AL_PD (Analog Power-Down) - CRITICAL!
    // AL_PD must be HIGH for normal operation
    ADS8638_ALPD_ENABLE();
    HAL_Delay(50);  // Wait for analog power-up

    // Step 1: Ensure CS is HIGH during power-up (critical!)
    ADS8638_CS_HIGH();
    HAL_Delay(200);  // Extended power stabilization time

    // Step 2: Hardware reset by CS toggling (slow and deliberate)
    uint16_t response;
    for (int i = 0; i < 8; i++) {
        ADS8638_CS_LOW();
        HAL_Delay(20);
        ADS8638_CS_HIGH();
        HAL_Delay(20);
    }

    HAL_Delay(100);  // Additional stabilization

    // Step 3: Software reset sequence
    for (int i = 0; i < 16; i++) {
        status = ADS8638_SendCommand(hadc, ADS8638_CMD_RST, &response);
        HAL_Delay(15);  // Longer delay between resets
    }

    HAL_Delay(100);  // Wait for reset to complete

    // Step 4: Wake up from power-down with NOP commands
    for (int i = 0; i < 10; i++) {
        ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
        HAL_Delay(10);
    }

    // Step 5: Configure Feature Select Register
    // CRITICAL: Enable internal reference (INTREF_DIS=0)
    for (int i = 0; i < 8; i++) {
        ADS8638_WriteRegister(hadc, ADS8638_REG_FEATURE_SEL, 0x00);  // Internal REF enabled
        HAL_Delay(20);
        ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
        HAL_Delay(10);
    }

    // Step 6: Configure Auto-Sequence mode
    // Retry multiple times to ensure register write succeeds
    for (int i = 0; i < 8; i++) {
        ADS8638_WriteRegister(hadc, ADS8638_REG_AUTO_SEQ_EN, 0xFF);  // Enable all channels
        HAL_Delay(20);
        ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
        HAL_Delay(10);
    }

    // Step 7: Set default range configuration and write to registers
    for (uint8_t ch = 0; ch < 8; ch++) {
        hadc->range_config[ch] = ADS8638_RANGE_3xVREF;  // 7.5V max (for HVDD=5V)
        hadc->adc_data[ch] = 0;
        hadc->voltage[ch] = 0.0f;

        // CRITICAL: Actually write range to ADS8638 registers!
        ADS8638_WriteRegister(hadc, ADS8638_REG_CH0_RANGE + ch, ADS8638_RANGE_3xVREF);
        HAL_Delay(10);
    }

    // Step 8: Prime the Auto-Scan sequence with NOP commands
    for (int i = 0; i < 32; i++) {
        ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
        HAL_Delay(5);
    }

    return HAL_OK;
}

/**
  * @brief  Reset ADS8638
  * @param  hadc: Pointer to ADS8638 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_Reset(ADS8638_HandleTypeDef *hadc)
{
    uint16_t response;
    return ADS8638_SendCommand(hadc, ADS8638_CMD_RST, &response);
}

/**
  * @brief  Write to ADS8638 register using Program Register command
  * @param  hadc: Pointer to ADS8638 handle structure
  * @param  reg_addr: Register address
  * @param  value: Value to write
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_WriteRegister(ADS8638_HandleTypeDef *hadc, uint8_t reg_addr, uint8_t value)
{
    HAL_StatusTypeDef status;
    uint16_t cmd;
    uint16_t response;

    // Use Program Register command: 0xD000 | (addr << 8) | data
    cmd = ADS8638_PROG_REG(reg_addr, value);

    // Send the program register command
    status = ADS8638_SendCommand(hadc, cmd, &response);

    // CRITICAL: Send NOP after Program Register command
    // The register is actually written during the NEXT SPI transaction
    ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);

    return status;
}

/**
  * @brief  Read from ADS8638 register using Read Hword command
  * @param  hadc: Pointer to ADS8638 handle structure
  * @param  reg_addr: Register address
  * @param  value: Pointer to store read value
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_ReadRegister(ADS8638_HandleTypeDef *hadc, uint8_t reg_addr, uint8_t *value)
{
    HAL_StatusTypeDef status;
    uint16_t cmd;
    uint16_t response;

    // Use Read Register command: 0xC800 | (addr << 7)
    cmd = ADS8638_READ_REG(reg_addr);

    // First: Send read register command
    status = ADS8638_SendCommand(hadc, cmd, &response);
    if (status != HAL_OK) {
        return status;
    }

    // Second: Send NOP to get the register data
    status = ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);

    if (status == HAL_OK) {
        // Register data is in lower 8 bits
        *value = response & 0xFF;
    }

    return status;
}

/**
  * @brief  Set channel input range
  * @param  hadc: Pointer to ADS8638 handle structure
  * @param  channel: Channel number (0-7)
  * @param  range: Range setting (see ADS8638_RANGE_xxx defines)
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_SetChannelRange(ADS8638_HandleTypeDef *hadc, uint8_t channel, uint8_t range)
{
    HAL_StatusTypeDef status;

    if (channel > 7) {
        return HAL_ERROR;
    }

    // Write to channel range register
    status = ADS8638_WriteRegister(hadc, ADS8638_REG_CH0_RANGE + channel, range);

    if (status == HAL_OK) {
        hadc->range_config[channel] = range;
    }

    return status;
}

/**
  * @brief  Read single channel ADC value
  * @param  hadc: Pointer to ADS8638 handle structure
  * @param  channel: Channel number (0-7)
  * @param  adc_value: Pointer to store 12-bit ADC value
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_ReadChannel(ADS8638_HandleTypeDef *hadc, uint8_t channel, uint16_t *adc_value)
{
    HAL_StatusTypeDef status;
    uint16_t cmd;
    uint16_t response;

    if (channel > 7) {
        return HAL_ERROR;
    }

    // Select channel using manual channel selection command
    cmd = ADS8638_CMD_MAN_CH0 + (channel * 0x0400);

    // Step 1: Send channel select command (returns previous channel data)
    status = ADS8638_SendCommand(hadc, cmd, &response);
    if (status != HAL_OK) {
        return status;
    }

    // Step 2: Send same channel command to start conversion
    status = ADS8638_SendCommand(hadc, cmd, &response);
    if (status != HAL_OK) {
        return status;
    }

    // Step 3: Send NOP to get the selected channel result
    status = ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
    if (status != HAL_OK) {
        return status;
    }

    // Extract 12-bit ADC value (bits 11-0)
    *adc_value = response & 0x0FFF;
    hadc->adc_data[channel] = *adc_value;
    hadc->voltage[channel] = ADS8638_ConvertToVoltage(*adc_value, hadc->range_config[channel]);

    return HAL_OK;
}

/**
  * @brief  Read all channels in Auto-Scan mode
  * @param  hadc: Pointer to ADS8638 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_ReadAllChannels_AutoScan(ADS8638_HandleTypeDef *hadc)
{
    HAL_StatusTypeDef status;
    uint16_t response;
    uint16_t raw_responses[8];

    // In Auto-Scan mode, device sends channels in sequence
    // Each NOP returns the next channel in sequence: CH0, CH1, CH2, ..., CH7
    // We need to read 8 times to get all channels
    for (uint8_t ch = 0; ch < 8; ch++) {
        status = ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
        if (status != HAL_OK) {
            return status;
        }

        raw_responses[ch] = response;

        // Extract ADC data (lower 12 bits)
        uint16_t adc_value = response & 0x0FFF;

        // Store in sequential channel order
        hadc->adc_data[ch] = adc_value;
        hadc->voltage[ch] = ADS8638_ConvertToVoltage(adc_value, hadc->range_config[ch]);
    }

    // Debug: Store first raw response for inspection
    // You can access raw_responses[0] to see full 16-bit data
    (void)raw_responses; // Prevent unused variable warning

    return HAL_OK;
}

/**
  * @brief  Read all channels in sequence (Manual mode)
  * @param  hadc: Pointer to ADS8638 handle structure
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_ReadAllChannels(ADS8638_HandleTypeDef *hadc)
{
    HAL_StatusTypeDef status;

    for (uint8_t ch = 0; ch < 8; ch++) {
        status = ADS8638_ReadChannel(hadc, ch, &hadc->adc_data[ch]);
        if (status != HAL_OK) {
            return status;
        }
    }

    return HAL_OK;
}

/**
  * @brief  Convert ADC raw value to voltage
  * @param  adc_value: 12-bit ADC value
  * @param  range_config: Range configuration for the channel
  * @retval Voltage in volts
  */
float ADS8638_ConvertToVoltage(uint16_t adc_value, uint8_t range_config)
{
    float vref = 2.5f;  // Internal reference voltage
    float range_multiplier;

    // Determine range multiplier
    switch (range_config) {
        case ADS8638_RANGE_3xVREF:
            range_multiplier = 3.0f;
            break;
        case ADS8638_RANGE_2p5xVREF:
            range_multiplier = 2.5f;
            break;
        case ADS8638_RANGE_1p5xVREF:
            range_multiplier = 1.5f;
            break;
        case ADS8638_RANGE_1p25xVREF:
            range_multiplier = 1.25f;
            break;
        case ADS8638_RANGE_0p625xVREF:
            range_multiplier = 0.625f;
            break;
        default:
            range_multiplier = 1.5f;
            break;
    }

    // Calculate voltage: ADC_value / 4096 * (range_multiplier * Vref)
    return ((float)adc_value / 4096.0f) * (range_multiplier * vref);
}

/**
  * @brief  Send command to ADS8638 (16-bit command)
  * @param  hadc: Pointer to ADS8638 handle structure
  * @param  cmd: 16-bit command
  * @param  response: Pointer to store 16-bit response
  * @retval HAL status
  */
HAL_StatusTypeDef ADS8638_SendCommand(ADS8638_HandleTypeDef *hadc, uint16_t cmd, uint16_t *response)
{
    HAL_StatusTypeDef status;
    uint8_t tx_data[2];
    uint8_t rx_data[2];

    // Convert 16-bit command to bytes (MSB first)
    tx_data[0] = (cmd >> 8) & 0xFF;
    tx_data[1] = cmd & 0xFF;

    // Initialize rx_data
    rx_data[0] = 0x00;
    rx_data[1] = 0x00;

    // Ensure CS is HIGH before transaction (ADS8638 requirement)
    ADS8638_CS_HIGH();
    // No delay needed - just ensure CS is high

    ADS8638_CS_LOW();
    // No delay - start SPI immediately after CS low

    status = HAL_SPI_TransmitReceive(hadc->hspi, tx_data, rx_data, 2, 100);

    // No delay - CS can go high immediately after transmission
    ADS8638_CS_HIGH();

    // Small delay between commands for device recovery (ADS8638 needs time between transactions)
    for(volatile int i = 0; i < 1000; i++);  // ~10us delay at 480MHz

    if (status == HAL_OK && response != NULL) {
        *response = ((uint16_t)rx_data[0] << 8) | rx_data[1];
    }

    return status;
}
