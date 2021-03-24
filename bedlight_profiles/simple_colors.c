/*
 * simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: dadan
 *
 *	Description:
 *
 *  BUTTON 1: red
 *  BUTTON 2: green
 *  BUTTON 3: blue
 *  BUTTON 4: white
 *
 *	Press button to turn on one of the colors. If 2 or more buttons are pressed the light will turn off.
 *	If DIMMING_ENABLE is 1 at build time the light will slowly decrease PWM duty cycle until DIMMING_MIN_VALUE. It will compensate eyes adaption to dark.
 */

#include "bedlight.h"

#define	DIMMING_ENABLED		1			// gradually decrease PWM duty cycle
#define DIMMING_TIME_STEP	10000			// if timer reaches this value PWM will be decreased by 1
#define DIMMING_MIN_VAULE	100			// do not dim bellow this PWM

void button1_callback()
{
	bedlight_set_colors(255, 0, 0);
	g_bedlight.dim_level = 255;
	g_bedlight.timer = 0;

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button2_callback()
{
	bedlight_set_colors(0, 255, 0);
	g_bedlight.dim_level = 255;
	g_bedlight.timer = 0;

	g_bedlight.button2_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button3_callback()
{
	bedlight_set_colors(0 , 0, 255);
	g_bedlight.dim_level = 255;
	g_bedlight.timer = 0;

	g_bedlight.button3_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button4_callback()
{
	bedlight_set_colors(255, 255, 255);
	g_bedlight.dim_level = 255;
	g_bedlight.timer = 0;

	g_bedlight.button4_flag = 0;		// clear flag after callback to prevent infinite loop
}

void cycle_callback()
{
	// dimming
	if (DIMMING_ENABLED)
	{
		if (g_bedlight.timer > DIMMING_TIME_STEP)
		{
			if (g_bedlight.dim_level > DIMMING_MIN_VAULE)
			{
				--g_bedlight.dim_level;
			}

			g_bedlight.update_pwm = 1;
			g_bedlight.timer = 0;
		}
	}
}

