#include <iostream>

using namespace std;

struct TestStruct
{
private:
    char* username; 
    int userid;

public:
    void changeID(int input) {
        userid = input;
    }
    void printID() {
        cout << userid << endl;
    }
};

class TestClass
{
private:
    char* username;
    int userid;

public:
    void changeID(int input) {
        userid = input;
    }
    void printID() {
        cout << userid << endl;
    }
};

int main()
{
    TestStruct newStruct;       //struct는 public이 기본
    TestClass newClass;         //class는 private가 기본

    //newStruct.userid = 123;       //cpp에서 데이터를 건드리는건 별로 좋은 방식이 아님
    newStruct.changeID(123);        //함수를 추가해서 건드리는게 좋음
    newStruct.printID();

    newClass.changeID(123);
    newClass.printID();
}