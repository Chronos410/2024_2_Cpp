#include<iostream>

class cls
{
	int id;

public:
	char* pName;
	void init(int id, const char* name){}
	void printID() 
	{
		std::cout << "ID : " << id << std::endl; 
		if (pName != NULL)
			std::cout << "Name : " << this->pName << std::endl;
	}
	void printID(const char* str) {

		std::cout << str << "ID : " << id << std::endl;

		if(pName!=NULL)
			std::cout << str << "Name : " << this->pName << std::endl;
	}

	//디폴트 생성자
	cls() {}
	//사용자 정의 생성자
	cls(int id, const char* name) 
	{
		//this 포인터 = 생성된 객체가 가지는 값
		this->id = id;
		//c스타일
		//this->pName = (char*)malloc(strlen(name) + 1);
		//c++스타일
		this->pName = new char[sizeof(name) + 1];

	
	}
	//디폴트 파괴자
	~cls() 
	{
		//malloc 해제
		//free(pName);
		//new 해제
		//delete pName;



		std::cout << "디폴트 파괴자 호출" <<std::endl;
	}

	//대입 연산자

	//복사 생성자
	cls(cls& source) 
	{
		this->id = source.id;
	}
};
int main() {
	//
	cls MyClass;
	MyClass.init(1,"2");

	//디폴트 생성자 사용 구문
	cls MyClass2();

	//사용자 정의 생성자 사용
	cls MyClass3(3,"s");
	cls* pMyClass3 = new cls(3,"33");
	cls& rpMyClass3 = MyClass3;

	//객체 대입
	cls MyClass4 = MyClass3; //얕은 복사로 pName을 복사해서 같은 공간에 있는 내용을 공유함.
	//이때 하나가 메모리 해제하면 다른 하나도 해제되서 두번 해제당하는 오류가 발생
	MyClass3.printID("obj3");
	MyClass4.printID("obj4");

	//복사 생성자 사용
	cls MyClass5(MyClass3);

}