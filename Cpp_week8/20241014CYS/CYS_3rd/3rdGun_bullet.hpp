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
		//cout << "GunBullet �⺻ ������ �����" << endl; 
	}

	GunBullet(int GUN_UID, int MAXBULLET, int CURRENTBULLET, int SHOOTDURATION, bool ISBROKE) {
		gun_uid = GUN_UID;
		maxBullet = MAXBULLET;
		currentBullet = CURRENTBULLET;
		shootDuration = SHOOTDURATION;
		isBroke = ISBROKE;
		//cout << "GunBullet ����� ���� ������ �����" << endl;
	}

	~GunBullet()
	{
		//cout << "GunBullet �Ҹ��� �����" << endl; 
	}


	void Fire()
	{
		currentBullet--;
		cout << "GunBullet Fire �Լ� ���� / GUN_UID : " << gun_uid << endl;
	}
	void Aim(int TARGETUID)
	{
		cout << "GunBullet Aim �Լ� ���� / TargetPlayer : " << TARGETUID << endl;
	}
	void CheckBullet()
	{
		cout << "��ź : " << currentBullet << "/" << maxBullet << endl;
		cout << "GunBullet CheckBullet �Լ� ����" << endl;
	}
	void Reload()
	{
		currentBullet = maxBullet;
		cout << "GunBullet Reload �Լ� ����" << endl;
	}
	void GunBroke()
	{
		isBroke = true;
		cout << "GunBullet GunBroke �Լ� ����" << endl;
	}
};