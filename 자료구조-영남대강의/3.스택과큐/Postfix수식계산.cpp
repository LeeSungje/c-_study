#include <iostream>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

using namespace std;

typedef enum { 
	lparen, rparen, pluss, m, times,
	divide, mod, eos, operand
} precedence;

int stack [ MAX_STACK_SIZE ]; // global stack
char expr [ MAX_EXPR_SIZE ]; // input string
int top;

void push(int item){
	if(top==MAX_STACK_SIZE-1){
		cout << "stack is full";
		return;
	}
	stack[++top] = item;
}

int pop(){
	if(top==-1){
		cout << "stack is empty";
	}
	else{
		return stack[top--];
	}
}

precedence get_token (char &symbol, int &n)
{ // 수식 문자열에서 다음 문자를 검사하여 해당 token을 반환
	symbol = expr[n++];
	switch (symbol){
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return pluss;
		case '-' : return m;
		case '/' : return divide;
		case '*' : return times;
		case '%' : return mod;
		case 'q' : return eos;
		default : return operand; // 오류 검사 없음. 피연산자
	}
}

int eval (void)
{
	// expr[] 배열에 문자열로 저장된 postfix 수식 계산.
	// expr[]과 stack[], 그리고 top은 전역변수임.
	// get_token() 함수는 수식의 각 문자의 precedence를 return
	// 수식에서 피연산자는 한 문자로 구성된다고 가정.
	
	precedence token;
	char symbol;
	int op1, op2;
	int n=0;
	
	top=-1;
	
	token = get_token(symbol, n);
	
	while (token != eos){
		if (token == operand)
			push(symbol-'0'); // 피연산자를 만나면 스택에 저장	
		
		else{	// operator가 오면 stack에서 피연산자 2개를 제거한 후 이를 이용하여 
				//수식을 계산한 후 결과를 다시 stack에 저장
				
				op2 = pop(); 
				op1 = pop();
				
				switch (token) {
					case pluss : push(op1 + op2); break;
					case m : push(op1 -op2); break;
					case times : push(op1 * op2); break;
					case divide : push(op1 / op2); break;
					case mod : push(op1 % op2);
				}
		}
		token = get_token (symbol, n);
	}
	
	return pop(); //결과값 리턴 
}




int main(){
	
	char c;
	int i=0, result;
	
	cout << "수식을 입력해주세요(q는 끝내기)" << endl;
	cin >> c;
	while(c!='q'){
		expr[i++] = c;
		cin >> c;
	} 
	expr[i]=c;
	
	result = eval();
	
	cout << "결과 = " << result <<endl; 
	
}
