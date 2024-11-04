#pragma once

#include"IFan.h"

class fan_newType_B : IFan
{
	int fan_id;
	int fanState_PowerOnOff;
	int fanState_Speed_level;
	int fanState_Swing;

public:
	enum FAN_SPEED_T {
		OFF = 0,
		ON
	};

	fan_newType_B(unsigned int a);
	void fan_state(void);
	void fan_ctrlPowerOn();
	void fan_ctrlPowerOff();
	void fan_ctrlSpeed(FAN_SPEED_T speed);
	void fan_ctrlSwing();
	bool IsFanPowerOn(void);
	bool IsFanPowerOff(void);

};

