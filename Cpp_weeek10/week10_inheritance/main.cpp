#include <iostream>
using namespace std;

class A_case
{
private:
	int id_pri;
public:
	int id_pub;
protected:
	int id_pro;

public:
	A_case() 
	{
		cout << "A_case ����" << endl;
	}
	~A_case()
	{
		cout << "A_case �Ҹ�" << endl;
	}

	void func() 
	{
		cout << "A_Case�� func" << endl;
	};

	void virtual vfunc() 
	{
		cout << "A_Case�� virtual vfunc" << endl;
	};
};

class Is_case : public A_case
{
private:
	int id_pri_derived;
public:
	int id_pub_derived;
protected:
	int id_pro_derived;

public:
	void rund() 
	{
		// �� Ŭ�������� ������ ������ ���� ���� ����
		id_pri_derived = 0;
		id_pub_derived = 0;
		id_pro_derived = 0;
		
		//id_pri = 0; ���� Ŭ������ private ���������� �������� ���� �Ұ�
		id_pub = 0;
		id_pro = 0;
	}
	Is_case()
	{
		cout << "Is_case ����" << endl;
	}
	~Is_case()
	{
		cout << "Is_case �Ҹ�" << endl;
	}

	void func() {
		cout << "is_Case�� func" << endl;
	}
	void func(float i) {
		cout << "is_Case�� func Float����" << endl;
	}
	void vfunc() override
	{
		cout << "is_Case�� virtual vfunc" << endl;
	};
};//����� ���� isCase�� A�� �Ϻ��̴� �� ����

/*
class has_case
{	
public:
	A_case& Aobj;
};//������ ���� hasCase�� A�� ������ �ִٸ� ����
*/

int main() 
{
	cout << "===================��������===================" << endl;
	
	cout << "===================A case===================" << endl;
	A_case aObj;

	//aObj.id_pri = 0;	���� �Ұ�
	aObj.id_pub = 0;
	//aObj.id_pro = 0;  ���� �Ұ�
	
	cout << "===================is case===================" << endl;
	Is_case a_Is;

	//a_Is.id_pri_derived = 1000;
	  a_Is.id_pub_derived = 1000;
	//a_Is.id_pro_derived = 1000;

	cout << "===================func test===================" << endl;

	aObj.func();
	a_Is.func();

	a_Is.func(1u);
	a_Is.func(1.0f);
	a_Is.func((int)1);
	//�� ���Ÿ� �ص� �� float�� ����ȯ �ؼ� �޾Ƶ���. ���ʿ� ��Ȯ�� �Լ� ������ �߿�

	cout << "===================UpCasting===================" << endl;
	//�Ϲ� ���� ��ĵ�
	A_case a1;
	Is_case a2;
	A_case* pa3 = new A_case();
	Is_case* pa4 = new Is_case();

	//���� Ŭ������ ĳ�����ϱ�
	Is_case* pIsObj = new Is_case();
	A_case* paObj = new Is_case(); // is_case Ŭ������ is_case(new) + A_case(old) �ΰ��� ������ ����

	paObj->func();		//�� ��� A_case�� func�� �����
	
	paObj->vfunc();		//is_case�� ���뿡 ������ �ʿ��� ��� virtual Ű���带 ���



	cout << "===================��������===================" << endl;
}