#include<iostream>
#include<cstring>

using namespace std;
class Unit
{
private:
int hp;
int mp;
int unitSize;
char* name;
public:
Unit()
{
hp = 0;
mp = 0;
unitSize = 0;
name = NULL;
}
Unit(int argHp, int argMp, int argSize, const char* argName)
: hp(argHp), mp(argMp), unitSize(argSize)
{
name = new char[strlen(argName) + 1];
strcpy(name, argName);
}
~Unit()
{
if (!name)
{
delete[ ] name;
name = NULL;
}
}
public:
int GetSize()
{
return unitSize;
}
int operator+(Unit right);

};

int Unit::operator+(Unit right)
{
return GetSize() + right.GetSize();
}



class HUnit : public Unit
{
public:
HUnit()
: Unit(45, 125, 2, "HUnit")
{}
};

void funcUnit(Unit a)
{
cout<<a.GetSize() ;
}
void funcHUnit(HUnit a)
{
cout<<a.GetSize() ;
}


int main()
{
HUnit a;
funcHUnit(a);
return 0;
}
