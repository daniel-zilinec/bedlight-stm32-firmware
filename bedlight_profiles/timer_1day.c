/*
 * empty_template.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */
#include "bedlight.h"

#define TIMER_TIMEOUT	(24*60*60*1000)
// #define TIMER_TIMEOUT	(2*1000)

uint8_t timeout_flag = 0;		// if non zero turn on the LED

void button1_callback()
{
	if (g_bedlight.timer > TIMER_TIMEOUT)
	{
		g_bedlight.timer = 0;
		timeout_flag = 0;
		g_bedlight.power_off = 1;
	}
}

void button2_callback()
{
	if (g_bedlight.timer > TIMER_TIMEOUT)
	{
		g_bedlight.timer = 0;
		timeout_flag = 0;
		g_bedlight.power_off = 1;
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
			// never allow to turn off

	if ((g_bedlight.timer > TIMER_TIMEOUT) && (timeout_flag == 0))
	{
		pwm(255, 0, 0);		// turn on red LED
		timeout_flag = 1;
		g_bedlight.power_off = 0;
	}
}
