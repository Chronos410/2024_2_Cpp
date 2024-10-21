#include <iostream>
#include <string>

using namespace std;

class personC 
{
	int age;
public:
	personC(int age = 10) :age(age) 
	{
		cout << "생성자 호출"<<endl;
	}
	personC(const personC& input)
	{
		age = input.age;
		cout << "복사 생성자 호출" << endl;
	}
	void print(void);
	personC add(const personC& input);
	personC operator+(const personC& input);
	personC& operator=(const personC& input);	// 4대 자동 생성함수인 기본 복사대입연산자(얘만 레퍼런스타입임)
	//자동 생성 함수 / 생성자 소멸자 복사생성자 복사대입연산자
	
};

void personC::print() 
{
	cout << age << endl;
}
personC personC::add(const personC& input) 
{
	cout << "add 호출" << endl;
	personC temp(this->age + input.age);
	return temp;
}
personC personC::operator+(const personC& input) // operator를 사용한 연산자 오버로딩
{
	cout << "operator+ 호출" << endl;	
	personC temp(this->age + input.age);
	return temp;
}
personC& personC::operator=(const personC& input) // operator를 사용한 기본 복사대입연산자 오버로딩
{
	cout << "operator= 호출" << endl;
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
	//이게 하고싶음
	personC resultPerson;

	resultPerson = aPerson.add(bPerson);
	// C = C + C
	// C = (this) operator+ (C)
	// C = operator+(C)
	resultPerson.print();

	resultPerson = aPerson + bPerson;	//'+' 연산자 오버로딩 사용(모호하니까 만들어쓰진마)
	
	personC cPerson;
	resultPerson = cPerson;				//복사대입연산자 오버로딩 = 사용자 정의 복사대입연산자

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