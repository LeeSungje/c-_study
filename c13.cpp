#include<iostream>

using namespace std;


class Triangle
{
	int width;
	int height;
public:
	Triangle(){}
	Triangle(int argWidth, int argHeight):width(argWidth), height(argHeight){}
	int GetWidth()
	{
		return width;
	}
	int GetHeight()
	{
		return height;
	}
};

class Square
{
private:
	int width;
public:
	Square(){}
	Square(int argSide):width(argSide){}
public:
	int GetWidth()
	{
		return width;
	}
};

class Circle
{
	int radius;
public:
	Circle(){}
	Circle(int argRadius)
	:radius(argRadius)
	{}
public:
	int GetRadius()
	{
		return radius;
	}
};

int Calculate(Triangle t){
	return 0.5*t.GetHeight()*t.GetWidth();
}

int Calculate(Square s){
	return s.GetWidth()*s.GetWidth();
}

double Calculate(Circle c){
	return c.GetRadius()*c.GetRadius()*3.14;
}

int main()
{
	Triangle tri(5, 2);
	Square square(5);
	Circle circle(5);
	
	cout << "Area of Triangle = " << Calculate(tri) << endl;
	cout << "Area of Square = " << Calculate(square) << endl;
	cout << "Area of Circle = " << Calculate(circle) << endl;


	return 0;

}
