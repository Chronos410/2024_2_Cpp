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
        cout << "HUMAN 기본 생성자 실행됨" << endl;
    }
    Human(int UID, int HP, int CURRENTHP, int SPEED, bool ISALIVE)
    {
        cout << "HUMAN 사용자 지정 생성자 실행됨" << endl;
        uid = UID;
        hp = HP;
        currenthp = CURRENTHP;
        speed = SPEED;
        isAlive = ISALIVE;
    }
    ~Human()
    {
        cout << "HUMAN 소멸자 실행됨" << endl;
    }
    void Move()
    {
        cout << "Human Move 함수 실행" << endl;
    }

    void Die()
    {
        isAlive = false;
        cout << "Human Die 함수 실행" << endl;
    }

    void PlusMaxHp(int plusHp)
    {
        hp = hp + plusHp;
        cout << "MaxHp : " << hp << endl << "Human PlusMaxHp 함수 실행" << endl;
    }

    void MinusMaxHp(int minusHp)
    {
        hp = hp - minusHp;
        cout << "MaxHp : " << hp << endl << "Human MinusMaxHp 함수 실행" << endl;
    }

    void GetDamage(int damage)
    {
        currenthp = currenthp - damage;
        cout << "CurrentHp : " << currenthp << endl << "Human GetDamage 함수 실행" << endl;
    }
};

