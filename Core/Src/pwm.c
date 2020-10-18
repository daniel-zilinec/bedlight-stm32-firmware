/*
 * pwm.c
 *
 *  Created on: Sep 24, 2020
 *      Author: hello
 */

#include "pwm.h"

void pwm_blue(uint16_t value)
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim22, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim22, TIM_CHANNEL_1);
}

void pwm_red(uint16_t value)
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim21, &sConfigOC, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim21, TIM_CHANNEL_2);
}

void pwm_green(uint16_t value)
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim22, &sConfigOC, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim22, TIM_CHANNEL_2);
}

void pwm(uint16_t red, uint16_t green, uint16_t blue)
{
	pwm_red(red);
	pwm_green(green);
	pwm_blue(blue);
}
