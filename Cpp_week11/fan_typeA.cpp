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
	// 모터 드라이버를 초기화 하는 구문
	// 이 함수는 예시를 위해서 간단히 작성되어 
	// 헤더파일에 정의부가 들어 가있으며,
	// 작성작가 모터 타입을 선택할 수 없다는 단점을 가지고 있다.
	Motor_initialized();
	///
	///추가된 함수사용
	/// 기능은 드라이버 헤더파일에 선언부를 보고 선택
	Motor_initialize(SpeedMotor_type15, SwingMotor);
	


	fanState_PowerOnOff = true;
	cout << "\t[_CTRL_] 선풍기 전원 인가됨." << endl;
}

void fan_ctrlPowerOff() 
{
	fanState_PowerOnOff = false;
	fanState_Speed_level = false;
	fanState_Swing = false;
	cout << "\t[_CTRL_] 선풍기 전원 꺼짐." << endl;
}
void fan_ctrlSpeed(FAN_SPEED_T speed)
{
	if (IsFanPowerOff()) return;

	fanState_Speed_level = speed;
	switch (fanState_Speed_level)
	{
	case LEVEL_MIN:
		cout << "\t[_CTRL_] 선풍기 바람은 초미풍을 선택했습니다." << endl;
		pSpeedMotor(1);
		break;
	case LEVEL_1:
		cout << "\t[_CTRL_] 선풍기 바람은 미풍을 선택했습니다." << endl;
		pSpeedMotor(3);
		break;
	case LEVEL_2:
		cout << "\t[_CTRL_] 선풍기 바람은 약풍을 선택했습니다." << endl;
		pSpeedMotor(5);
		break;
	case LEVEL_3:
		cout << "\t[_CTRL_] 선풍기 바람은 강풍을 선택했습니다." << endl;
		pSpeedMotor(7);
		break;
	case LEVEL_0:
	default:
		cout << "\t[_CTRL_] 선풍기 바람은 무풍을 선택했습니다." << endl;
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
		cout << "\t[_CTRL_] 선풍기는 회전 선택했습니다." << endl;
		SwingMotor(2);
	}
	else
	{
		cout << "\t[_CTRL_] 선풍기는 회전정지 선택했습니다." << endl;
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
