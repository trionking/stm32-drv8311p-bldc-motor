/**
  ******************************************************************************
  * @file           : drv8311.h
  * @brief          : Header for drv8311.c file.
  *                   DRV8311 BLDC Motor Driver
  ******************************************************************************
  * @attention
  *
  * DRV8311: 3-Phase BLDC Motor Gate Driver with Integrated Buck Regulator
  * - SPI Interface for configuration
  * - PWM_SYNC for synchronization
  * - Fault detection and status monitoring
  *
  ******************************************************************************
  */

#ifndef __DRV8311_H
#define __DRV8311_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include <stdint.h>

/* ============================================================================
 * DRV8311 SPI Register Map
 * ============================================================================ */

/* Register Addresses */
#define DRV8311_REG_DEV_STS1            0x00
#define DRV8311_REG_FAULT_STATUS1       0x00  // Alias for compatibility
#define DRV8311_REG_FAULT_STATUS2       0x01
#define DRV8311_REG_DRIVER_CONTROL      0x02
#define DRV8311_REG_GATE_DRIVE_HS       0x03
#define DRV8311_REG_GATE_DRIVE_LS       0x04
#define DRV8311_REG_OCP_CONTROL         0x05
#define DRV8311_REG_CSA_CONTROL         0x06

/* tSPI PWM Generation Registers */
#define DRV8311_REG_FLT_CLR             0x17
#define DRV8311_REG_PWMG_PERIOD         0x18
#define DRV8311_REG_PWMG_A_DUTY         0x19
#define DRV8311_REG_PWMG_B_DUTY         0x1A
#define DRV8311_REG_PWMG_C_DUTY         0x1B
#define DRV8311_REG_PWM_STATE           0x1C
#define DRV8311_REG_PWMG_CTRL           0x1D
#define DRV8311_REG_PWM_CTRL1           0x20
#define DRV8311_REG_DRV_CTRL            0x22
#define DRV8311_REG_CSA_CTRL_NEW        0x23
#define DRV8311_REG_SYS_CTRL            0x3F

/* SYS_CTRL Register (0x3F) bits */
#define DRV8311_SYS_CTRL_WRITE_KEY      (0x5 << 12)  // Write key = 0x5
#define DRV8311_SYS_CTRL_REG_LOCK       (1 << 7)      // Register lock bit
#define DRV8311_SYS_CTRL_UNLOCK         (DRV8311_SYS_CTRL_WRITE_KEY | 0x00)  // Unlock: KEY=5, LOCK=0

/* Fault Status 1 Register (0x00) - Read Only */
#define DRV8311_FAULT1_VDS_OCP          (1 << 0)
#define DRV8311_FAULT1_GDF              (1 << 1)
#define DRV8311_FAULT1_UVLO             (1 << 2)
#define DRV8311_FAULT1_OTSD             (1 << 3)
#define DRV8311_FAULT1_VCP_UV           (1 << 4)
#define DRV8311_FAULT1_OCP              (1 << 5)
#define DRV8311_FAULT1_SPI_FLT          (1 << 6)
#define DRV8311_FAULT1_FAULT            (1 << 7)

/* Driver Control Register (0x02) */
#define DRV8311_CTRL_CLR_FLT            (1 << 0)
#define DRV8311_CTRL_BRAKE              (1 << 1)
#define DRV8311_CTRL_COAST              (1 << 2)
#define DRV8311_CTRL_PWM_DIR            (1 << 3)
#define DRV8311_CTRL_PWM_MODE_MASK      (3 << 4)
#define DRV8311_CTRL_PWM_MODE_6PWM      (0 << 4)
#define DRV8311_CTRL_PWM_MODE_3PWM      (1 << 4)
#define DRV8311_CTRL_PWM_MODE_1PWM      (2 << 4)

/* Gate Drive HS Register (0x03) */
#define DRV8311_GATE_HS_IDRIVEP_MASK    (0x0F)
#define DRV8311_GATE_HS_IDRIVEN_MASK    (0xF0)

/* Gate Drive LS Register (0x04) */
#define DRV8311_GATE_LS_IDRIVEP_MASK    (0x0F)
#define DRV8311_GATE_LS_IDRIVEN_MASK    (0xF0)

/* PWM_CTRL1 Register (0x20) */
#define DRV8311_PWM_MODE_6PWM           (0x00)
#define DRV8311_PWM_MODE_3PWM           (0x02)
#define DRV8311_PWM_MODE_PWMGEN         (0x03)  // tSPI PWM Generation Mode
#define DRV8311_SSC_DISABLE             (1 << 2)

/* PWMG_CTRL Register (0x1D) */
#define DRV8311_PWM_EN                  (1 << 10)  // Enable internal PWM generation
#define DRV8311_PWMCNTR_MODE_UP_DOWN    (0x00 << 8)
#define DRV8311_PWMCNTR_MODE_UP         (0x01 << 8)
#define DRV8311_PWMCNTR_MODE_DOWN       (0x02 << 8)

