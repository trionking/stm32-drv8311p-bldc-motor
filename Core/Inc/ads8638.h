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

/* ADS8638 Command Definitions */
#define ADS8638_CMD_NO_OP               0x0000
#define ADS8638_CMD_STDBY               0x8200
#define ADS8638_CMD_PWR_DN              0x8300
#define ADS8638_CMD_RST                 0x8500
#define ADS8638_CMD_AUTO_RST            0xA000
#define ADS8638_CMD_MAN_CH0             0xC000
#define ADS8638_CMD_MAN_CH1             0xC400
#define ADS8638_CMD_MAN_CH2             0xC800
#define ADS8638_CMD_MAN_CH3             0xCC00
#define ADS8638_CMD_MAN_CH4             0xD000
#define ADS8638_CMD_MAN_CH5             0xD400
#define ADS8638_CMD_MAN_CH6             0xD800
#define ADS8638_CMD_MAN_CH7             0xDC00
#define ADS8638_CMD_MAN_AUX             0xE000

/* Program Register Command - Bit pattern: 1101 AAAAAA DDDDDDDD (16 bits) */
/*   Bit 15-14: 11 (Write command)
     Bit 13-12: 01 (Program Register)
     Bit 11-8:  Address high nibble (upper 4 bits of 6-bit address)
     Bit 7-0:   Data byte */
#define ADS8638_PROG_REG(addr, data)    (0xD000 | (((addr) & 0x3F) << 8) | ((data) & 0xFF))

/* Read Register Command - Bit pattern: 11 00 1 A5-A0 X */
#define ADS8638_READ_REG(addr)          (0xC800 | (((addr) & 0x3F) << 7))

/* ADS8638 Register Addresses */
#define ADS8638_REG_AUTO_SEQ_EN         0x01  // Auto Sequence Enable
#define ADS8638_REG_CH_PWR_DN           0x02  // Channel Power Down
#define ADS8638_REG_FEATURE_SEL         0x03  // Feature Select
#define ADS8638_REG_CH0_RANGE           0x05  // Channel 0 Input Range
#define ADS8638_REG_CH1_RANGE           0x06  // Channel 1 Input Range
#define ADS8638_REG_CH2_RANGE           0x07  // Channel 2 Input Range
#define ADS8638_REG_CH3_RANGE           0x08  // Channel 3 Input Range
#define ADS8638_REG_CH4_RANGE           0x09  // Channel 4 Input Range
#define ADS8638_REG_CH5_RANGE           0x0A  // Channel 5 Input Range
#define ADS8638_REG_CH6_RANGE           0x0B  // Channel 6 Input Range
#define ADS8638_REG_CH7_RANGE           0x0C  // Channel 7 Input Range

/* Input Range Settings (for 2.5V internal reference) */
#define ADS8638_RANGE_3xVREF    0x00  // 0 to 7.5V (3 x 2.5V)
#define ADS8638_RANGE_2p5xVREF  0x01  // 0 to 6.25V (2.5 x 2.5V)
#define ADS8638_RANGE_1p5xVREF  0x02  // 0 to 3.75V (1.5 x 2.5V)
#define ADS8638_RANGE_1p25xVREF 0x03  // 0 to 3.125V (1.25 x 2.5V)
#define ADS8638_RANGE_0p625xVREF 0x05 // 0 to 1.5625V (0.625 x 2.5V)

/* GPIO Pin Definitions */
#define ADS8638_CS_PIN          GPIO_PIN_1   // PD1 -> SPI4_NCS
#define ADS8638_CS_PORT         GPIOD
#define ADS8638_ALPD_PIN        GPIO_PIN_9   // PC9 -> AL_PD (Analog Power-Down)
#define ADS8638_ALPD_PORT       GPIOC

/* Macro for CS control */
#define ADS8638_CS_LOW()        HAL_GPIO_WritePin(ADS8638_CS_PORT, ADS8638_CS_PIN, GPIO_PIN_RESET)
#define ADS8638_CS_HIGH()       HAL_GPIO_WritePin(ADS8638_CS_PORT, ADS8638_CS_PIN, GPIO_PIN_SET)

/* Macro for AL_PD control */
#define ADS8638_ALPD_ENABLE()   HAL_GPIO_WritePin(ADS8638_ALPD_PORT, ADS8638_ALPD_PIN, GPIO_PIN_SET)
#define ADS8638_ALPD_DISABLE()  HAL_GPIO_WritePin(ADS8638_ALPD_PORT, ADS8638_ALPD_PIN, GPIO_PIN_RESET)

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
