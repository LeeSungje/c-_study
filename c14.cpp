#include<iostream>

using namespace std;

class Unit
{
int level, type;
public:
Unit()
{
level=0; type=0;
}
Unit(int n, int m)
{
level=n; type=m;
}
int GetLevel()
{
return level;
}
int GetType()
{
return type;
}
};

int main()
{
Unit A[4];
Unit B[4] = {Unit(1,2), Unit(3,4), Unit(5,6), Unit(7,8)};
int i;

for(i=0;i<4;i++)
{
cout << "A[" << i << "] : " << A[i].GetLevel() << "," << A[i].GetType()<< "\n";
cout << "B[" << i << "] : " << B[i].GetLevel() << "," << B[i].GetType()<< "\n";
}
return 0;}
