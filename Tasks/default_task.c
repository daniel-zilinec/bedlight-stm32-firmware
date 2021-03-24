/*
 * default_task.c
 *
 *  Created on: Mar 24, 2021
 *      Author: hello
 */

#include "cmsis_os.h"
#include "bedlight.h"

void StartDefaultTask(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
	  // if device is enabled
	  if (g_bedlight.power_off == 0)
	  {
		  if (g_bedlight.button1_flag)
		  {
			  button1_callback();
		  }

		  if (g_bedlight.button2_flag)
		  {
			  button2_callback();
		  }

		  if (g_bedlight.button3_flag)
		  {
			  button3_callback();
		  }

		  if (g_bedlight.button4_flag)
		  {
			  button4_callback();
		  }
	  }
	  else		// device disabled
	  {
		  if (	g_bedlight.button1_flag ||		// some button pressed
				g_bedlight.button2_flag ||
				g_bedlight.button3_flag ||
				g_bedlight.button4_flag)
		  {
			  g_bedlight.power_off = 0;		// wake up
		  }

		  else
		  {
			  pwm(0, 0, 0);
		  }
	  }

	  cycle_callback();
	  osDelay(1);
  }
}
