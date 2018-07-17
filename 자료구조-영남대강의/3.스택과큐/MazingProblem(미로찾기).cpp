#include <iostream>
#include <string.h>
#include <iomanip>

#define M 11
#define P 15
#define MAX_STACK_SIZE M*P // = m �� p

using namespace std;

typedef struct{
	int x;
	int y;
}offset;

offset move[8]; //8���� �������� ���


typedef struct {
 	int row;
 	int col;
	int dir;
} element;

element stack[MAX_STACK_SIZE];  

int maze[M+2][P+2];
int mark[M+2][P+2];
int top=-1;
int Exit_row = M;
int Exit_col = P;

int is_empty(){
	if(top==-1) return 1;
	return 0;
}

void push(element item){
	if(top==MAX_STACK_SIZE-1){
		cout << "stack is full";
		return;
	}
	stack[++top] = item;
}

element pop(){
	if(is_empty()){
		cout << "stack is empty";
	}
	else{
		return stack[top--];
	}
}


//�̷θ� ����ϴ� ��ΰ� ������ ���, �̸� ����ϴ� �Լ� 
void path(){
	int i, row, col, next_row, next_col, dir;
	int found = 0; //��� ã���� 1 �Ǵ� flag 
	element position; //���� ��ġ 
	
	mark[1][1] = 1; //����ϴ� �� -> �����ϱ� mark�� 1�� ����
	top = 0; // ����ϴ� �� ���ÿ� ���� ���̴ϱ� top ���� 
	stack[0].row=1; stack[0].col=1; stack[0].dir = 2; //ó���� ���� ���� �˻��ϰ� �Ϸ���!  
	
	while(top>-1 && !found){ //stack�� empty�̰ų�, ��θ� ã�������� �ݺ�  
		position = pop();
		row = position.row; col = position.col;
		dir = position.dir;	
		
		while(dir<8 && !found){ //8���� �˻� 
			next_row = row + move[dir].x; // move in direction dir
			next_col = col + move[dir].y;
			if (next_row == Exit_row && next_col == Exit_col){
				found = 1;
			}
			
			else if (maze[next_row][next_col]==0 && mark[next_row][next_col]==0){ //���� �����鼭 ���� ��ġ�� ���� ���̸� 
				
				mark[next_row][next_col] = 1; //�������̶�� ��ũ�� 
				position.row = row;
				position.col = col;
				position.dir = ++dir; //���� ���̾��� �ǵ��� ���� �� ���� ���⸻�� ���� ������� �ٽ� �˻��ϵ��� �ϱ� ����!
				push(position);
				row = next_row;
				col = next_col;
				dir = 0;
				
			}
			else ++dir;
		}
	}
	
	if(found){ //��θ� ã���� 
		cout <<	"The path is : \n";
		cout << "row  col \n";
		
		for(int i=0; i<=top; i++)
			cout << setw(2) << stack[i].row << setw(5) << stack[i].col << endl;
		
		cout << setw(2) << row << setw(5) << col << endl; //���� �ֱ� pop���״� ��ġ 
		cout << setw(2) << Exit_row << setw(5) << Exit_col << endl;; //������ �ⱸ ��ġ 
		
	}
	
	else{
		cout << "The maze does not have a path \n ";
	}
}


int main(){
	
	/*for(int j=0; j<P+2; j++){
		maze[0][j]=1;
		maze[M+1][j]=1;
		maze[j][0]=1;
		maze[j][P+1]=1;
	}*/
	
	for(int i=0; i<M+2; i++){
		for(int j=0; j<P+2; j++){
			maze[i][j]=1;
			mark[i][j]=0;
		}
	}
	
	for(int i=1; i<=M; i++){
		for(int j=1; j<=P; j++){
			cin >> maze[i][j];
		}
	}
	
	move[0].x = -1; move[0].y = 0;
	move[1].x = -1; move[1].y = 1;
	move[2].x = 0; move[2].y = 1;
	move[3].x = 1; move[3].y = 1;
	move[4].x = 1; move[4].y = 0;
	move[5].x = 1; move[5].y = -1;
	move[6].x = 0; move[6].y = -1;
	move[7].x = -1; move[7].y = -1;
	
	path(); 
	
	return 0;
} 
