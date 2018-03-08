#include <iostream>

using namespace std;

class student{
private:
    char * name;
    int age;
    char * hobby;

public:
      student(char * _name, int _age, char * _hobby);
      void ShowInfo();
      void Study();
      void Sleep();
};

student::student(char * _name, int _age, char * _hobby){
      name = _name;
      age = _age;
      hobby = _hobby;
}

void student::ShowInfo(){
      cout << "이름: " << name << ", 나이: " << age << ", 취미: " << hobby << endl;
}

void student::Study(){
      cout << "공부!" << endl;
}

void student::Sleep(){
      cout << "잠!" << endl;
}

int main(){

    student stu("이성제", 25, "농구");

    stu.ShowInfo();
    stu.Study();
    stu.Sleep();

    return 0;
}
