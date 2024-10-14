#include <iostream>
using namespace std;

#include "3rdGun_Bullet.hpp"
#include "3rdGun_Laser.hpp"

class Human
{
    int uid = -1;
    int hp = 0;
    int currenthp = 0;
    int speed = 0;
    bool isAlive = false;

    bool isGunBullet = false;
    GunBullet* gunB = NULL;
    GunLaser* gunL = NULL;

public:
    Human()
    {
        //cout << "HUMAN �⺻ ������ �����" << endl;
    }
    Human(int UID, int HP, int CURRENTHP, int SPEED, bool ISALIVE)
    {
        //cout << "HUMAN ����� ���� ������ �����" << endl;
        uid = UID;
        hp = HP;
        currenthp = CURRENTHP;
        speed = SPEED;
        isAlive = ISALIVE;
    }
    ~Human()
    {
        //cout << "HUMAN �Ҹ��� �����" << endl;
    }

    void GunFire()
    {
        cout << "HUMAN GunFire �Լ� ����� / HumanUID : " << uid << endl;
        if (isGunBullet)
            gunB->Fire();
        else
            gunL->Fire();
    }
    void GunReload()
    {
        cout << "HUMAN GunReload �Լ� ����� / HumanUID : " << uid << endl;
        if (isGunBullet)
            gunB->Reload();
        else
            gunL->Reload();
    }
    void GunCheckBullet()
    {
        cout << "HUMAN GunCheckBullet �Լ� ����� / HumanUID : " << uid << endl;
        if (isGunBullet)
            gunB->CheckBullet();
        else
            gunL->CheckBullet();
    }
    void GunAim(int TargetUID)
    {
        cout << "HUMAN GunAim �Լ� ����� / HumanUID : " << uid << endl;
        if (isGunBullet)
            gunB->Aim(TargetUID);
        else
            gunL->Aim(TargetUID);
    }


    void ChangeGunBullet(GunBullet* GUN)
    {
        isGunBullet = true;
        gunB = GUN;
        cout << "HUMAN ChangeGunBullet �Լ� ����� / HumanUID : " << uid << endl;
    }
    void ChangeGunLaser(GunLaser* GUN)
    {
        isGunBullet = false;
        gunL = GUN;
        cout << "HUMAN ChangeGunLaser �Լ� ����� / HumanUID : " << uid << endl;
    }

    void Move()
    {
        cout << "Human Move �Լ� ����" << endl;
    }

    void Die()
    {
        isAlive = false;
        cout << "Human Die �Լ� ����" << endl;
    }

    void PlusMaxHp(int plusHp)
    {
        hp = hp + plusHp;
        cout << "MaxHp : " << hp << endl << "Human PlusMaxHp �Լ� ����" << endl;
    }

    void MinusMaxHp(int minusHp)
    {
        hp = hp - minusHp;
        cout << "MaxHp : " << hp << endl << "Human MinusMaxHp �Լ� ����" << endl;
    }

    void GetDamage(int damage)
    {
        cout << "CurrentHp : " << currenthp << endl << "Human GetDamage �Լ� ����" << endl;
    }
};

