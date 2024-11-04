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
/// ���� ���Ǹ� ���ؼ� ������ϸ� �ۼ���
/// ��� ����θ� ���� ����̹� ��밡���ϸ� �ʱ�ȭ �����ϵ��� ��
/// </summary>
/// 
void Motor_initialized(void)
{
	// �ܺο��� ���� �Ҽ� �ְ� �����Ѵٸ� ���� ���� ����� �� ����.
	pSwingMotor = SwingMotor;
	pSpeedMotor = SpeedMotor_type15;
}

// ����̹� �ʱ�ȭ�ÿ� ���� Ÿ���� �����Ͽ� ����ϰ� ����
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

