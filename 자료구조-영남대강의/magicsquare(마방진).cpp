#include <iostream>

using namespace std;


int main(){
	
	int arr[100][100]={};
	int size;
	
	cout << "size(100미만) : " ;
	cin >> size;
	
	if(size%2==0){
		cout << "홀수 크기를 정해주세요." ;
		return 0;
	}
	
	for(int i=0; i< size; i++){
		for(int j=0; j< size; j++){
			arr[i][j]=0;
		}
	}
	
	int row = 0;
	int col = (size-1)/2;
	arr[row][col]=1;
	
	for(int i=2; i<=size*size; i++){
		row = (row == 0) ? size-1 : row-1;
		col = (col == 0) ? size-1 : col-1;
		
		if(arr[row][col] == 0){
			arr[row][col]=i;
		}
		else{
			if(row == size-1){
				row = 1;
			}
			else if(row == size-2){
				row=0;
			}
			else{
				row = row+2;
			}
			col = (col == size-1) ? 0 : col+1;
			arr[row][col]=i;
		}
	}
	
	for(int i=0; i< size; i++){
		for(int j=0; j< size; j++){
			cout.width(5);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
