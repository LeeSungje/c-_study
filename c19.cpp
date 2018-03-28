#include<iostream>
#include<cstring>

using namespace std;

template<typename T1, typename T2>
class calc {
	T1 a;
	T2 b;
public:
	calc(T1 _a, T2 _b);
	T1 add();
	T1 mul();
};

template<typename T1, typename T2>
calc<T1, T2>::calc(T1 _a, T2 _b){
	a=_a; b=_b;
}

template<typename T1, typename T2>
T1 calc<T1, T2>::add(){
	return a+b;
}

template<typename T1, typename T2>
T1 calc<T1, T2>::mul(){
	return a*b;
}

int main()
{
	calc<int,double> iCalc(2,3.1);
calc<float,int> fCalc(2.1f,3);
calc<double,float> dCalc(2.1,3.1f);
cout<<"iCalc add="<<iCalc.add()<<endl;
cout<<"fCalc add="<<fCalc.add()<<endl;
cout<<"dCalc add="<<dCalc.add()<<endl;
cout<<"iCalc mul="<<iCalc.mul()<<endl;
cout<<"fCalc mul="<<fCalc.mul()<<endl;
cout<<"dCalc mul="<<dCalc.mul()<<endl;

return 0;
}
