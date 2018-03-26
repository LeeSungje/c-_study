#include<iostream>

using namespace std;

inline int inc(int x)
{
	return x+1;
}

int main(){
	
	int i;
	cin >> i;
	cout << inc(i) << endl;
	
	return 0;
	
}
