#include <iostream>
using namespace std;

class Gun
{
	int gun_uid = -1;
	int maxBullet = 30;
	int currentBullet = 30;
	int shootDuration = 1;
	bool isBroke = false;

public:
	Gun() 
	{
		//cout << "Gun 기본 생성자 실행됨" << endl; 
	}

	Gun(int GUN_UID, int MAXBULLET, int CURRENTBULLET, int SHOOTDURATION, bool ISBROKE) {
		gun_uid = GUN_UID;
		maxBullet = MAXBULLET;
		currentBullet = CURRENTBULLET;
		shootDuration = SHOOTDURATION;
		isBroke = ISBROKE;
		//cout << "Gun 사용자 지정 생성자 실행됨" << endl;
	}

	~Gun() 
	{
		//cout << "Gun 소멸자 실행됨" << endl; 
	}


	void Fire()
	{
		currentBullet--;
		cout << "Gun Fire 함수 실행 / GUN_UID : " << gun_uid  << endl;
	}
	void Aim(int TARGETUID)
	{
		cout << "Gun Aim 함수 실행 / TargetPlayer : "<< TARGETUID << endl;
	}
	void CheckBullet()
	{
		cout << "잔탄 : " << currentBullet << "/" << maxBullet << endl;
		cout << "Gun CheckBullet 함수 실행" << endl;
	}
	void Reload()
	{
		currentBullet = maxBullet;
		cout << "Gun Reload 함수 실행" << endl;
	}
	void GunBroke()
	{
		isBroke = true;
		cout << "Gun GunBroke 함수 실행" << endl;
	}
};

