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
		cout << "A_case 생성" << endl;
	}
	~A_case()
	{
		cout << "A_case 소멸" << endl;
	}

	void func() 
	{
		cout << "A_Case의 func" << endl;
	};

	void virtual vfunc() 
	{
		cout << "A_Case의 virtual vfunc" << endl;
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
		// 내 클래스에서 선언한 변수는 전부 접근 가능
		id_pri_derived = 0;
		id_pub_derived = 0;
		id_pro_derived = 0;
		
		//id_pri = 0; 상위 클래스의 private 접근제한자 변수에는 접근 불가
		id_pub = 0;
		id_pro = 0;
	}
	Is_case()
	{
		cout << "Is_case 생성" << endl;
	}
	~Is_case()
	{
		cout << "Is_case 소멸" << endl;
	}

	void func() {
		cout << "is_Case의 func" << endl;
	}
	void func(float i) {
		cout << "is_Case의 func Float버전" << endl;
	}
	void vfunc() override
	{
		cout << "is_Case의 virtual vfunc" << endl;
	};
};//상속을 통해 isCase는 A의 일부이다 를 구현

/*
class has_case
{	
public:
	A_case& Aobj;
};//조합을 통해 hasCase는 A를 가지고 있다를 구현
*/

int main() 
{
	cout << "===================실행직후===================" << endl;
	
	cout << "===================A case===================" << endl;
	A_case aObj;

	//aObj.id_pri = 0;	접근 불가
	aObj.id_pub = 0;
	//aObj.id_pro = 0;  접근 불가
	
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
	//뭔 짓거릴 해도 걍 float로 형변환 해서 받아들임. 애초에 명확한 함수 선언이 중요

	cout << "===================UpCasting===================" << endl;
	//일반 선언 방식들
	A_case a1;
	Is_case a2;
	A_case* pa3 = new A_case();
	Is_case* pa4 = new Is_case();

	//상위 클래스로 캐스팅하기
	Is_case* pIsObj = new Is_case();
	A_case* paObj = new Is_case(); // is_case 클래스는 is_case(new) + A_case(old) 두가지 정보를 가짐

	paObj->func();		//이 경우 A_case의 func이 실행됨
	
	paObj->vfunc();		//is_case의 내용에 접근이 필요할 경우 virtual 키워드를 사용



	cout << "===================종료직전===================" << endl;
}