/*
 * bedlight_simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */


#include "bedlight.h"

bedlight_t g_bedlight;



void bedlight_process()
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
		pwm(255, 0, 0);

		g_bedlight.button1_flag = 0;		// clear flag
	}

	if (g_bedlight.button2_flag)
	{
		pwm(0, 255, 0);

		g_bedlight.button2_flag = 0;		// clear flag
	}

	if (g_bedlight.button3_flag)
	{
		pwm(0, 0, 255);

		g_bedlight.button3_flag = 0;		// clear flag
	}

	if (g_bedlight.button4_flag)
	{
		pwm(255, 255, 255);

		g_bedlight.button4_flag = 0;		// clear flag
	}


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
	  if (HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == GPIO_PIN_RESET)
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
