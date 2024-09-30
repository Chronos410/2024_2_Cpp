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
		printf("������ �����ֽ��ϴ�.\n");
	else
		printf("������ �����ֽ��ϴ�.\n");

	printf("�� �ӵ��� %d�Դϴ�.\n", fanSpeed);

	if (fanSwing)
		printf("������ ���ۻ��� �Դϴ�.\n\n");
	else
		printf("������ �������� �Դϴ�.\n\n");
}

void fan_ctrl_speed(fanSpeed_t input)
{
	if (!isPowerOn()) return;

	printf("�� �ӵ��� %d�� �����߽��ϴ�.\n\n", SpeedMotor(input));
}

void fan_ctrl_swing(fanSwing_t input)
{
	if (!isPowerOn()) return;

	if (SwingMotor(input))
		printf("���� ������ �����߽��ϴ�.\n\n");
	else
		printf("���� ������ �����߽��ϴ�.\n\n");
}

void fan_ctrl_power()
{
	if (fanPower) 
	{
		printf("���� OFF\n\n");
		fanPower = false;
	}
	else 
	{
		printf("���� ON\n\n");
		fanPower = true;
	}
}