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
 * DRV8311P SPI Register Map (tSPI Version)
 * ============================================================================ */

/* Status Registers (Read-Only) */
#define DRV8311_REG_DEV_STS1            0x00  // Device Status 1
#define DRV8311_REG_OT_STS              0x04  // Temperature Status
#define DRV8311_REG_SUP_STS             0x05  // Supply Status
#define DRV8311_REG_DRV_STS             0x06  // Driver Status
#define DRV8311_REG_SYS_STS             0x07  // System Status

/* Configuration Registers (16-bit, requires unlock) */
#define DRV8311_REG_FLT_MODE            0x10  // Fault Mode Configuration
#define DRV8311_REG_SYSF_CTRL           0x12  // System Fault Control
#define DRV8311_REG_DRVF_CTRL           0x13  // Driver Fault Control
#define DRV8311_REG_FLT_TCTRL           0x16  // Fault Time Control
#define DRV8311_REG_FLT_CLR             0x17  // Fault Clear

/* tSPI PWM Generation Registers (16-bit) */
#define DRV8311_REG_PWMG_PERIOD         0x18  // PWM Generator Period
#define DRV8311_REG_PWMG_A_DUTY         0x19  // Phase A Duty
#define DRV8311_REG_PWMG_B_DUTY         0x1A  // Phase B Duty
#define DRV8311_REG_PWMG_C_DUTY         0x1B  // Phase C Duty
#define DRV8311_REG_PWM_STATE           0x1C  // PWM State Control
#define DRV8311_REG_PWMG_CTRL           0x1D  // PWM Generator Control

/* Control Registers (16-bit, requires unlock) */
#define DRV8311_REG_PWM_CTRL1           0x20  // PWM Control 1
#define DRV8311_REG_DRV_CTRL            0x22  // Predriver Control (Slew, Deadtime)
#define DRV8311_REG_CSA_CTRL            0x23  // Current Sense Amplifier Control
#define DRV8311_REG_SYS_CTRL            0x3F  // System Control (Lock/Unlock)

/* SYS_CTRL Register (0x3F) - 16-bit */
#define DRV8311_SYS_CTRL_WRITE_KEY      (0x5 << 12)  // Write key = 0x5 (bits 14-12)
#define DRV8311_SYS_CTRL_REG_LOCK       (1 << 7)     // Register lock bit
#define DRV8311_SYS_CTRL_SPI_PEN        (1 << 6)     // SPI Parity Enable
#define DRV8311_SYS_CTRL_UNLOCK         0x5000       // Unlock: KEY=5, LOCK=0

/* DEV_STS1 Register (0x00) - 16-bit Read Only */
#define DRV8311_STS1_FAULT              (1 << 0)     // Device Fault Status
#define DRV8311_STS1_OT                 (1 << 1)     // Overtemperature
#define DRV8311_STS1_UVP                (1 << 2)     // Undervoltage Protection
#define DRV8311_STS1_OCP                (1 << 5)     // Overcurrent Protection
#define DRV8311_STS1_SPI_FLT            (1 << 6)     // SPI Fault
#define DRV8311_STS1_RESET              (1 << 7)     // Power-On Reset Status
#define DRV8311_STS1_OTP_FLT            (1 << 8)     // OTP Read Fault

/* FLT_CLR Register (0x17) - 16-bit */
#define DRV8311_FLT_CLR_ALL             0x0001       // Clear all faults

/* FLT_MODE Register (0x10) - 16-bit */
#define DRV8311_OCP_MODE_DISABLE        (0x0 << 4)   // OCP Disabled
#define DRV8311_OCP_MODE_LATCH          (0x1 << 4)   // Latch shutdown
#define DRV8311_OCP_MODE_AUTO_RETRY     (0x2 << 4)   // Auto retry
#define DRV8311_OCP_MODE_LATCH_ALL      (0x3 << 4)   // Latch shutdown (all outputs)
#define DRV8311_UVP_MODE_DISABLE        (0x0 << 2)   // UVP Disabled
#define DRV8311_UVP_MODE_ENABLE         (0x1 << 2)   // UVP Enabled
#define DRV8311_OTSD_MODE_DISABLE       (0x0 << 0)   // OTSD Disabled
#define DRV8311_OTSD_MODE_ENABLE        (0x1 << 0)   // OTSD Enabled
#define DRV8311_SPIFLT_MODE_DISABLE     (0x0 << 7)   // SPI Fault Disabled
#define DRV8311_OTPFLT_MODE_ENABLE      (0x1 << 8)   // OTP Fault Enabled

/* SYSF_CTRL Register (0x12) - 16-bit */
#define DRV8311_OTAVDD_EN               (1 << 10)    // AVDD Over-temp Enable
#define DRV8311_OTW_EN                  (1 << 9)     // Over-temp Warning Enable
#define DRV8311_CSAREFUV_EN             (1 << 5)     // CSA REF Under-voltage Enable
#define DRV8311_CPUV_EN                 (1 << 4)     // Charge Pump UV Enable
#define DRV8311_AVDDUV_EN               (1 << 2)     // AVDD UV Enable
#define DRV8311_VINAVDDUV_EN            (1 << 0)     // VIN_AVDD UV Enable

