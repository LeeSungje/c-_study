#include <iostream>
#include <cstring>

using namespace std;

class MyClass{
private:
      char *str;

public:
      MyClass(const char *astr){    //생성자
          str = new char[strlen(astr)+1];
          strcpy(str, astr);
      }

      MyClass(const MyClass& mc){    //복사 생성자
          str = new char[strlen(mc.str)+1];
          strcpy(str, mc.str);
      }

      ~MyClass(){   //소멸자
          delete []str;
          cout << "~소멸자 호출됨" << endl;
      }

      void ShowData(){
          cout << str << endl;
      }
};

int main(){

    MyClass mc1("Myclass!!!!!");
    MyClass mc2 = mc1;

    mc1.ShowData();
    mc2.ShowData();

    return 0;
}
