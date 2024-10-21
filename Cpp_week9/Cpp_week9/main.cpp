#include <iostream>
using namespace std;

		int global_C;	//외부 파일에서 접근 가능
static	int global_D;	//외부 파일에서 접근 불가 

class StaticTestClass
{
	int class_local_a;
	static int class_local_static_a;	//초기화 불가능(여기서는 선언만 가능)
	
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
		cout << "함수의 정적 변수는 " << func_static_a << "입니다." << endl;
		cout << "객체의 로컬 변수는 " << class_local_a << "입니다." << endl;
	}
	void print_local_static()
	{
		cout << "객체의 정적 변수는 " << class_local_static_a << "입니다." << endl;
	}
};
int StaticTestClass::class_local_static_a = 0;	//여기가 정의

void StaticTest() 
{
	int a = 0;
	a++;
	cout << "로컬변수 a는 " << a << "입니다" << endl;

	static int b = 0;
	b++;
	cout << "정적변수 b는 " << b << "입니다" << endl;
}
int main() 
{
	cout << endl << "==============함수 내 변수==============" << endl << endl;
	StaticTest();
	StaticTest();
	StaticTest();
	
	cout << endl << "==============객체 1개==============" << endl << endl;
	StaticTestClass c1;
	c1.print_local(); 
	c1.print_local_static();

	cout << endl << "==============객체 2개==============" << endl << endl;
	StaticTestClass c2;
	c2.print_local();
	c2.print_local_static();

	cout << endl << "==============객체 3개==============" << endl << endl;
	StaticTestClass c3;
	c3.print_local();
	c3.print_local_static();
}