#include<iostream>

#define MAX_TERMS 50

using namespace std;

typedef struct{
	int row;
	int col;
	int value;
}SparseMat;

int origin[MAX_TERMS][MAX_TERMS];
SparseMat a[MAX_TERMS*MAX_TERMS];
SparseMat b[MAX_TERMS*MAX_TERMS];
int avail_a, avail_b;

void createSparseMat(int rows, int cols){
	avail_a = 1;
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(origin[i][j]==0) continue;
			a[avail_a].row = i;
			a[avail_a].col = j;
			a[avail_a++].value = origin[i][j];
		}
	}
	a[0].row = rows;
	a[0].col = cols;
	a[0].value = avail_a-1;
}

void transpose(){
		
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	if(a[0].value > 0){
		avail_b = 1;
		for(int i=0; i<a[0].col; i++){
			for(int j=1; j<=a[0].value; j++){
				if(i == a[j].col){
					b[avail_b].row = a[j].col;
					b[avail_b].col = a[j].row;
					b[avail_b++].value = a[j].value;
				}
			}
		}
	}
}

void fastTrans(){
	
	int rowterms[MAX_TERMS];
	int num_col = a[0].col, num_value = a[0].value;
	
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	if(num_value > 0){
		for(int i=0; i<num_col; i++){
			rowterms[i]=0;
		}
		
		for(int i=1; i<=num_value; i++){ //각 col에 몇개의 value가 있는지 세서 rowterms에 저장 
			rowterms[a[i].col]++;
		}
		
		int temp1=1, temp2;
		for(int i=0; i<num_col; i++){  //rowterms에서 starting_pos로 바꾸기 
			temp2 = rowterms[i];
			rowterms[i]=temp1;
			temp1 += temp2;
		}
		
		int position_b;
		for(int i=1; i<=num_value; i++){
			position_b = rowterms[a[i].col]++; //starting_pos로부터 어디로 들어가는지 정보 알수있음 
			b[position_b].row = a[i].col;
			b[position_b].col = a[i].row;
			b[position_b].value = a[i].value;
		}
	}	
}

int main(){
	
	int rows=0, cols=0, row, col;
	
	cout << "Input array size (rows cols): " ;
	cin >> rows >> cols;
	
	for(row=0; row<rows; row++){
		for(col=0; col<cols; col++){
			cin >> origin[row][col];
		}
	}
	
	createSparseMat(rows, cols);
	//transpose();
	fastTrans();
	
	for(int i=0; i<=a[0].value; i++){
		cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	}
	cout << endl;
	for(int i=0; i<=b[0].value; i++){
		cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
	}
	
	
	return 0;
}
