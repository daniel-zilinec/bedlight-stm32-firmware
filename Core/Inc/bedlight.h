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

typedef struct
{
	uint8_t button1_flag;
	uint8_t button2_flag;
	uint8_t button3_flag;
	uint8_t button4_flag;
} bedlight_t;

extern bedlight_t g_bedlight;

void bedlight_process();
uint8_t pressed_button1();
uint8_t pressed_button2();
uint8_t pressed_button3();
uint8_t pressed_button4();
uint8_t pressed_button_count();

void button1_callback();
void button2_callback();
void button3_callback();
void button4_callback();


#endif /* INC_BEDLIGHT_H_ */
