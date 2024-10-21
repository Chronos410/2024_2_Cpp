#include <iostream>
using namespace std;

		int global_C;	//�ܺ� ���Ͽ��� ���� ����
static	int global_D;	//�ܺ� ���Ͽ��� ���� �Ұ� 

class StaticTestClass
{
	int class_local_a;
	static int class_local_static_a;	//�ʱ�ȭ �Ұ���(���⼭�� ���� ����)
	
public:
	StaticTestClass() 
	{
		class_local_a = 0;
		class_local_a++;
		class_local_static_a++;
	}

	void print_local()
	{
		static int func_static_a = 0;
		func_static_a++;
		cout << "�Լ��� ���� ������ " << func_static_a << "�Դϴ�." << endl;
		cout << "��ü�� ���� ������ " << class_local_a << "�Դϴ�." << endl;
	}
	void print_local_static()
	{
		cout << "��ü�� ���� ������ " << class_local_static_a << "�Դϴ�." << endl;
	}
};
int StaticTestClass::class_local_static_a = 0;	//���Ⱑ ����

void StaticTest() 
{
	int a = 0;
	a++;
	cout << "���ú��� a�� " << a << "�Դϴ�" << endl;

	static int b = 0;
	b++;
	cout << "�������� b�� " << b << "�Դϴ�" << endl;
}
int main() 
{
	cout << endl << "==============�Լ� �� ����==============" << endl << endl;
	StaticTest();
	StaticTest();
	StaticTest();
	
	cout << endl << "==============��ü 1��==============" << endl << endl;
	StaticTestClass c1;
	c1.print_local(); 
	c1.print_local_static();

	cout << endl << "==============��ü 2��==============" << endl << endl;
	StaticTestClass c2;
	c2.print_local();
	c2.print_local_static();

	cout << endl << "==============��ü 3��==============" << endl << endl;
	StaticTestClass c3;
	c3.print_local();
	c3.print_local_static();
}