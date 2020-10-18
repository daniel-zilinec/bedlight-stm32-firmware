/*
 * pwm.h
 *
 *  Created on: Sep 24, 2020
 *      Author: hello
 */

#ifndef SRC_PWM_H_
#define SRC_PWM_H_

#include <stdint.h>
#include "tim.h"

void pwm_red(uint16_t value);
void pwm_green(uint16_t value);
void pwm_blue(uint16_t value);
void pwm(uint16_t red, uint16_t green, uint16_t blue);


#endif /* SRC_PWM_H_ */
