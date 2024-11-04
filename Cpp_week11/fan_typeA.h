
#pragma once
#ifndef _FAN_TYPEA_H_
#define _FAN_TYPEA_H_

// CPP ������ �ɼ� C���� C++�� �Լ��� �ٷ�� ����� �޶� �̷��� �����
// ���ſ� C ���� �ۼ��� �Լ��鵵 ��밡���ϸ�,
// ��ŷ�������� ������ �߻��Ѵ�.
// ��. .c ���Ϸ� �ۼ��ؾ� ��Ȯ�� ���̰� �߻���.
// .cpp ���Ϸ� �ۼ��ϸ� �ڵ����� �ν��� �� ����.
#ifdef __cplusplus
extern "C"  {
#endif 
	// �����͸� ���������� ����ϴ� ���� ������.
	//extern int fanState_PowerOnOff;
	//extern int fanState_Speed;
	//extern int fanState_Swing;

	// ������ �� �ִ� ����� ���������� ������
	typedef enum {
		LEVEL_0 = 0,
		LEVEL_1,
		LEVEL_2,
		LEVEL_3,
		LEVEL_MIN
	}FAN_SPEED_T;

	typedef enum {
		SWING_OFF = 0,
		SWING_ON
	}FAN_SWING_T;



	void fan_state(void);
	void fan_ctrlPowerOn();
	void fan_ctrlPowerOff();
	void fan_ctrlSpeed(FAN_SPEED_T speed);
	void fan_ctrlSwing(FAN_SWING_T swingOn);

	unsigned char  IsFanPowerOn(void);
	unsigned char  IsFanPowerOff(void);

	void SpeedMotor(int speed);
	void SwingMotor(int swing);

#ifdef __cplusplus
}
#endif
#endif // !_FAN_TYPEA_H_

