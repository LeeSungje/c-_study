#include<iostream>

using namespace std;

class Unit
{
private:
	int hp;
public:
	Unit() { hp=0; }
	Unit(int i):hp(i){}
	int GetHP()
	{
		return hp;
	}
	
	Unit operator+(Unit right);
	int operator!=(Unit right);
	Unit operator++();
	Unit operator++(int);
};

Unit Unit::operator+(Unit right)
{
	Unit temp;
	temp.hp = hp + right.hp;
	return temp;
}

int Unit::operator!=(Unit right)
{
if ( hp != right.GetHP() )
return 1;
else
return 0;
}

Unit Unit::operator++()
{
hp++;
return (*this);
}

Unit Unit::operator++(int)
{
	Unit temp;
	temp.hp = hp;
hp++;
return temp;
}

int main( )
{
Unit Unit1, Unit2, Unit3(10);
Unit1 = Unit3++;
Unit2 = ++Unit3;
cout << Unit1.GetHP()<<"\n";
cout << Unit2.GetHP()<<"\n";
return 0;
}
