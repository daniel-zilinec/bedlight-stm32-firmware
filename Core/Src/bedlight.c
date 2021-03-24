/*
 * bedlight_simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */


#include "bedlight.h"

volatile bedlight_t g_bedlight;

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


/**
 * @brief Set color settings to internal structure
 * @param red red LED PWM duty cycle
 * @param green green LED PWM duty cycle
 * @param blue blue LED PWM duty cycle
 */
void bedlight_set_colors(uint8_t red, uint8_t green, uint8_t blue)
{
	g_bedlight.red = red;
	g_bedlight.green = green;
	g_bedlight.blue = blue;
	g_bedlight.update_pwm = 1;
}


/**
 * @brief Update PWM registers and apply dimming
 */
void bedlight_update_pwm()
{
	if (g_bedlight.update_pwm)
	{
		uint8_t red = 0;
		uint8_t green = 0;
		uint8_t blue = 0;
		float dim = 0;

		dim = (g_bedlight.dim_level / 255.0);
		red = g_bedlight.red * dim;
		green = g_bedlight.green * dim;
		blue = g_bedlight.blue * dim;

		pwm(red, green, blue);
	}
}
