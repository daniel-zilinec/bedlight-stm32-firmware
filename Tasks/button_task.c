/*
 * button.c
 *
 *  Created on: Mar 24, 2021
 *      Author: hello
 */

#include "cmsis_os.h"
#include "bedlight.h"

void StartButtonTask(void const * argument)
{
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
}
