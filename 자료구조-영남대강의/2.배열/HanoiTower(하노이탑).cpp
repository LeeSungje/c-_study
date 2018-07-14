#include<iostream>

using namespace std;

void hanoi(int n, int from, int tmp, int to){
	
	if(n==1){
		cout << n << "번째 원판 : " << from << " --> " << to << endl;
	}
	
	else if(n > 1){
		hanoi(n-1, from, to, tmp);
		cout << n << "번째 원판 : " << from << " --> " << to << endl;	
		hanoi(n-1, tmp, from, to);
	}
	
}

int main(){
	
	int num;
	
	cout << "Enter size : " ;
	cin >> num;
	
	hanoi(num,1,2,3);
		
	return 0;
}
