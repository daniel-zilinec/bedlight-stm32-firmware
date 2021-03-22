/*
 * pwm.c
 *
 *  Created on: Sep 24, 2020
 *      Author: hello
 */

#include "pwm.h"

void pwm_blue(uint16_t value)
{
    __HAL_TIM_SET_COMPARE(&htim22, TIM_CHANNEL_1, value);
}

void pwm_red(uint16_t value)
{
	__HAL_TIM_SET_COMPARE(&htim21, TIM_CHANNEL_2, value);
}

void pwm_green(uint16_t value)
{
	__HAL_TIM_SET_COMPARE(&htim22, TIM_CHANNEL_2, value);
}

void pwm(uint16_t red, uint16_t green, uint16_t blue)
{
	pwm_red(red);
	pwm_green(green);
	pwm_blue(blue);
}
