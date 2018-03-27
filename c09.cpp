#include<iostream>

using namespace std;

class Unit
{
	int x;
	int y;
public:
	Unit *p;
	Unit(int x, int y, Unit *p)
	{
		this->x = x;
		this->y = y;
		this->p = p;
	}
	void Print()
	{
		if(p!=NULL)
			p->Print();
			
		cout << x << ", " << y << "\n";
		
	}
};

int main()
{
	Unit c(5, 6, NULL);
	Unit b(3, 4, &c);
	Unit a(1, 2, &b) ;
	cout<<"[Print a]"<<endl; 
	a.Print();
	cout<<"[Print b]"<<endl; 
	b.Print();
	cout<<"[Print c]"<<endl; 
	c.Print();

	return 0;
}

