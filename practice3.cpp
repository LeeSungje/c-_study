#include <iostream>
#include <cstring>
using namespace std;

class Student{
private:
    char name[10];
    int age;
    int ID;
public:
    Student(char * _name, int _age, int _ID) : age(_age), ID(_ID){  //멤버이니셜라이저
        strcpy(name, _name);
    }
    void GetInfo(){
        cout << name << " " << age << " " << ID << endl;
    }
};

int main(){
    Student * stu[3];   //객체 포인터 배열
    char name[10];
    int age, ID;

    for(int i=0; i<3; i++){
      cin >> name >> age >> ID;
      stu[i] = new Student(name, age, ID);    //객체 포인터 배열
    }

    for(int i=0; i<3; i++){
      stu[i]->GetInfo();
    }

    delete stu[0];
    delete stu[1];
    delete stu[2];

    return 0;
}
