/*
 * simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */
#include "bedlight.h"

void button1_callback()
{
	pwm(255, 0, 0);

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button2_callback()
{
	pwm(0, 255, 0);

	g_bedlight.button2_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button3_callback()
{
	pwm(0 , 0, 255);

	g_bedlight.button3_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button4_callback()
{
	pwm(255, 255, 255);

	g_bedlight.button4_flag = 0;		// clear flag after callback to prevent infinite loop
}

