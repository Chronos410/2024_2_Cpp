#include "fan_newType_B.h"
#include <iostream>
using namespace std;

fan_newType_B::fan_newType_B(unsigned int input_id) 
{
	fan_id = input_id;
	fanState_PowerOnOff = 0;
	fanState_Speed_level = 0;
	fanState_Swing = 0;
}

void fan_newType_B::fan_state(void)
{
	cout << "FanNumber [" << fan_id << "]"
		<< "\t\t[_CTRL_] Fan State PWR [" << fanState_PowerOnOff << "]"
		<< ", Speed_LEVEL[" << fanState_Speed_level << "]" << endl;
}

void fan_newType_B::fan_ctrlPowerOn()
{
	fanState_PowerOnOff = true;
	cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ŧ������ ���� �ΰ���." << endl;
}

void fan_newType_B::fan_ctrlPowerOff()
{
	fanState_PowerOnOff = false;
	fanState_Speed_level = false;
	fanState_Swing = false;
	cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ŧ������ ���� ����." << endl;
}

void fan_newType_B::fan_ctrlSpeed(FAN_SPEED_T speed)
{
	if (fan_newType_B::IsFanPowerOff()) return;

	fanState_Speed_level = speed;

	if (fanState_Speed_level == OFF)
	{
		cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ŧ������ �ٶ��� ������ �����߽��ϴ�." << endl;
	}
	else if (fanState_Speed_level == ON)
	{
		cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ŧ������ �ٶ��� ������ �����߽��ϴ�." << endl;
	}
}

void fan_newType_B::fan_ctrlSwing()
{
	cout << "FanNumber [" << fan_id << "]" << "\t\t[_ERROR_] ��ŧ�����ʹ� ������ �Ұ����մϴ�." << endl;
}

bool fan_newType_B::IsFanPowerOn(void)
{
	if (fanState_PowerOnOff) return false;
	else return true;
}
bool fan_newType_B::IsFanPowerOff(void)
{
	if (fanState_PowerOnOff) return false;
	else return true;
}
