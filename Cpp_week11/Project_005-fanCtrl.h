#pragma once
#include "fan_newType.h"
#include "fan_newType_B.h"

int main()
{
	fan_newType fan_arr[5];
	for (int i = 0; i < 5; i++) 
	{
		fan_arr[i] = *new fan_newType(i);
	}


	for (int i = 0; i < 5; i++) 
	{
		fan_arr[i].fan_state();
		fan_arr[i].fan_ctrlPowerOn();
		fan_arr[i].fan_ctrlSpeed(fan_newType::LEVEL_MIN);
		fan_arr[i].fan_ctrlSwing(fan_newType::SWING_ON);
		fan_arr[i].fan_state();
		fan_arr[i].fan_ctrlPowerOff();
		fan_arr[i].fan_state();
	}

	fan_newType_B fanB(99);
	fanB.fan_ctrlPowerOn();
	fanB.fan_ctrlSwing();
	
}
