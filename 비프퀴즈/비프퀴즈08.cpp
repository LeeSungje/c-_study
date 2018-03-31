#include<iostream>

using namespace std;

template<typename T1, typename T2>
class calc{
private:
	T1 a;
	T2 b;
public:
	calc(T1 _a, T2 _b){
		a = _a;
		b= _b;
	}
	T1 add(){
		return a+b;
	}
	T2 mul(){
		return a*b;
	}
};

int main(){
	
	calc<int, float> A(2.1, 3.1f);
	calc<double, int> B(2.1, 3.1);
	calc<double, float> C(2.1, 3.1f);
	
	cout<<"A add="<<A.add()<<endl;
	cout<<"B add="<<B.add()<<endl;
	cout<<"C add="<<C.add()<<endl;
	cout<<"A mul="<<A.mul()<<endl;
	cout<<"B mul="<<B.mul()<<endl;
	cout<<"C mul="<<C.mul()<<endl;		
	
	return 0;
}