/* DRVF_CTRL Register (0x13) - 16-bit */
#define DRV8311_OCP_LVL_9A              (0x0 << 0)   // OCP Level = 9A (DANGEROUS!)
#define DRV8311_OCP_LVL_5A              (0x1 << 0)   // OCP Level = 5A (SAFER)
#define DRV8311_OCP_TBLANK_200NS        (0x0 << 2)   // OCP Blanking = 0.2us
#define DRV8311_OCP_TBLANK_400NS        (0x1 << 2)   // OCP Blanking = 0.4us
#define DRV8311_OCP_TBLANK_600NS        (0x2 << 2)   // OCP Blanking = 0.6us
#define DRV8311_OCP_TBLANK_1US          (0x3 << 2)   // OCP Blanking = 1us
#define DRV8311_OCP_DEG_200NS           (0x0 << 4)   // OCP Deglitch = 0.2us
#define DRV8311_OCP_DEG_400NS           (0x1 << 4)   // OCP Deglitch = 0.4us
#define DRV8311_OCP_DEG_600NS           (0x2 << 4)   // OCP Deglitch = 0.6us
#define DRV8311_OCP_DEG_1US             (0x3 << 4)   // OCP Deglitch = 1us

/* DRV_CTRL Register (0x22) - 16-bit */
#define DRV8311_DRV_SLEW_35V            (0x0 << 0)   // 35 V/µs
#define DRV8311_DRV_SLEW_75V            (0x1 << 0)   // 75 V/µs
#define DRV8311_DRV_SLEW_180V           (0x2 << 0)   // 180 V/µs
#define DRV8311_DRV_SLEW_230V           (0x3 << 0)   // 230 V/µs
#define DRV8311_DRV_TDEAD_NONE          (0x0 << 4)   // No deadtime
#define DRV8311_DRV_TDEAD_200NS         (0x1 << 4)   // 200ns
#define DRV8311_DRV_TDEAD_400NS         (0x2 << 4)   // 400ns
#define DRV8311_DRV_TDEAD_600NS         (0x3 << 4)   // 600ns
#define DRV8311_DRV_TDEAD_800NS         (0x4 << 4)   // 800ns
#define DRV8311_DRV_TDEAD_1000NS        (0x5 << 4)   // 1us
#define DRV8311_DRV_TDEAD_1200NS        (0x6 << 4)   // 1.2us
#define DRV8311_DRV_TDEAD_1400NS        (0x7 << 4)   // 1.4us
#define DRV8311_DRV_DLYCMP_EN           (1 << 7)     // Delay Compensation Enable

/* CSA_CTRL Register (0x23) - 16-bit */
#define DRV8311_CSA_GAIN_025            (0x0 << 0)   // 0.25 V/A
#define DRV8311_CSA_GAIN_050            (0x1 << 0)   // 0.5 V/A
#define DRV8311_CSA_GAIN_100            (0x2 << 0)   // 1.0 V/A
#define DRV8311_CSA_GAIN_200            (0x3 << 0)   // 2.0 V/A
#define DRV8311_CSA_EN                  (1 << 3)     // CSA Enable

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

    uint8_t pwm_mode;           // 0=6PWM, 2=3PWM, 3=PWM Gen
    uint16_t slew_rate;         // Slew rate setting (DRV_CTRL bits 1-0)
    uint16_t deadtime;          // Deadtime setting (DRV_CTRL bits 6-4)
    uint16_t csa_gain;          // CSA gain setting (CSA_CTRL bits 1-0)

    uint16_t dev_status;        // Last read device status (DEV_STS1)
    uint16_t drv_status;        // Last read driver status (DRV_STS)

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
HAL_StatusTypeDef DRV8311_UnlockRegisters(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_ClearFaults(DRV8311_HandleTypeDef *hdrv);

/* nSLEEP Control */
void DRV8311_nSLEEP_High(void);
void DRV8311_nSLEEP_Low(void);
void DRV8311_nSLEEP_Pulse_Reset(void);

/* Register Access */
HAL_StatusTypeDef DRV8311_WriteRegister16(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint16_t value);
HAL_StatusTypeDef DRV8311_ReadRegister16(DRV8311_HandleTypeDef *hdrv, uint8_t reg_addr, uint16_t *value);

/* Motor Control */
HAL_StatusTypeDef DRV8311_SetPWMMode(DRV8311_HandleTypeDef *hdrv, uint8_t mode);
HAL_StatusTypeDef DRV8311_SetDirection(DRV8311_HandleTypeDef *hdrv, uint8_t direction);
HAL_StatusTypeDef DRV8311_SetSpeed(DRV8311_HandleTypeDef *hdrv, uint8_t duty_percent);
HAL_StatusTypeDef DRV8311_Start(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_Stop(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_Brake(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_Coast(DRV8311_HandleTypeDef *hdrv);

/* Status and Fault Monitoring */
HAL_StatusTypeDef DRV8311_ReadDeviceStatus(DRV8311_HandleTypeDef *hdrv);
HAL_StatusTypeDef DRV8311_ReadDriverStatus(DRV8311_HandleTypeDef *hdrv);
uint8_t DRV8311_IsFault(DRV8311_HandleTypeDef *hdrv);
void DRV8311_PrintDeviceStatus(DRV8311_HandleTypeDef *hdrv);

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
