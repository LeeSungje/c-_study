#include<iostream>

using namespace std;

class Square{
	int h,w;
public:
	Square(int x, int y){
		h = x;
		w = y;
	}
	
	friend void addSquare(Square &s1, Square &s2);

};

void Square(Square &s1, Square &s2){
	cout << "Sum : "  << s1.h*s1.w + s2.h*s2.w << endl;
}

int main(){
	Square A(5,3), B(4,4);
	addSquare(A, B);
	
	return 0;
}
