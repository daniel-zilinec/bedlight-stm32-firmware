/*
 * bedlight_simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */


#include "bedlight.h"

bedlight_t g_bedlight;

__weak void button1_callback()
{

}

__weak void button2_callback()
{

}

__weak void button3_callback()
{

}

__weak void button4_callback()
{

}

__weak void cycle_callback()
{

}


void bedlight_process(uint32_t cycle_time)
{
	if ((g_bedlight.button1_flag + g_bedlight.button2_flag + g_bedlight.button3_flag + g_bedlight.button4_flag) > 1)
	{
		pwm(0, 0, 0);

		while (pressed_button_count() != 0);

		g_bedlight.button1_flag = 0;
		g_bedlight.button2_flag = 0;
		g_bedlight.button3_flag = 0;
		g_bedlight.button4_flag = 0;
	}

	if (g_bedlight.button1_flag)
	{
		button1_callback();

		g_bedlight.button1_flag = 0;		// clear flag
	}

	if (g_bedlight.button2_flag)
	{
		button2_callback();

		g_bedlight.button2_flag = 0;		// clear flag
	}

	if (g_bedlight.button3_flag)
	{
		button3_callback();

		g_bedlight.button3_flag = 0;		// clear flag
	}

	if (g_bedlight.button4_flag)
	{
		button4_callback();

		g_bedlight.button4_flag = 0;		// clear flag
	}

	g_bedlight.timer += cycle_time;
	cycle_callback();
}

uint8_t pressed_button1()
{
	  if (HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}

uint8_t pressed_button2()
{
	  if (HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}


uint8_t pressed_button3()
{
	  if (HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}

uint8_t pressed_button4()
{
	  if (HAL_GPIO_ReadPin(BUTTON4_GPIO_Port, BUTTON4_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}

uint8_t pressed_button_count()
{
	return (pressed_button1() + pressed_button2() + pressed_button3() + pressed_button4());
}
