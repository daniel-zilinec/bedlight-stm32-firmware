/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32l0xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON4_Pin GPIO_PIN_2
#define BUTTON4_GPIO_Port GPIOA
#define BUTTON4_EXTI_IRQn EXTI2_3_IRQn
#define BUTTON1_Pin GPIO_PIN_5
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON1_EXTI_IRQn EXTI4_15_IRQn
#define BUTTON2_Pin GPIO_PIN_6
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON2_EXTI_IRQn EXTI4_15_IRQn
#define BUTTON3_Pin GPIO_PIN_7
#define BUTTON3_GPIO_Port GPIOA
#define BUTTON3_EXTI_IRQn EXTI4_15_IRQn
#define LED_RED2_Pin GPIO_PIN_1
#define LED_RED2_GPIO_Port GPIOB
#define LED_BLUE2_Pin GPIO_PIN_8
#define LED_BLUE2_GPIO_Port GPIOA
#define LED_RED1_Pin GPIO_PIN_11
#define LED_RED1_GPIO_Port GPIOA
#define LED_GREEN2_Pin GPIO_PIN_12
#define LED_GREEN2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LD3_Pin GPIO_PIN_3
#define LD3_GPIO_Port GPIOB
#define LED_BLUE1_Pin GPIO_PIN_4
#define LED_BLUE1_GPIO_Port GPIOB
#define LED_GREEN1_Pin GPIO_PIN_5
#define LED_GREEN1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
