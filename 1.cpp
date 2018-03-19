#include<iostream>
#include<cstring>

using namespace std;

class Unit{
 
public:
 
 char *str;
  	
 Unit(char* agStr)
 {
 int strLength = strlen(agStr);
 str = new char[strLength + 1];
 strcpy(str, agStr);
 }
 
 show(){
 	cout << str << endl;
 }
 
 copyFrom(Unit& x){
 	str = x.str;
 }
	
};


 
 
int main(){
	
	Unit A("Unit A"), B("Unit B"), C("Unit C");
	
	A.show(); B.show(); C.show(); cout<<endl;
}
