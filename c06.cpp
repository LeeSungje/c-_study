#include<iostream>
#include<cstring>
using namespace std;

class Unit {
	char* str;
public:
	Unit()
	{
		cout << "I'm a default constructor\n";
		str = NULL;
	}
	Unit(char* agStr)
	{
		cout << "I'm a default constructor with parameters\n";
		int strLength = strlen(agStr);
		str = new char[strLength + 1];
		strcpy(str, agStr);
	}
	Unit(Unit& agUnit)
	{
		int len = strlen(agUnit.str);
		str = new char[len+1];
		strcpy(str, agUnit.str);
		cout << "I'm a copy constructor\n";
	}
	
	~Unit(){
		delete[] str;
	}
	
	void set(char* agStr) {
		strcpy(str, agStr);
	}
	
	void show()
	{
		cout << str << "\n";	
	}
};
		
int main(){
	
	Unit A("Unit A"), B("Unit B"), C("Unit C");
	A.show(); B.show(); C.show(); cout<<endl;
	A=B; 
	B=C;
	A.show(); B.show(); C.show(); cout<<endl;
	B.set("Unit B");
	A.show(); B.show(); C.show(); cout<<endl;

	return 0;
}
