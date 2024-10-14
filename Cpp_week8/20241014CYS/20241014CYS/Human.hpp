#include <iostream>
using namespace std;

class Human
{
    int uid = -1;
    int hp = 0;
    int currenthp = 0;
    int speed = 0;
    bool isAlive = false;

public:
    Human()
    {
        cout << "HUMAN �⺻ ������ �����" << endl;
    }
    Human(int UID, int HP, int CURRENTHP, int SPEED, bool ISALIVE)
    {
        cout << "HUMAN ����� ���� ������ �����" << endl;
        uid = UID;
        hp = HP;
        currenthp = CURRENTHP;
        speed = SPEED;
        isAlive = ISALIVE;
    }
    ~Human()
    {
        cout << "HUMAN �Ҹ��� �����" << endl;
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
        currenthp = currenthp - damage;
        cout << "CurrentHp : " << currenthp << endl << "Human GetDamage �Լ� ����" << endl;
    }
};

