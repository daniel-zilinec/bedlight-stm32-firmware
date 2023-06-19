/*
 * simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */
#include "bedlight.h"

void button1_callback()
{
	//pwm(255, 0, 0);
	//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.red_port, g_bedlight.led.red, GPIO_PIN_SET);
	HAL_GPIO_WritePin(g_bedlight.led.green_port, g_bedlight.led.green, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.blue_port, g_bedlight.led.blue, GPIO_PIN_RESET);

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button2_callback()
{
	//pwm(0, 255, 0);
	//HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.red_port, g_bedlight.led.red, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.green_port, g_bedlight.led.green, GPIO_PIN_SET);
	HAL_GPIO_WritePin(g_bedlight.led.blue_port, g_bedlight.led.blue, GPIO_PIN_RESET);

	g_bedlight.button2_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button3_callback()
{
	//pwm(0 , 0, 255);
	HAL_GPIO_WritePin(GPIOB, LED_BLUE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.red_port, g_bedlight.led.red, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.green_port, g_bedlight.led.green, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.blue_port, g_bedlight.led.blue, GPIO_PIN_SET);


	g_bedlight.button3_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button4_callback()
{
	//pwm(255, 255, 255);
	switch_LEDs();


	g_bedlight.button4_flag = 0;		// clear flag after callback to prevent infinite loop
}

