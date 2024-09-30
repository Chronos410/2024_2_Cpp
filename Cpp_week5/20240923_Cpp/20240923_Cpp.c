#include "fanlib.h"
#include "fanMotorLib.h"

void main() 
{
	fan_state();
	fan_ctrl_power();
	fan_ctrl_speed(SPEED_3);
	fan_ctrl_swing(SWING_ON);
	fan_state();
}