#include <iostream>
#include <string.h>
#include <iomanip>

#define M 11
#define P 15
#define MAX_STACK_SIZE M*P // = m × p

using namespace std;

typedef struct{
	int x;
	int y;
}offset;

offset move[8]; //8방향 구현위해 사용


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


//미로를 통과하는 경로가 존재할 경우, 이를 출력하는 함수 
void path(){
	int i, row, col, next_row, next_col, dir;
	int found = 0; //경로 찾으면 1 되는 flag 
	element position; //현재 위치 
	
	mark[1][1] = 1; //출발하는 곳 -> 지나니깐 mark에 1로 셋팅
	top = 0; // 출발하는 곳 스택에 넣을 것이니깐 top 증가 
	stack[0].row=1; stack[0].col=1; stack[0].dir = 2; //처음에 동쪽 부터 검사하게 하려고!  
	
	while(top>-1 && !found){ //stack이 empty이거나, 경로를 찾을때까지 반복  
		position = pop();
		row = position.row; col = position.col;
		dir = position.dir;	
		
		while(dir<8 && !found){ //8방향 검사 
			next_row = row + move[dir].x; // move in direction dir
			next_col = col + move[dir].y;
			if (next_row == Exit_row && next_col == Exit_col){
				found = 1;
			}
			
			else if (maze[next_row][next_col]==0 && mark[next_row][next_col]==0){ //길이 있으면서 아직 거치지 않은 곳이면 
				
				mark[next_row][next_col] = 1; //가본길이라고 마크함 
				position.row = row;
				position.col = col;
				position.dir = ++dir; //만약 길이없어 되돌아 오면 그 갔던 방향말고 다음 방향부터 다시 검사하도록 하기 위해!
				push(position);
				row = next_row;
				col = next_col;
				dir = 0;
				
			}
			else ++dir;
		}
	}
	
	if(found){ //경로를 찾으면 
		cout <<	"The path is : \n";
		cout << "row  col \n";
		
		for(int i=0; i<=top; i++)
			cout << setw(2) << stack[i].row << setw(5) << stack[i].col << endl;
		
		cout << setw(2) << row << setw(5) << col << endl; //가장 최근 pop시켰던 위치 
		cout << setw(2) << Exit_row << setw(5) << Exit_col << endl;; //마지막 출구 위치 
		
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
