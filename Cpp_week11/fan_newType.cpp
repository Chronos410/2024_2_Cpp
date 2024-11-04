#include "fan_newType.h"
#include <iostream>

using namespace std;

	fan_newType::fan_newType()
	{
		fan_id = -1;
		fanState_PowerOnOff = 0;
		fanState_Speed_level = 0;
		fanState_Swing = 0;
	}
	fan_newType::fan_newType(unsigned int input_id) 
	{
		fan_id = input_id;
		fanState_PowerOnOff = 0;
		fanState_Speed_level = 0;
		fanState_Swing = 0;
	}

	void fan_newType::fan_state(void)
	{
		cout << "FanNumber [" << fan_id << "]"
			<<"\t\t[_CTRL_] Fan State PWR [" << fanState_PowerOnOff << "]"
			<< ", Speed_LEVEL[" << fanState_Speed_level << "]"
			<< ", Swing[" << fanState_Swing << "]" << endl;
	}

	void fan_newType::fan_ctrlPowerOn()
	{
		fanState_PowerOnOff = true;
		cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� ���� �ΰ���." << endl;
	}

	void fan_newType::fan_ctrlPowerOff()
	{
		fanState_PowerOnOff = false;
		fanState_Speed_level = false;
		fanState_Swing = false;
		cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� ���� ����." << endl;
	}
	void fan_newType::fan_ctrlSpeed(FAN_SPEED_T speed)
	{
		if (fan_newType::IsFanPowerOff()) return;

		fanState_Speed_level = speed;
		switch (fanState_Speed_level)
		{
		case LEVEL_MIN:
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� �ٶ��� �ʹ�ǳ�� �����߽��ϴ�." << endl;
			break;
		case LEVEL_1:
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
			break;
		case LEVEL_2:
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
			break;
		case LEVEL_3:
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
			break;
		case LEVEL_0:
		default:
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
			break;
		}
	}

	void fan_newType::fan_ctrlSwing(FAN_SWING_T swingOn)
	{
		if (fan_newType::IsFanPowerOff()) return;

		fanState_Swing = swingOn;
		if (fanState_Swing == SWING_ON)
		{
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ��� ȸ�� �����߽��ϴ�." << endl;
		}
		else
		{
			cout << "FanNumber [" << fan_id << "]" << "\t\t[_CTRL_] ��ǳ��� ȸ������ �����߽��ϴ�." << endl;
		}
	}


	bool fan_newType::IsFanPowerOn(void)
	{
		if (fanState_PowerOnOff) return false;
		else return true;
	}
	bool fan_newType::IsFanPowerOff(void)
	{
		if (fanState_PowerOnOff) return false;
		else return true;
	}

