#include <iostream>
#include <string>

using namespace std;

class personC 
{
	int age;
public:
	personC(int age = 10) :age(age) 
	{
		cout << "������ ȣ��"<<endl;
	}
	personC(const personC& input)
	{
		age = input.age;
		cout << "���� ������ ȣ��" << endl;
	}
	void print(void);
	personC add(const personC& input);
	personC operator+(const personC& input);
	personC& operator=(const personC& input);	// 4�� �ڵ� �����Լ��� �⺻ ������Կ�����(�길 ���۷���Ÿ����)
	//�ڵ� ���� �Լ� / ������ �Ҹ��� ��������� ������Կ�����
	
};

void personC::print() 
{
	cout << age << endl;
}
personC personC::add(const personC& input) 
{
	cout << "add ȣ��" << endl;
	personC temp(this->age + input.age);
	return temp;
}
personC personC::operator+(const personC& input) // operator�� ����� ������ �����ε�
{
	cout << "operator+ ȣ��" << endl;	
	personC temp(this->age + input.age);
	return temp;
}
personC& personC::operator=(const personC& input) // operator�� ����� �⺻ ������Կ����� �����ε�
{
	cout << "operator= ȣ��" << endl;
	this->age = input.age;
	return *this;
}

int main() 
{
	int res = 1 + 2;

	int a = 1;
	int b = 2;
	int result = a + b;


	personC aPerson;
	aPerson.print();
	personC bPerson;
	bPerson.print();
	//personC resPerson = aPerson + bPerson;
	//�̰� �ϰ����
	personC resultPerson;

	resultPerson = aPerson.add(bPerson);
	// C = C + C
	// C = (this) operator+ (C)
	// C = operator+(C)
	resultPerson.print();

	resultPerson = aPerson + bPerson;	//'+' ������ �����ε� ���(��ȣ�ϴϱ� ��������)
	
	personC cPerson;
	resultPerson = cPerson;				//������Կ����� �����ε� = ����� ���� ������Կ�����

	string str = "test";
	str = str + " + sub";
	str.append(" + append");
	cout << str << endl;
	str[0] = 'A';
	str[1] = 'A';
	str[2] = 'A';
	str[3] = 'A';
	cout << str << endl;



}