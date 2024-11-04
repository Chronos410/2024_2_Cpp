#include "fan_typeA.h"
#include "fan_driver.h"
#include <iostream>

using namespace std;

int fanState_PowerOnOff;
int fanState_Speed_level;
int fanState_Swing;


void fan_state(void)
{
	cout <<
		"\t[_CTRL_] Fan State PWR [" << fanState_PowerOnOff << "]"
		<< ", Speed_LEVEL[" << fanState_Speed_level << "]"
		<<", Swing[" << fanState_Swing << "]" << endl;
}

void fan_ctrlPowerOn() 
{
	// ���� ����̹��� �ʱ�ȭ �ϴ� ����
	// �� �Լ��� ���ø� ���ؼ� ������ �ۼ��Ǿ� 
	// ������Ͽ� ���Ǻΰ� ��� ��������,
	// �ۼ��۰� ���� Ÿ���� ������ �� ���ٴ� ������ ������ �ִ�.
	Motor_initialized();
	///
	///�߰��� �Լ����
	/// ����� ����̹� ������Ͽ� ����θ� ���� ����
	Motor_initialize(SpeedMotor_type15, SwingMotor);
	


	fanState_PowerOnOff = true;
	cout << "\t[_CTRL_] ��ǳ�� ���� �ΰ���." << endl;
}

void fan_ctrlPowerOff() 
{
	fanState_PowerOnOff = false;
	fanState_Speed_level = false;
	fanState_Swing = false;
	cout << "\t[_CTRL_] ��ǳ�� ���� ����." << endl;
}
void fan_ctrlSpeed(FAN_SPEED_T speed)
{
	if (IsFanPowerOff()) return;

	fanState_Speed_level = speed;
	switch (fanState_Speed_level)
	{
	case LEVEL_MIN:
		cout << "\t[_CTRL_] ��ǳ�� �ٶ��� �ʹ�ǳ�� �����߽��ϴ�." << endl;
		pSpeedMotor(1);
		break;
	case LEVEL_1:
		cout << "\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
		pSpeedMotor(3);
		break;
	case LEVEL_2:
		cout << "\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
		pSpeedMotor(5);
		break;
	case LEVEL_3:
		cout << "\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
		pSpeedMotor(7);
		break;
	case LEVEL_0:
	default:
		cout << "\t[_CTRL_] ��ǳ�� �ٶ��� ��ǳ�� �����߽��ϴ�." << endl;
		SpeedMotor(0);
		break;
	}
}

void fan_ctrlSwing(FAN_SWING_T swingOn)
{
	if (IsFanPowerOff()) return;

	fanState_Swing = swingOn;
	if (fanState_Swing == SWING_ON)
	{
		cout << "\t[_CTRL_] ��ǳ��� ȸ�� �����߽��ϴ�." << endl;
		SwingMotor(2);
	}
	else
	{
		cout << "\t[_CTRL_] ��ǳ��� ȸ������ �����߽��ϴ�." << endl;
		SwingMotor(0);
	}
}


unsigned char IsFanPowerOn(void)
{
	if (fanState_PowerOnOff) return 1;
	else return 0;
}
unsigned char  IsFanPowerOff(void)
{
	if (fanState_PowerOnOff) return 0;
	else return 1;
}
