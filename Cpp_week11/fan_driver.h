#pragma once
#ifndef _FAN_DRIVER_H_
#define _FAN_DRIVER_H_

void (*pSpeedMotor)(int);
void (*pSwingMotor)(int);

#include <iostream>

unsigned int Motor_speed_value;
unsigned int Motor_swing_value;

void Motor_initialized(void);
void Motor_initialize(void(*SpeedMotor)(int), void(*SwingMotor)(int));


void SpeedMotor(int speed);
void SwingMotor(int swing);
void SpeedMotor_type15(int speed);
void SwingMotor_type12(int swing);




/// <summary>
/// 수업 편의를 위해서 헤더파일만 작성함
/// 상단 선언부를 보고 드라이버 사용가능하며 초기화 가능하도록 함
/// </summary>
/// 
void Motor_initialized(void)
{
	// 외부에서 제어 할수 있게 수정한다면 좀더 좋은 방법이 될 것임.
	pSwingMotor = SwingMotor;
	pSpeedMotor = SpeedMotor_type15;
}

// 드라이버 초기화시에 모토 타입을 지정하여 사용하게 유도
void Motor_initialize(void(*SpeedMotor)(int), void(*SwingMotor)(int))
{
	pSwingMotor = SwingMotor;
	pSpeedMotor = SpeedMotor;
}


void SpeedMotor(int speed)
{
	Motor_speed_value = speed;
	printf("\t\t[_DRIVER_] Motor speed Ctrl value = [%d]\n", Motor_speed_value);
}

void SpeedMotor_type15(int speed)
{
	Motor_speed_value = speed;
	printf("\t\t[_DRIVER_] Motor_T15 speed Ctrl value = [%d]\n", Motor_speed_value);
}

void SwingMotor(int swing)
{
	Motor_swing_value = swing;
	printf("\t\t[_DRIVER_] Motor swing Ctrl value = [%d]\n", Motor_speed_value);
}

void SwingMotor_type12(int swing)
{
	Motor_swing_value = swing;
	printf("\t\t[_DRIVER_] Motor_T12 swing Ctrl value = [%d]\n", Motor_speed_value);
}

#endif // !_FAN_DRIVER_H_

