#include <iostream>

using namespace std;

void powerset(int arr[], int flag[], int n, int depth){
	
	if(n==depth){
		for(int j=0; j<n; j++){
			if(flag[j]==1){
				cout << arr[j] << " ";
			}
		}
		cout << endl;
		return;
	}
	
	flag[depth]=0;
	powerset(arr, flag, n,depth+1);
	flag[depth]=1;
	powerset(arr, flag, n,depth+1);
	
}

int main(){
	
	
	int arr[100]={};
	int flag[100]={};
	int size;
	
	cout << "size(100¹Ì¸¸) : " ;
	cin >> size;
	
	for(int j=0; j<size; j++){
		arr[j]=j+1;
	}
	for(int j=0; j<size; j++){
		flag[j]=0;
	}
	
	powerset(arr, flag, size, 0);
	
	
	return 0;
}
