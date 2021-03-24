/*
 * random.c
 *
 *  Created on: Mar 24, 2021
 *      Author: --none--
 *
 *	Description:
 *	RANDOM COLOR
 *
 *  If any button is pressed a random color will be set to LEDs. Two or more buttons pressed in the same time will turn off the light.
 */

#include "bedlight.h"
#include "stdlib.h"

#define MIN_RANDOM_PWM		5

void set_random_color()
{
	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;

	while (((red < MIN_RANDOM_PWM) && (green < MIN_RANDOM_PWM) && (blue < MIN_RANDOM_PWM)))		// prevent from very weak light
	{
		red = rand() % 255;
		green = rand() % 255;
		blue = rand() % 255;
	}

	bedlight_set_colors(red, green, blue);
	bedlight_update_pwm();

	osDelay(500);
}

void button1_callback()
{
	// This function is called when BUTTON 1 was pressed

	set_random_color();

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button2_callback()
{
	// This function is called when BUTTON 2 was pressed

	set_random_color();

	g_bedlight.button2_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button3_callback()
{
	// This function is called when BUTTON 3 was pressed

	set_random_color();

	g_bedlight.button3_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button4_callback()
{
	// This function is called when BUTTON 4 was pressed

	set_random_color();

	g_bedlight.button4_flag = 0;		// clear flag after callback to prevent infinite loop
}

void cycle_callback()
{
	// This function is called every time processor has nothing to do. Don't spend excessive time here or the device can miss some button presses

	// Put your code here
}
