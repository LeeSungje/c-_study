#include<iostream>

using namespace std;

class Unit
{
	int x;
	int y;
public:

	Unit(int a, int b)
	{
		x= a;
		y= b;
	}
	void Print()
	{
		cout << x << ", " << y << "\n";	
	}
};

int main()
{
	Unit* pUnit = new Unit[2]{Unit(1,2), Unit(3,4)};
	
	pUnit->Print();
	(pUnit+1)->Print();
	
	(*pUnit).Print();
	(*(pUnit+1)).Print();
	
	pUnit[0].Print();
	pUnit[1].Print();
	
	delete[] pUnit;
	
	return 0;
}

