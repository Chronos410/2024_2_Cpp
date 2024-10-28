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
	//정적 변수는 클래스 내에서 초기화 불가능(아마 여기 존재하는게 아니라 그런 듯)
	
private:
	int id, id2;
	char* pName;

public:
	inline void idOut(); // inline함수는 전처리기에서 함수호출부에 정의부를 그대로 입력시킴
	//심지어 해주세요~고 컴파일러가 꼭 해주진 않음
	//함수를 호출하는데 쓰이는 시간?을 줄일 수 있지만 코드 전체 길이가 늘어남
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
		delete pName; //안하면 메모리 누수가 생기겠지요?
	}

	myClass(const myClass& obj) 
	{
		id = obj.id;
		id2 = obj.id2;
		//pName = obj.pName;
		//얕은 복사 <- 주소만 복사
		pName = new char[10];
		strncpy(pName, obj.pName, 10);
		//깊은 복사 <- 새로 메모리를 할당해 값 저장
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