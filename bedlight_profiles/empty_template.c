/*
 * empty_template.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */
#include "bedlight.h"

void button1_callback()
{
	// This function is called when BUTTON 1 was pressed

	// Put your code here

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button2_callback()
{
	// This function is called when BUTTON 2 was pressed

	// Put your code here

	g_bedlight.button2_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button3_callback()
{
	// This function is called when BUTTON 3 was pressed

	// Put your code here

	g_bedlight.button3_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button4_callback()
{
	// This function is called when BUTTON 4 was pressed

	// Put your code here

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void cycle_callback()
{
	// This function is called every time processor has nothing to do. Don't spend excessive time here or the device can miss some button presses

	// Put your code here
}
