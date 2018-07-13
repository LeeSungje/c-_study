#include <iostream>

using namespace std;

void swap(int &x, int &y){
	int temp;
	temp = x;
	x=y;
	y=temp;
}

void permutation(int arr[], int i, int n){
	
	int j;
	
	if(i==n){
		for(j=0; j<=n; j++)
			cout << arr[j] << " ";
		cout << endl;
	}
	
	for(j=i; j<=n; j++){
		swap(arr[i], arr[j]);
		permutation(arr, i+1, n);
		swap(arr[i], arr[j]);
	}	
}

int main(){
	
	int arr[100]={};
	int size;
	
	cout << "size(100¹Ì¸¸) : " ;
	cin >> size;
	
	for(int j=0; j<size; j++){
		arr[j]=j+1;
	}
		
	permutation(arr, 0, size-1);
	
	return 0;	
}
