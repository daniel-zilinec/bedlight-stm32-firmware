/*
 * button.c
 *
 *  Created on: Mar 24, 2021
 *      Author: hello
 */

#include "main.h"
#include "cmsis_os.h"
#include "bedlight.h"

void StartButtonTask(void const * argument)
{
	/* Infinite loop */
	for(;;)
	{
		if (osMutexWait(bedlightMutexHandle, 10) == osOK)
		{
			// Critical section for g_bedlight structure

			// Read button states and increment it's counters if pressed

			// BUTTON 1
			if (pressed_button1())
			{
				++g_bedlight.button1_counter;
			}
			else
			{
				g_bedlight.button1_counter = 0;
			}

			// BUTTON 2
			if (pressed_button2())
			{
				++g_bedlight.button2_counter;
			}
			else
			{
				g_bedlight.button2_counter = 0;
			}

			// BUTTON 3
			if (pressed_button3())
			{
				++g_bedlight.button3_counter;
			}
			else
			{
				g_bedlight.button3_counter = 0;
			}

			// BUTTON 4
			if (pressed_button4())
			{
				++g_bedlight.button4_counter;
			}
			else
			{
				g_bedlight.button4_counter = 0;
			}

			// set button pressed flag if it is pressed for long enough
			if (g_bedlight.button1_counter > (BEDLIGHT_BUTTON_MIN_TIME / BUTTON_LOOP_DELAY))
			{
				g_bedlight.button1_flag = 1;
			}

			if (g_bedlight.button2_counter > (BEDLIGHT_BUTTON_MIN_TIME / BUTTON_LOOP_DELAY))
			{
				g_bedlight.button2_flag = 1;
			}

			if (g_bedlight.button3_counter > (BEDLIGHT_BUTTON_MIN_TIME / BUTTON_LOOP_DELAY))
			{
				g_bedlight.button3_flag = 1;
			}

			if (g_bedlight.button4_counter > (BEDLIGHT_BUTTON_MIN_TIME / BUTTON_LOOP_DELAY))
			{
				g_bedlight.button4_flag = 1;
			}

			// power-off if at least 2 buttons are pressed
			if ( pressed_button_count() >= 2)
			{
				// clear flags
				g_bedlight.button1_flag = 0;
				g_bedlight.button2_flag = 0;
				g_bedlight.button3_flag = 0;
				g_bedlight.button4_flag = 0;

				// power off
				g_bedlight.power_off = 1;

				// end of critical section
				osMutexRelease(bedlightMutexHandle);

				while (pressed_button_count() != 0);		//	long loop inside critical section
			}
			else
			{
				// end of critical section
				osMutexRelease(bedlightMutexHandle);
			}
	}

	osDelay(BUTTON_LOOP_DELAY);
  }
}
