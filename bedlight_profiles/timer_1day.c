/*
 * empty_template.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */
#include "bedlight.h"

#define TIMER_TIMEOUT	(24*60*60*1000)

void button1_callback()
{
	if (g_bedlight.timer > TIMER_TIMEOUT)
	{
		g_bedlight.timer = 0;
	}
}

void button2_callback()
{
	if (g_bedlight.timer > TIMER_TIMEOUT)
	{
		g_bedlight.timer = 0;
	}
}

void button3_callback()
{

}

void button4_callback()
{

}

void cycle_callback()
{
	if (g_bedlight.timer > TIMER_TIMEOUT)
	{
		pwm(255, 0, 0);
	}
	else
	{
		pwm(0, 0, 0);
	}
}
