#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

class myClass 
{
private: 
	static int static_pivate;
public:
	static int static_public;
protected:
	static int static_protected;
	//���� ������ Ŭ���� ������ �ʱ�ȭ �Ұ���(�Ƹ� ���� �����ϴ°� �ƴ϶� �׷� ��)
	
private:
	int id, id2;
	char* pName;

public:
	inline void idOut(); // inline�Լ��� ��ó���⿡�� �Լ�ȣ��ο� ���Ǻθ� �״�� �Է½�Ŵ
	//������ ���ּ���~�� �����Ϸ��� �� ������ ����
	//�Լ��� ȣ���ϴµ� ���̴� �ð�?�� ���� �� ������ �ڵ� ��ü ���̰� �þ
	void idOut(int id);

	myClass() {};
	myClass(int id, int id2 = 100):id(0),id2(id2)
	{
		pName = new char[10];
	};
	myClass(int id, int id2, char* pName) :id(id), id2(id2)
	{
		pName = new char[10];
		this->pName = pName;
	};
	~myClass() 
	{
		delete pName; //���ϸ� �޸� ������ ���������?
	}

	myClass(const myClass& obj) 
	{
		id = obj.id;
		id2 = obj.id2;
		//pName = obj.pName;
		//���� ���� <- �ּҸ� ����
		pName = new char[10];
		strncpy(pName, obj.pName, 10);
		//���� ���� <- ���� �޸𸮸� �Ҵ��� �� ����
	};
	myClass& operator+(const myClass& obj);

	myClass& initId(int id);
	myClass& initId2(int id2);
};

myClass& myClass::initId(int id = 0)
{
	this->id = id;
	return *this;
};
myClass& myClass::initId2(int id2 = 0)
{
	this->id2 = id2;
	return *this;
};

myClass& myClass::operator+(const myClass& obj)
{
	id = id + obj.id;
	id2 = id2 + obj.id2;
	return *this;
}
inline void myClass::idOut() 
{
	cout << id << endl;
};
void myClass::idOut(int id) 
{
	id = this->id;
	cout << id << endl;
};
int myClass::static_pivate = 0;
int myClass::static_public = 0;
int myClass::static_protected = 0;

int main() 
{
	myClass obj1(1);
	myClass obj2(2, 2);
	obj1 = obj1 + obj2;
	obj1.idOut();
}