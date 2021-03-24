/*
 * favorite_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: dadan
 *
 *	Description:
 *	FAVORITE COLORS
 *
 *  BUTTON 1: next color
 *  BUTTON 2: previous color
 *  BUTTON 3: more light
 *  BUTTON 4: less light
 *
 *  Change colors with button 1 and 2. Increase and decrease light output with button 3 and 4. Press2 or more buttons to turn off.
 */

#include "bedlight.h"


#define COLOR_DELAY		500		// [ms]
#define DIM_DELAY		50		// [ms]
#define DIM_STEP		10
#define DIM_MIN			30		// do not decrease dim under this value

struct color_t
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct color_t favorite_color[] = {
	{221, 78, 19},		// orange
	{252, 155, 4},		// yellow
	{34, 152, 224},		// light blue
	{66, 249, 131},		// turquoise
	{254, 18, 180},		// purple
	{6, 20, 140},		// dark blue
	{45, 199, 3},		// light green
	{42, 102, 0},		// dark green
	{255, 0, 0}			// red

};

uint32_t current_color = 0;


uint32_t get_favorite_colors_count()
{
	return (sizeof(favorite_color) / 3);
}

void set_favorite_color(uint32_t num)
{
	if (num >= get_favorite_colors_count())		// out of structure range
	{
		return;
	}

	bedlight_set_colors(favorite_color[num].red, favorite_color[num].green, favorite_color[num].blue);
	bedlight_update_pwm();
}

void button1_callback()
{
	// This function is called when BUTTON 1 was pressed
	uint32_t color_count = get_favorite_colors_count();

	if ((current_color + 1) >= color_count)
	{
		current_color = 0;
	}
	else
	{
		++current_color;
	}

	set_favorite_color(current_color);
	osDelay(COLOR_DELAY);

	g_bedlight.button1_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button2_callback()
{
	// This function is called when BUTTON 2 was pressed
	uint32_t color_count = get_favorite_colors_count();

	if (current_color == 0)
	{
		current_color = color_count - 1;
	}
	else
	{
		--current_color;
	}

	set_favorite_color(current_color);
	osDelay(COLOR_DELAY);

	g_bedlight.button2_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button3_callback()
{
	// This function is called when BUTTON 3 was pressed
	if (g_bedlight.dim_level > DIM_MIN)
	{
		if (g_bedlight.dim_level < DIM_STEP)
		{
			g_bedlight.dim_level = 0;
		}
		else
		{
			g_bedlight.dim_level -= DIM_STEP;
		}
	}

	osDelay(DIM_DELAY);
	g_bedlight.button3_flag = 0;		// clear flag after callback to prevent infinite loop
}

void button4_callback()
{
	// This function is called when BUTTON 4 was pressed

	if (g_bedlight.dim_level > (255 - DIM_STEP))
	{
		g_bedlight.dim_level = 255;
	}
	else
	{
		g_bedlight.dim_level += DIM_STEP;
	}

	osDelay(DIM_DELAY);
	g_bedlight.button4_flag = 0;		// clear flag after callback to prevent infinite loop
}

void cycle_callback()
{
	// This function is called every time processor has nothing to do. Don't spend excessive time here or the device can miss some button presses

	// Put your code here
}
