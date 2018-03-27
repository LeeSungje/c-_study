#include <iostream>
#include <cstring>
using namespace std;

class Unit{
char *pszName;
public:
Unit(){
pszName = new char[255];
cout << "Normal Constructor\n";
}
~Unit(){
delete [ ] pszName;
}
Unit(const Unit &unit);
void Print(){
cout << pszName << "\n";
}
void Set(char* pszIn){
strcpy( pszName, pszIn );
}
};

Unit::Unit(const Unit &unit)
{
pszName = new char[255];
strcpy(pszName, "Untitled");
cout << "Copy Constructor\n";
}

int main()
{
Unit Zerg, Spawn;
Zerg.Set("zergling");
Zerg.Print();
Spawn=Zerg;
Spawn.Print();
return 0;
}

