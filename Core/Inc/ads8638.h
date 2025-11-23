/**
  ******************************************************************************
  * @file           : ads8638.h
  * @brief          : Header for ads8638.c file.
  *                   ADS8638 12-bit 8-channel SAR ADC driver
  ******************************************************************************
  */

#ifndef __ADS8638_H
#define __ADS8638_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdint.h>

/* ADS8638 Command Definitions - NO_OP keeps device in current mode */
#define ADS8638_CMD_NO_OP               0x0000
#define ADS8638_CMD_RST                 0x8500  // Software reset (legacy, use WriteRegister to 0x01 instead)

/* Manual Channel Select Commands (for ReadChannel function) */
#define ADS8638_CMD_MAN_CH0             0xC000
#define ADS8638_CMD_MAN_CH1             0xC400
#define ADS8638_CMD_MAN_CH2             0xC800
#define ADS8638_CMD_MAN_CH3             0xCC00
#define ADS8638_CMD_MAN_CH4             0xD000
#define ADS8638_CMD_MAN_CH5             0xD400
#define ADS8638_CMD_MAN_CH6             0xD800
#define ADS8638_CMD_MAN_CH7             0xDC00

/* ADS8638 Register Addresses (Page 0) - Per Datasheet Table 11 */
#define ADS8638_REG_RESET_DEVICE        0x01  // Device Reset Register
#define ADS8638_REG_MANUAL_MODE         0x04  // Manual Channel Select Mode
#define ADS8638_REG_AUTO_MODE           0x05  // Auto-Scan Mode
#define ADS8638_REG_AUX_CONFIG          0x06  // Auxiliary Config (VREF, Temp Sensor, AL_PD)
#define ADS8638_REG_AUTO_CH_SEL         0x0C  // Auto-Mode Channel Selection
#define ADS8638_REG_CH0_1_RANGE         0x10  // Channel 0-1 Range (CH0: bits[6:4], CH1: bits[2:0])
#define ADS8638_REG_CH2_3_RANGE         0x11  // Channel 2-3 Range (CH2: bits[6:4], CH3: bits[2:0])
#define ADS8638_REG_CH4_5_RANGE         0x12  // Channel 4-5 Range (CH4: bits[6:4], CH5: bits[2:0])
#define ADS8638_REG_CH6_7_RANGE         0x13  // Channel 6-7 Range (CH6: bits[6:4], CH7: bits[2:0])

/* Legacy register names for backwards compatibility with test code */
#define ADS8638_REG_FEATURE_SEL         ADS8638_REG_AUX_CONFIG    // Alias: Feature Select -> Aux Config
#define ADS8638_REG_AUTO_SEQ_EN         ADS8638_REG_AUTO_CH_SEL   // Alias: Auto Seq Enable -> Auto Ch Sel

/* Program Register Command - Bit pattern: Bits[15:9]=Address, Bit[8]=R/W, Bits[7:0]=Data */
#define ADS8638_PROG_REG(addr, data)    ((((addr) & 0x7F) << 9) | (0x00 << 8) | ((data) & 0xFF))

/* Read Register Command - Bit pattern: Bits[15:9]=Address, Bit[8]=R/W */
#define ADS8638_READ_REG(addr)          ((((addr) & 0x7F) << 9) | (0x01 << 8))

/* Input Range Settings - Per Datasheet Register Definitions */
/* Range Select[2:0] - Used in Manual/Auto mode registers and Ch Range registers */
#define ADS8638_RANGE_AS_PROGRAMMED     0x00  // Use range from configuration registers (0x10-0x13)
#define ADS8638_RANGE_BIPOLAR_10V       0x01  // ± 10V (requires 2.5V VREF)
#define ADS8638_RANGE_BIPOLAR_5V        0x02  // ± 5V
#define ADS8638_RANGE_BIPOLAR_2P5V      0x03  // ± 2.5V
// 0x04 Reserved
#define ADS8638_RANGE_UNIPOLAR_10V      0x05  // 0 to 10V
#define ADS8638_RANGE_UNIPOLAR_5V       0x06  // 0 to 5V
#define ADS8638_RANGE_POWERDOWN         0x07  // Powers down device

/* Aux-Config Register (0x06) Bit Definitions */
#define ADS8638_AUX_AL_PD_AS_ALARM      0x00  // AL_PD pin = Alarm output
#define ADS8638_AUX_AL_PD_AS_PWRDN      0x08  // AL_PD pin = Power-down control (Bit 3)
#define ADS8638_AUX_INT_VREF_ENABLE     0x04  // Enable internal 2.5V reference (Bit 2)
#define ADS8638_AUX_TEMP_SENSOR_ENABLE  0x02  // Enable temperature sensor (Bit 1)

/* Manual/Auto Mode Register - Channel Select (bits[6:4] for Manual mode) */
#define ADS8638_CH_SELECT(ch)           (((ch) & 0x07) << 4)  // Channel 0-7
#define ADS8638_SEL_TEMP_SENSOR         0x01  // Select temperature sensor (Bit 0)

/* GPIO Pin Definitions */
#define ADS8638_CS_PIN          GPIO_PIN_1   // PD1 -> SPI4_NCS
#define ADS8638_CS_PORT         GPIOD

/* Macro for CS control */
#define ADS8638_CS_LOW()        HAL_GPIO_WritePin(ADS8638_CS_PORT, ADS8638_CS_PIN, GPIO_PIN_RESET)
#define ADS8638_CS_HIGH()       HAL_GPIO_WritePin(ADS8638_CS_PORT, ADS8638_CS_PIN, GPIO_PIN_SET)

/* ADS8638 Structure */
typedef struct {
    SPI_HandleTypeDef *hspi;
    uint16_t adc_data[8];       // ADC raw data for 8 channels
    float voltage[8];           // Converted voltage values
    uint8_t range_config[8];    // Range configuration for each channel
} ADS8638_HandleTypeDef;

/* Function Prototypes */
HAL_StatusTypeDef ADS8638_Init(ADS8638_HandleTypeDef *hadc, SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef ADS8638_Reset(ADS8638_HandleTypeDef *hadc);
HAL_StatusTypeDef ADS8638_SendCommand(ADS8638_HandleTypeDef *hadc, uint16_t cmd, uint16_t *response);
HAL_StatusTypeDef ADS8638_WriteRegister(ADS8638_HandleTypeDef *hadc, uint8_t reg_addr, uint8_t value);
HAL_StatusTypeDef ADS8638_ReadRegister(ADS8638_HandleTypeDef *hadc, uint8_t reg_addr, uint8_t *value);
HAL_StatusTypeDef ADS8638_SetChannelRange(ADS8638_HandleTypeDef *hadc, uint8_t channel, uint8_t range);
HAL_StatusTypeDef ADS8638_ReadChannel(ADS8638_HandleTypeDef *hadc, uint8_t channel, uint16_t *adc_value);
HAL_StatusTypeDef ADS8638_ReadAllChannels(ADS8638_HandleTypeDef *hadc);
HAL_StatusTypeDef ADS8638_ReadAllChannels_AutoScan(ADS8638_HandleTypeDef *hadc);
float ADS8638_ConvertToVoltage(uint16_t adc_value, uint8_t range_config);

/* Diagnostic Functions */
void ADS8638_DiagnosticTest(ADS8638_HandleTypeDef *hadc);
uint8_t ADS8638_CheckCommunication(ADS8638_HandleTypeDef *hadc);

#ifdef __cplusplus
}
#endif

#endif /* __ADS8638_H */
