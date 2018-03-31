#include<iostream>

using namespace std;

class Unit{
private:
	int x;
	int y;
public:
	Unit(){
		x=3;
		y=3;
	}
	Unit(int _x){
		x = _x;
		y = 3;
	}
	Unit(int _x, int _y){
		x = _x;
		y = _y;
	}
	Unit(Unit& unit){
		x = unit.x+2;
		y = unit.y+2;
	}
	
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
};

int main(){
	
	Unit a, b(5), c(4,4);
	a = b;
	b = c;
	Unit d(c);
	
	
	cout << "a.x = " << a.getX() << endl;
	cout << "b.x = " << b.getX() << endl;
	cout << "d.x = " << d.getX() << endl;
	
	cout << "a.y = " << a.getY() << endl;
	cout << "b.y = " << b.getY() << endl;	
	cout << "d.y = " << d.getY() << endl;
	
	return 0;
}
