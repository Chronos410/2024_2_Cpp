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
		cout << "personA생성 " << endl;
	}
	void printAge(void);
	void checkOld(const personA& a);
	void checkOld(const personB& a);

	friend class personB;	//해당 클래스에서 내 멤버 변수(private)에 접근할 수 있게 해줌 / 객체지향적이지는 않다 / 쓰지마
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
		cout << "personB 기본 생성 " << endl;
	}
	personB(int age): age(age)
	{
		this->age = age;
		cout << "personB 1생성 " << endl;
	}
	personB(float b, int age) : age(age), wrongCast(b)
	{
		cout << "personB 2생성 " << endl;
	}
	personB(const personB& input) : age(input.age)
	{
		cout << "복사 생성자 실행" << endl;
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
	cout << "personA 오브젝트의 나이는 " << age << endl;
}
void personA::checkOld(const personA& a) 
{
	if (age > a.age) 
	{
		cout << "A 내가 더 많다" << endl;
	}
	else 
	{
		cout << "A 상대가 더 많다" << endl;
	}
}
void personA::checkOld(const personB& a)
{
	if (age > a.age)
	{
		cout << "B가 더 많다" << endl;
	}
	else
	{
		cout << "A가 더 많다" << endl;
	}
}

void personB::printAge() {
	cout << "personA 오브젝트의 나이는 " << age << endl;
}
void personB::checkOld(const personA& a)
{
	if (age > a.age)
	{
		cout << "B가 더 많다" << endl;
	}
	else
	{
		cout << "A가 더 많다" << endl;
	}
}
void personB::checkOld(const personB& a)
{
	if (age > a.age)
	{
		cout << "B 내가 더 많다" << endl;
	}
	else
	{
		cout << "B 상대가 더 많다" << endl;
	}
}

int main()
{
	cout << endl << "==================동일 객체==================" << endl << endl;
	personA a1(10);
	personA a2(30);

	a1.printAge();
	a2.printAge();
	a1.checkOld(a2);

	cout << endl << "==================다른 객체==================" << endl << endl;

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

	personB otest = test.returnSelfObj(); //복사 생성자 사용
	otest.printAge();

	cout << endl << "==================체이닝 기법==================" << endl << endl;
	
	personB c(20, 10.0f); //캐스팅으로 인해 원하지 않는 방식으로 들어감
	personB d;
	d.initAge(20).initColor(1).initGender(2); //체이닝 기법 / 객체를 리턴해서 계속 이어가기 가능
	//왜 쓰냐? => 생성자 수정뿐만 아니라 버전이나 언어가 바뀌어도 동일한 방식 사용 가능
}