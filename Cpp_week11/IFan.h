#pragma once
class IFan
{
	int fan_id;
	int fanState_PowerOnOff;
	int fanState_Speed_level;
	int fanState_Swing;

public:
	virtual void fan_state(void);
	virtual void fan_ctrlPowerOn();
	virtual void fan_ctrlPowerOff();
	virtual void fan_ctrlSpeed();
	virtual void fan_ctrlSwing();
	virtual bool IsFanPowerOn(void);
	virtual bool IsFanPowerOff(void);
};

