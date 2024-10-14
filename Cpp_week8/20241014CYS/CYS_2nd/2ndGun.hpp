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
		//cout << "Gun �⺻ ������ �����" << endl; 
	}

	Gun(int GUN_UID, int MAXBULLET, int CURRENTBULLET, int SHOOTDURATION, bool ISBROKE) {
		gun_uid = GUN_UID;
		maxBullet = MAXBULLET;
		currentBullet = CURRENTBULLET;
		shootDuration = SHOOTDURATION;
		isBroke = ISBROKE;
		//cout << "Gun ����� ���� ������ �����" << endl;
	}

	~Gun() 
	{
		//cout << "Gun �Ҹ��� �����" << endl; 
	}


	void Fire()
	{
		currentBullet--;
		cout << "Gun Fire �Լ� ���� / GUN_UID : " << gun_uid  << endl;
	}
	void Aim(int TARGETUID)
	{
		cout << "Gun Aim �Լ� ���� / TargetPlayer : "<< TARGETUID << endl;
	}
	void CheckBullet()
	{
		cout << "��ź : " << currentBullet << "/" << maxBullet << endl;
		cout << "Gun CheckBullet �Լ� ����" << endl;
	}
	void Reload()
	{
		currentBullet = maxBullet;
		cout << "Gun Reload �Լ� ����" << endl;
	}
	void GunBroke()
	{
		isBroke = true;
		cout << "Gun GunBroke �Լ� ����" << endl;
	}
};

