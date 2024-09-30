#include "fanLib.h"

static int fanSpeed = 0;
static bool fanSwing = false;
static bool fanPower = false;

bool isPowerOn() 
{
	if (fanPower) return true;
	else return false;
}

void fan_state()
{
	if (isPowerOn())
		printf("전원이 켜져있습니다.\n");
	else
		printf("전원이 꺼져있습니다.\n");

	printf("팬 속도는 %d입니다.\n", fanSpeed);

	if (fanSwing)
		printf("스윙이 동작상태 입니다.\n\n");
	else
		printf("스윙이 정지상태 입니다.\n\n");
}

void fan_ctrl_speed(fanSpeed_t input)
{
	if (!isPowerOn()) return;

	printf("팬 속도를 %d로 선택했습니다.\n\n", SpeedMotor(input));
}

void fan_ctrl_swing(fanSwing_t input)
{
	if (!isPowerOn()) return;

	if (SwingMotor(input))
		printf("스윙 동작을 선택했습니다.\n\n");
	else
		printf("스윙 정지를 선택했습니다.\n\n");
}

void fan_ctrl_power()
{
	if (fanPower) 
	{
		printf("전원 OFF\n\n");
		fanPower = false;
	}
	else 
	{
		printf("전원 ON\n\n");
		fanPower = true;
	}
}