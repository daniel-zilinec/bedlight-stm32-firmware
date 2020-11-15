/*
 * bedlight.h
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */

#ifndef INC_BEDLIGHT_H_
#define INC_BEDLIGHT_H_

#include "stdio.h"
#include "pwm.h"

#define BEDLIGHT_BUTTON_MIN_TIME	100			// minimal time in ms to consider button as pressed

typedef struct
{
	uint32_t button1_counter;
	uint32_t button2_counter;
	uint32_t button3_counter;
	uint32_t button4_counter;
	uint8_t button1_flag;
	uint8_t button2_flag;
	uint8_t button3_flag;
	uint8_t button4_flag;
	uint32_t timer;				// count time in milliseconds
	uint8_t power_off;
} bedlight_t;

extern bedlight_t g_bedlight;

uint8_t pressed_button1();
uint8_t pressed_button2();
uint8_t pressed_button3();
uint8_t pressed_button4();
uint8_t pressed_button_count();

void button1_callback();
void button2_callback();
void button3_callback();
void button4_callback();
void cycle_callback();


#endif /* INC_BEDLIGHT_H_ */
