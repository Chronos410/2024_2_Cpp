
#pragma once
#ifndef _FAN_TYPEA_H_
#define _FAN_TYPEA_H_

// CPP 컴파일 옵션 C언어와 C++은 함수를 다루는 방식이 달라서 이렇게 해줘야
// 과거에 C 언어로 작성된 함수들도 사용가능하며,
// 링킹과정에서 오류가 발생한다.
// 단. .c 파일로 작성해야 정확히 차이가 발생함.
// .cpp 파일로 작성하면 자동으로 인식할 수 있음.
#ifdef __cplusplus
extern "C"  {
#endif 
	// 데이터를 직접적으로 사용하는 것은 안좋다.
	//extern int fanState_PowerOnOff;
	//extern int fanState_Speed;
	//extern int fanState_Swing;

	// 제어할 수 있는 기능을 열거형으로 제어함
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

