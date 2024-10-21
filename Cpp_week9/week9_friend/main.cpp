#include <iostream>
using namespace std;

class personA;
class personB;

class personA
{
	int age;
public:
	personA(int a)
	{
		age = a;
		cout << "personA���� " << endl;
	}
	void printAge(void);
	void checkOld(const personA& a);
	void checkOld(const personB& a);

	friend class personB;	//�ش� Ŭ�������� �� ��� ����(private)�� ������ �� �ְ� ���� / ��ü������������ �ʴ� / ������
};

class personB 
{
	
	int age;
	int gender;
	int color;
	float wrongCast;
public:
	personB()
	{
		cout << "personB �⺻ ���� " << endl;
	}
	personB(int age): age(age)
	{
		this->age = age;
		cout << "personB 1���� " << endl;
	}
	personB(float b, int age) : age(age), wrongCast(b)
	{
		cout << "personB 2���� " << endl;
	}
	personB(const personB& input) : age(input.age)
	{
		cout << "���� ������ ����" << endl;
	}
	void printAge(void);
	void checkOld(const personA& a);
	void checkOld(const personB& a);

	friend class personA;

	personB returnSelfObj(void) 
	{
		return *this;
	}
	personB* returnSelfPointer(void)
	{
		return this;
	}
	personB& returnSelfRef(void)
	{
		return *this;
	}
	personB& initAge(int a)
	{
		this->age = a;
		return *this;
	}
	personB& initGender(int a)
	{
		this->gender = a;
		return *this;
	}
	personB& initColor(int a)
	{
		this->color = a;
		return *this;
	}
};

void personA::printAge() {
	cout << "personA ������Ʈ�� ���̴� " << age << endl;
}
void personA::checkOld(const personA& a) 
{
	if (age > a.age) 
	{
		cout << "A ���� �� ����" << endl;
	}
	else 
	{
		cout << "A ��밡 �� ����" << endl;
	}
}
void personA::checkOld(const personB& a)
{
	if (age > a.age)
	{
		cout << "B�� �� ����" << endl;
	}
	else
	{
		cout << "A�� �� ����" << endl;
	}
}

void personB::printAge() {
	cout << "personA ������Ʈ�� ���̴� " << age << endl;
}
void personB::checkOld(const personA& a)
{
	if (age > a.age)
	{
		cout << "B�� �� ����" << endl;
	}
	else
	{
		cout << "A�� �� ����" << endl;
	}
}
void personB::checkOld(const personB& a)
{
	if (age > a.age)
	{
		cout << "B ���� �� ����" << endl;
	}
	else
	{
		cout << "B ��밡 �� ����" << endl;
	}
}

int main()
{
	cout << endl << "==================���� ��ü==================" << endl << endl;
	personA a1(10);
	personA a2(30);

	a1.printAge();
	a2.printAge();
	a1.checkOld(a2);

	cout << endl << "==================�ٸ� ��ü==================" << endl << endl;

	personB b1(20);
	personB b2(40);
	a1.checkOld(b1);
	b1.checkOld(b2);
	b2.checkOld(a2);

	cout << endl << "==================this Pointer return==================" << endl << endl;

	personB test(100);
	test.printAge();

	personB* ptest = test.returnSelfPointer();
	ptest->printAge();
	personB& rtest = test.returnSelfRef();
	rtest.printAge();

	personB otest = test.returnSelfObj(); //���� ������ ���
	otest.printAge();

	cout << endl << "==================ü�̴� ���==================" << endl << endl;
	
	personB c(20, 10.0f); //ĳ�������� ���� ������ �ʴ� ������� ��
	personB d;
	d.initAge(20).initColor(1).initGender(2); //ü�̴� ��� / ��ü�� �����ؼ� ��� �̾�� ����
	//�� ����? => ������ �����Ӹ� �ƴ϶� �����̳� �� �ٲ� ������ ��� ��� ����
}