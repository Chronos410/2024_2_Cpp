#pragma once
#include "3rdGun.hpp"

class GunLaser : Gun
{
	int gun_uid = -1;
	int maxBullet = 30;
	int currentBullet = 30;
	int shootDuration = 1;
	bool isBroke = false;

public:
	GunLaser()
	{
		//cout << "GunBullet �⺻ ������ �����" << endl; 
	}

	GunLaser(int GUN_UID, int MAXBULLET, int CURRENTBULLET, int SHOOTDURATION, bool ISBROKE) {
		gun_uid = GUN_UID;
		maxBullet = MAXBULLET;
		currentBullet = CURRENTBULLET;
		shootDuration = SHOOTDURATION;
		isBroke = ISBROKE;
		//cout << "GunBullet ����� ���� ������ �����" << endl;
	}

	~GunLaser()
	{
		//cout << "GunBullet �Ҹ��� �����" << endl; 
	}


	void Fire()
	{
		currentBullet--;
		cout << "GunLaser Fire �Լ� ���� / GUN_UID : " << gun_uid << endl;
	}
	void Aim(int TARGETUID)
	{
		cout << "GunLaser Aim �Լ� ���� / TargetPlayer : " << TARGETUID << endl;
	}
	void CheckBullet()
	{
		cout << "��ź : " << currentBullet << "/" << maxBullet << endl;
		cout << "GunLaser CheckBullet �Լ� ����" << endl;
	}
	void Reload()
	{
		currentBullet = maxBullet;
		cout << "GunLaser Reload �Լ� ����" << endl;
	}
	void GunBroke()
	{
		isBroke = true;
		cout << "GunLaser GunBroke �Լ� ����" << endl;
	}
};