/* PWM_STATE Register (0x1C) values for each phase */
#define DRV8311_PWM_STATE_HIGHZ         (0x0)  // High-Z (off)
#define DRV8311_PWM_STATE_HS_ON         (0x1)  // High-side on
#define DRV8311_PWM_STATE_LS_ON         (0x2)  // Low-side on
#define DRV8311_PWM_STATE_PWM_MODE      (0x7)  // PWM mode (default)

/* ============================================================================
 * Hardware Pin Definitions
 * ============================================================================ */

/* SPI1 Pins (from schematic) */
#define DRV8311_SPI_CS_PIN              GPIO_PIN_10
#define DRV8311_SPI_CS_PORT             GPIOD

/* Second DRV8311 CS Pin */
#define DRV8311_2_SPI_CS_PIN            GPIO_PIN_14
#define DRV8311_2_SPI_CS_PORT           GPIOD

/* PWM_SYNC Pin (TIM15_CH1) */
#define DRV8311_PWM_SYNC_TIM            htim15
#define DRV8311_PWM_SYNC_CHANNEL        TIM_CHANNEL_1

/* Macros for CS Control */
#define DRV8311_CS_LOW()                HAL_GPIO_WritePin(DRV8311_SPI_CS_PORT, DRV8311_SPI_CS_PIN, GPIO_PIN_RESET)
#define DRV8311_CS_HIGH()               HAL_GPIO_WritePin(DRV8311_SPI_CS_PORT, DRV8311_SPI_CS_PIN, GPIO_PIN_SET)

#define DRV8311_2_CS_LOW()              HAL_GPIO_WritePin(DRV8311_2_SPI_CS_PORT, DRV8311_2_SPI_CS_PIN, GPIO_PIN_RESET)
#define DRV8311_2_CS_HIGH()             HAL_GPIO_WritePin(DRV8311_2_SPI_CS_PORT, DRV8311_2_SPI_CS_PIN, GPIO_PIN_SET)

/* ============================================================================
 * DRV8311 Configuration Structure
 * ============================================================================ */

typedef struct {
    SPI_HandleTypeDef *hspi;
    TIM_HandleTypeDef *htim;

    uint8_t device_id;          // Device ID: 1 or 2
    GPIO_TypeDef *cs_port;      // CS GPIO port
    uint16_t cs_pin;            // CS GPIO pin

    uint8_t pwm_mode;           // 0=6PWM, 1=3PWM, 2=1PWM
    uint8_t gate_drive_hs;      // High-side gate drive strength
    uint8_t gate_drive_ls;      // Low-side gate drive strength

    uint8_t fault_status1;      // Last read fault status
    uint8_t fault_status2;

    uint16_t pwm_frequency;     // PWM frequency in Hz
    uint8_t pwm_duty;           // PWM duty cycle (0-100%)
    uint8_t direction;          // 0=CW, 1=CCW

} DRV8311_HandleTypeDef;

/* ============================================================================
 * Function Prototypes
 * ============================================================================ */

/* Initialization and Configuration */
HAL_StatusTypeDef DRV8311_Init(DRV8311_HandleTypeDef *hdrv, SPI_HandleTypeDef *hspi, TIM_HandleTypeDef *htim);
HAL_StatusTypeDef DRV8311_Reset(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_ClearFaults(DRV8311_HandleTypeDef *hdrv);

/* Register Access */
HAL_StatusTypeDef DRV8311_WriteRegister(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint8_t value);
HAL_StatusTypeDef DRV8311_ReadRegister(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint8_t *value);

/* Motor Control */
HAL_StatusTypeDef DRV8311_SetPWMMode(DRV8311_HandleTypeDef *hdrv, uint8_t mode);
HAL_StatusTypeDef DRV8311_SetDirection(DRV8311_HandleTypeDef *hdrv, uint8_t direction);
HAL_StatusTypeDef DRV8311_SetSpeed(DRV8311_HandleTypeDef *hdrv, uint8_t duty_percent);
HAL_StatusTypeDef DRV8311_Start(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_Stop(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_Brake(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_Coast(DRV8311_HandleTypeDef *hdrv);

/* Status and Fault Monitoring */
HAL_StatusTypeDef DRV8311_ReadFaultStatus(DRV8311_HandleTypeDef *hdrv);
uint8_t DRV8311_IsFault(DRV8311_HandleTypeDef *hdrv);
void DRV8311_PrintFaultStatus(DRV8311_HandleTypeDef *hdrv);

/* PWM Configuration */
HAL_StatusTypeDef DRV8311_ConfigurePWM(DRV8311_HandleTypeDef *hdrv, uint16_t frequency_hz);

/* tSPI PWM Generation Mode Functions */
HAL_StatusTypeDef DRV8311_EnablePWMGeneration(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_SetPWMPeriod(DRV8311_HandleTypeDef *hdrv, uint16_t period);
HAL_StatusTypeDef DRV8311_SetPWMDuty(DRV8311_HandleTypeDef *hdrv, uint16_t duty_a, uint16_t duty_b, uint16_t duty_c);
HAL_StatusTypeDef DRV8311_StartPWMGen(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_StopPWMGen(DRV8311_HandleTypeDef *hdrv);

#ifdef __cplusplus
}
#endif

#endif /* __DRV8311_H */
