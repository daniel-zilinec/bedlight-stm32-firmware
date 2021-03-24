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

#define BUTTON_LOOP_DELAY			10
#define BEDLIGHT_BUTTON_MIN_TIME	100			// minimal time in ms to consider button as pressed

typedef struct
{
	uint32_t button1_counter;		// how long is button pressed [ms]
	uint32_t button2_counter;		// how long is button pressed [ms]
	uint32_t button3_counter;		// how long is button pressed [ms]
	uint32_t button4_counter;		// how long is button pressed [ms]
	uint8_t button1_flag;			// 1 if button is pressed long enough
	uint8_t button2_flag;			// 1 if button is pressed long enough
	uint8_t button3_flag;			// 1 if button is pressed long enough
	uint8_t button4_flag;			// 1 if button is pressed long enough
	uint32_t timer;					// count time in milliseconds
	uint8_t power_off;				// 1 if device is disabled and all LEDs are off

	uint8_t red;			// desired red LED duty cycle
	uint8_t green;			// desired green LED duty cycle
	uint8_t blue;			// desired blue LED duty cycle
	uint8_t update_pwm;		// 1 if update of PWM registers needed
	uint8_t dim_level;		// dimming: 255 = 100% (no dimming)

} bedlight_t;

extern volatile bedlight_t g_bedlight;

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

void bedlight_set_colors(uint8_t red, uint8_t green, uint8_t blue);
void bedlight_update_pwm();


#endif /* INC_BEDLIGHT_H_ */
