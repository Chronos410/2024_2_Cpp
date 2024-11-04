#pragma once

#include"IFan.h"

class fan_newType : IFan
{
	int fan_id;
	int fanState_PowerOnOff;
	int fanState_Speed_level;
	int fanState_Swing;

public:
	enum FAN_SPEED_T {
		LEVEL_0 = 0,
		LEVEL_1,
		LEVEL_2,
		LEVEL_3,
		LEVEL_MIN
	};
	enum FAN_SWING_T {
		SWING_OFF = 0,
		SWING_ON
	}; 
	fan_newType();
	fan_newType(unsigned int a);
	void fan_state(void);
	void fan_ctrlPowerOn();
	void fan_ctrlPowerOff();
	void fan_ctrlSpeed(FAN_SPEED_T speed);
	void fan_ctrlSwing(FAN_SWING_T swingOn);
	bool IsFanPowerOn(void);
	bool IsFanPowerOff(void);
};

