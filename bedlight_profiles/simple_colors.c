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
}

void button2_callback()
{
	pwm(0, 255, 0);
}

void button3_callback()
{
	pwm(0 , 0, 255);
}

void button4_callback()
{
	pwm(255, 255, 255);
}

