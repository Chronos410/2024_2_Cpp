#ifndef _fanLib_
#define _fanLib_
#include <stdio.h>
#include <stdbool.h>

typedef enum {SPEED_0 = 0,
SPEED_1,
SPEED_2,
SPEED_3,
}fanSpeed_t ;

typedef enum {
	SWING_OFF = 0,
	SWING_ON
}fanSwing_t;

bool isPowerOn();

void fan_state();

void fan_ctrl_speed(fanSpeed_t input);

void fan_ctrl_swing(fanSwing_t input);

void fan_ctrl_power();

#endif