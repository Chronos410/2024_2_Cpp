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

	//����Ʈ ������
	cls() {}
	//����� ���� ������
	cls(int id, const char* name) 
	{
		//this ������ = ������ ��ü�� ������ ��
		this->id = id;
		//c��Ÿ��
		//this->pName = (char*)malloc(strlen(name) + 1);
		//c++��Ÿ��
		this->pName = new char[sizeof(name) + 1];

	
	}
	//����Ʈ �ı���
	~cls() 
	{
		//malloc ����
		//free(pName);
		//new ����
		//delete pName;



		std::cout << "����Ʈ �ı��� ȣ��" <<std::endl;
	}

	//���� ������

	//���� ������
	cls(cls& source) 
	{
		this->id = source.id;
	}
};
int main() {
	//
	cls MyClass;
	MyClass.init(1,"2");

	//����Ʈ ������ ��� ����
	cls MyClass2();

	//����� ���� ������ ���
	cls MyClass3(3,"s");
	cls* pMyClass3 = new cls(3,"33");
	cls& rpMyClass3 = MyClass3;

	//��ü ����
	cls MyClass4 = MyClass3; //���� ����� pName�� �����ؼ� ���� ������ �ִ� ������ ������.
	//�̶� �ϳ��� �޸� �����ϸ� �ٸ� �ϳ��� �����Ǽ� �ι� �������ϴ� ������ �߻�
	MyClass3.printID("obj3");
	MyClass4.printID("obj4");

	//���� ������ ���
	cls MyClass5(MyClass3);

}