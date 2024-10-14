#pragma once
#include "3rdGun.hpp"

class GunBullet : Gun
{
	int gun_uid = -1;
	int maxBullet = 30;
	int currentBullet = 30;
	int shootDuration = 1;
	bool isBroke = false;

public:
	GunBullet()
	{
		//cout << "GunBullet 기본 생성자 실행됨" << endl; 
	}

	GunBullet(int GUN_UID, int MAXBULLET, int CURRENTBULLET, int SHOOTDURATION, bool ISBROKE) {
		gun_uid = GUN_UID;
		maxBullet = MAXBULLET;
		currentBullet = CURRENTBULLET;
		shootDuration = SHOOTDURATION;
		isBroke = ISBROKE;
		//cout << "GunBullet 사용자 지정 생성자 실행됨" << endl;
	}

	~GunBullet()
	{
		//cout << "GunBullet 소멸자 실행됨" << endl; 
	}


	void Fire()
	{
		currentBullet--;
		cout << "GunBullet Fire 함수 실행 / GUN_UID : " << gun_uid << endl;
	}
	void Aim(int TARGETUID)
	{
		cout << "GunBullet Aim 함수 실행 / TargetPlayer : " << TARGETUID << endl;
	}
	void CheckBullet()
	{
		cout << "잔탄 : " << currentBullet << "/" << maxBullet << endl;
		cout << "GunBullet CheckBullet 함수 실행" << endl;
	}
	void Reload()
	{
		currentBullet = maxBullet;
		cout << "GunBullet Reload 함수 실행" << endl;
	}
	void GunBroke()
	{
		isBroke = true;
		cout << "GunBullet GunBroke 함수 실행" << endl;
	}
};