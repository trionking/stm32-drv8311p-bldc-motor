/*
 * adc_func.c
 *
 *  Created on: Oct 2, 2025
 *      Author: SIDO
 */


#include "main.h"
//#include "stdio.h"
#include "string.h"
#include "adc_func.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern ADC_HandleTypeDef hadc3;
extern DMA_HandleTypeDef hdma_adc1;
extern DMA_HandleTypeDef hdma_adc2;
extern DMA_HandleTypeDef hdma_adc3;
extern TIM_HandleTypeDef htim15;


__attribute__((section(".dma_buffer")))
uint16_t adc_dma_buffer[2][8];  // 0x24000000 영역, non-cacheable

__attribute__((section(".ram_d3"))) __attribute__((aligned(32)))
uint16_t adc3_bdma_buffer[8];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	HAL_TIM_PWM_Stop(&htim15,TIM_CHANNEL_1);
	HAL_GPIO_TogglePin(OT_LD1_GPIO_Port, OT_LD1_Pin);
	HAL_GPIO_TogglePin(OT_LD2_GPIO_Port, OT_LD2_Pin);
}

void init_adc(void)
{
  memset(adc_dma_buffer,0,sizeof(adc_dma_buffer));
  HAL_ADCEx_Calibration_Start(&hadc1,ADC_CALIB_OFFSET,ADC_SINGLE_ENDED);
  HAL_ADCEx_Calibration_Start(&hadc2,ADC_CALIB_OFFSET,ADC_SINGLE_ENDED);
  HAL_ADCEx_Calibration_Start(&hadc3,ADC_CALIB_OFFSET,ADC_SINGLE_ENDED);

  HAL_ADC_Start_DMA(&hadc1,(uint32_t *)&adc_dma_buffer[0][0],4);
  HAL_ADC_Start_DMA(&hadc2,(uint32_t *)&adc_dma_buffer[1][0],4);
  HAL_ADC_Start_DMA(&hadc3,(uint32_t *)&adc3_bdma_buffer[0],4);
}

void start_adc(void)
{
	// Timer15 PWM Start
	//HAL_TIM_Base_Start(&htim15);
	HAL_TIM_PWM_Start(&htim15,TIM_CHANNEL_1);
}

void stop_adc(void)
{
	// Timer15 PWM Stop
	//HAL_TIM_Base_Stop(&htim15);
	HAL_TIM_PWM_Stop(&htim15,TIM_CHANNEL_1);
}

