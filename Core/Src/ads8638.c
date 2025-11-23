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
    if (hadc == NULL || hspi == NULL) {
        return HAL_ERROR;
    }

    hadc->hspi = hspi;

    // Simplified power-up sequence per datasheet
    // Note: AL_PD pin has internal weak pull-up to DVDD (can be left floating)

    // Step 1: Ensure CS is HIGH during power-up (critical!)
    ADS8638_CS_HIGH();
    HAL_Delay(10);  // Power stabilization

    // Step 2: Send first dummy transaction to initiate power-up
    // Per datasheet: "Power-up delay from first CS after power-up command: 1µs"
    uint16_t response;
    ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
    HAL_Delay(1);  // Wait for device to power up

    // Step 3: Software reset via register write (per datasheet Table 11)
    // Reset-Device Register (0x01), write 0x01 to reset
    ADS8638_WriteRegister(hadc, ADS8638_REG_RESET_DEVICE, 0x01);
    HAL_Delay(10);  // Wait for reset to complete

    // Step 4: Send NOP to clear any invalid data
    ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
    HAL_Delay(1);

    // Step 5: Configure Aux-Config Register (0x06)
    // CRITICAL:
    // - Bit 3 = 1: AL_PD as power-down control input (default, can float with internal pull-up)
    // - Bit 2 = 1: Enable internal 2.5V reference
    // - Bit 1 = 0: Temp Sensor disabled
    // NOTE: AL_PD pin has internal weak pull-up to DVDD, can be left floating
    // Register default = 0x08 (AL_PD control enabled), we add VREF enable
    uint8_t aux_config = ADS8638_AUX_AL_PD_AS_PWRDN | ADS8638_AUX_INT_VREF_ENABLE;  // 0x08 | 0x04 = 0x0C
    ADS8638_WriteRegister(hadc, ADS8638_REG_AUX_CONFIG, aux_config);

    // Per datasheet: "Internal reference block is powered up at the NEXT frame"
    // Send a dummy transaction to trigger the next frame
    ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);

    // Wait for internal reference to settle (datasheet: 9ms with 10µF cap)
    HAL_Delay(15);  // Settling time for internal reference

    // Step 6: Configure Auto-Mode Channel Selection (0x0C)
    // Enable all 8 channels for auto-scan sequence
    // Bit 7-0: Sel Ch7, Ch6, Ch5, Ch4, Ch3, Ch2, Ch1, Ch0
    ADS8638_WriteRegister(hadc, ADS8638_REG_AUTO_CH_SEL, 0xFF);  // All channels enabled
    HAL_Delay(1);

    // Step 7: Set default range configuration
    // Range registers: 2 channels per register (0x10-0x13)
    // IMPORTANT: With HVDD=5V, use 0-5V range (not 0-10V which requires HVDD=10-15V!)
    for (uint8_t ch = 0; ch < 8; ch++) {
        hadc->range_config[ch] = ADS8638_RANGE_UNIPOLAR_5V;  // 0-5V (for HVDD=5V)
        hadc->adc_data[ch] = 0;
        hadc->voltage[ch] = 0.0f;
    }

    // Write range to registers (CH0-1: 0x10, CH2-3: 0x11, CH4-5: 0x12, CH6-7: 0x13)
    // Each register: bits[6:4] = even channel, bits[2:0] = odd channel
    uint8_t range_val = (ADS8638_RANGE_UNIPOLAR_5V << 4) | ADS8638_RANGE_UNIPOLAR_5V;
    for (uint8_t reg = 0; reg < 4; reg++) {
        ADS8638_WriteRegister(hadc, ADS8638_REG_CH0_1_RANGE + reg, range_val);
        HAL_Delay(1);
    }

    // Step 8: Prime the Auto-Scan sequence with a few NOP commands
    for (int i = 0; i < 8; i++) {
        ADS8638_SendCommand(hadc, ADS8638_CMD_NO_OP, &response);
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

    // Per datasheet Table 10: Read Cycle Command Word
    // DIN: bits[15:9]=address, bit[8]=1 (read), bits[7:0]=don't care
    // DOUT: bits[15:8]=don't care, bits[7:0]=register data (SAME FRAME!)
    cmd = ADS8638_READ_REG(reg_addr);

    // Send read register command - data returned in SAME frame bits[7:0]
    status = ADS8638_SendCommand(hadc, cmd, &response);

    if (status == HAL_OK) {
        // Register data is in lower 8 bits of the SAME frame response
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
  * @note   Range registers contain 2 channels each:
  *         - 0x10: CH0 (bits[6:4]), CH1 (bits[2:0])
  *         - 0x11: CH2 (bits[6:4]), CH3 (bits[2:0])
  *         - 0x12: CH4 (bits[6:4]), CH5 (bits[2:0])
  *         - 0x13: CH6 (bits[6:4]), CH7 (bits[2:0])
  */
HAL_StatusTypeDef ADS8638_SetChannelRange(ADS8638_HandleTypeDef *hadc, uint8_t channel, uint8_t range)
{
    HAL_StatusTypeDef status;

    if (channel > 7 || range > 7) {
        return HAL_ERROR;
    }

    // Update local configuration
    hadc->range_config[channel] = range;

    // Determine which register to write (CH0-1: 0x10, CH2-3: 0x11, etc.)
    uint8_t reg_addr = ADS8638_REG_CH0_1_RANGE + (channel / 2);

    // Get the pair channel number
    uint8_t pair_channel = (channel % 2 == 0) ? (channel + 1) : (channel - 1);
    uint8_t pair_range = hadc->range_config[pair_channel];

    // Construct register value
    // Even channel (0,2,4,6) goes to bits[6:4], Odd channel (1,3,5,7) to bits[2:0]
    uint8_t reg_value;
    if (channel % 2 == 0) {
        // Even channel: this channel in upper bits, pair in lower bits
        reg_value = (range << 4) | (pair_range & 0x07);
    } else {
        // Odd channel: pair in upper bits, this channel in lower bits
        reg_value = (pair_range << 4) | (range & 0x07);
    }

    // Write to register
    status = ADS8638_WriteRegister(hadc, reg_addr, reg_value);

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
  * @param  adc_value: 12-bit ADC value (0-4095)
  * @param  range_config: Range configuration for the channel
  * @retval Voltage in volts
  * @note   Per datasheet:
  *         - Bipolar ranges (±10V, ±5V, ±2.5V): 0=min, 2048=0V, 4095=max
  *         - Unipolar ranges (0-10V, 0-5V): 0=0V, 4095=max
  */
float ADS8638_ConvertToVoltage(uint16_t adc_value, uint8_t range_config)
{
    float voltage = 0.0f;

    // Mask to 12-bit value
    adc_value &= 0x0FFF;

    switch (range_config) {
        case ADS8638_RANGE_BIPOLAR_10V:  // ± 10V
            // ADC 0 = -10V, 2048 = 0V, 4095 = +10V
            voltage = ((float)adc_value / 4096.0f) * 20.0f - 10.0f;
            break;

        case ADS8638_RANGE_BIPOLAR_5V:   // ± 5V
            // ADC 0 = -5V, 2048 = 0V, 4095 = +5V
            voltage = ((float)adc_value / 4096.0f) * 10.0f - 5.0f;
            break;

        case ADS8638_RANGE_BIPOLAR_2P5V: // ± 2.5V
            // ADC 0 = -2.5V, 2048 = 0V, 4095 = +2.5V
            voltage = ((float)adc_value / 4096.0f) * 5.0f - 2.5f;
            break;

        case ADS8638_RANGE_UNIPOLAR_10V: // 0 to 10V
            // ADC 0 = 0V, 4095 = 10V
            voltage = ((float)adc_value / 4096.0f) * 10.0f;
            break;

        case ADS8638_RANGE_UNIPOLAR_5V:  // 0 to 5V
            // ADC 0 = 0V, 4095 = 5V
            voltage = ((float)adc_value / 4096.0f) * 5.0f;
            break;

        case ADS8638_RANGE_AS_PROGRAMMED:
        default:
            // Default to unipolar 0-10V if range is unknown
            voltage = ((float)adc_value / 4096.0f) * 10.0f;
            break;
    }

    return voltage;
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
