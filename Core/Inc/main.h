/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OT_LD1_Pin GPIO_PIN_1
#define OT_LD1_GPIO_Port GPIOD
#define OT_LD2_Pin GPIO_PIN_9
#define OT_LD2_GPIO_Port GPIOC
#define OT_SPI3_NCS2_Pin GPIO_PIN_10
#define OT_SPI3_NCS2_GPIO_Port GPIOE
#define OT_SPI3_NCS1_Pin GPIO_PIN_14
#define OT_SPI3_NCS1_GPIO_Port GPIOE
#define OT_SPI2_NCS2_Pin GPIO_PIN_11
#define OT_SPI2_NCS2_GPIO_Port GPIOE
#define OT_SPI2_NCS1_Pin GPIO_PIN_15
#define OT_SPI2_NCS1_GPIO_Port GPIOE
#define OT_SPI1_NCS2_Pin GPIO_PIN_14
#define OT_SPI1_NCS2_GPIO_Port GPIOD
#define OT_SPI1_NCS1_Pin GPIO_PIN_10
#define OT_SPI1_NCS1_GPIO_Port GPIOD
#define IN_ENC5_Z_Pin GPIO_PIN_13
#define IN_ENC5_Z_GPIO_Port GPIOD
#define IN_ENC4_Z_Pin GPIO_PIN_9
#define IN_ENC4_Z_GPIO_Port GPIOE
#define IN_ENC3_Z_Pin GPIO_PIN_11
#define IN_ENC3_Z_GPIO_Port GPIOB
#define IN_ENC2_Z_Pin GPIO_PIN_12
#define IN_ENC2_Z_GPIO_Port GPIOB
#define IN_ENC1_Z_Pin GPIO_PIN_8
#define IN_ENC1_Z_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
