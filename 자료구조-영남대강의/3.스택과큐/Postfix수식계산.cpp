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
{ // ���� ���ڿ����� ���� ���ڸ� �˻��Ͽ� �ش� token�� ��ȯ
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
		default : return operand; // ���� �˻� ����. �ǿ�����
	}
}

int eval (void)
{
	// expr[] �迭�� ���ڿ��� ����� postfix ���� ���.
	// expr[]�� stack[], �׸��� top�� ����������.
	// get_token() �Լ��� ������ �� ������ precedence�� return
	// ���Ŀ��� �ǿ����ڴ� �� ���ڷ� �����ȴٰ� ����.
	
	precedence token;
	char symbol;
	int op1, op2;
	int n=0;
	
	top=-1;
	
	token = get_token(symbol, n);
	
	while (token != eos){
		if (token == operand)
			push(symbol-'0'); // �ǿ����ڸ� ������ ���ÿ� ����	
		
		else{	// operator�� ���� stack���� �ǿ����� 2���� ������ �� �̸� �̿��Ͽ� 
				//������ ����� �� ����� �ٽ� stack�� ����
				
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
	
	return pop(); //����� ���� 
}




int main(){
	
	char c;
	int i=0, result;
	
	cout << "������ �Է����ּ���(q�� ������)" << endl;
	cin >> c;
	while(c!='q'){
		expr[i++] = c;
		cin >> c;
	} 
	expr[i]=c;
	
	result = eval();
	
	cout << "��� = " << result <<endl; 
	
}
