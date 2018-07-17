#include <iostream>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

using namespace std;

typedef enum { 
	lparen, rparen, pluss, m, times,
	divide, mod, eos, operand
} precedence;

int postfix_stack [ MAX_STACK_SIZE ]; // global stack
precedence operator_stack[MAX_STACK_SIZE];
char expr [ MAX_EXPR_SIZE ]; // ���ĳ��� �迭
char expr2 [MAX_EXPR_SIZE]; // postfix�� �ٲ� ���� 
int index=0;
int postfix_stack_top, operator_stack_top;

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0}; //stack�� ����� �������� �켱����
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0}; //�Է� �������� �켱����

void push1(int item){
	if(postfix_stack_top==MAX_STACK_SIZE-1){
		cout << "postfix_stack is full";
		return;
	}
	postfix_stack[++postfix_stack_top] = item;
}

int pop1(){
	if(postfix_stack_top==-1){
		cout << "postfix_stack is empty";
	}
	else{
		return postfix_stack[postfix_stack_top--];
	}
}

void push2(precedence item){
	if(operator_stack_top==MAX_STACK_SIZE-1){
		cout << "operator_stack is full";
		return;
	}
	operator_stack[++operator_stack_top] = item;
}

int pop2(){
	if(operator_stack_top==-1){
		cout << "operator_stack is empty";
	}
	else{
		return operator_stack[operator_stack_top--];
	}
}

precedence get_token (char &symbol, int &n, char arr[])
{ // ���� ���ڿ����� ���� ���ڸ� �˻��Ͽ� �ش� token�� ��ȯ
	symbol = arr[n];
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
	
	postfix_stack_top=-1;
	
	token = get_token(symbol, n, expr2);
	
	while (token != eos){
		if (token == operand)
			push1(symbol-'0'); // �ǿ����ڸ� ������ ���ÿ� ����	
		
		else{	// operator�� ���� stack���� �ǿ����� 2���� ������ �� �̸� �̿��Ͽ� 
				//������ ����� �� ����� �ٽ� stack�� ����
				
				op2 = pop1(); 
				op1 = pop1();
				
				switch (token) {
					case pluss : push1(op1 + op2); break;
					case m : push1(op1 -op2); break;
					case times : push1(op1 * op2); break;
					case divide : push1(op1 / op2); break;
					case mod : push1(op1 % op2);
				}
		}
		token = get_token (symbol, ++n, expr2);
	}
	
	return pop1(); //����� ���� 
}


//infix -> postfix ��ȯ 
void infixTopostfix(){
	
	precedence token;
	char symbol;
	int n=0;
	
	operator_stack_top = -1;
	
	token = get_token(symbol, n, expr);
	
	while(token != eos){
		
		if(token==operand){
			cout << expr[n] << " ";
			expr2[index++]=expr[n];
		}
		
		else if(token==rparen){
			while(operator_stack[operator_stack_top]!=lparen){
				switch (operator_stack[operator_stack_top]) {
					case pluss : expr2[index++] = '+'; cout<<"+ "; break;
					case m : expr2[index++] = '-'; cout<<"- "; break;
					case times : expr2[index++] = '*'; cout<<"* "; break;
					case divide : expr2[index++] = '/'; cout<<"/ "; break;
					case mod : expr2[index++] = '%'; cout<<"% ";
				}
				pop2();
			}
			pop2();
		}
		
		else{
			while(isp[operator_stack[operator_stack_top]] >= icp[token]){
				switch (operator_stack[operator_stack_top]) {
					case pluss : expr2[index++] = '+'; cout<<"+ "; break;
					case m : expr2[index++] = '-'; cout<<"- "; break;
					case times : expr2[index++] = '*'; cout<<"* "; break;
					case divide : expr2[index++] = '/'; cout<<"/ "; break;
					case mod : expr2[index++] = '%'; cout<<"% ";
				}
				pop2();
			}
			push2(token);
		}
		
		token = get_token (symbol, ++n, expr);
	}
	while(operator_stack_top >=0){
		switch (operator_stack[operator_stack_top]) {
			case pluss : expr2[index++] = '+'; cout<<"+ "; break;
			case m : expr2[index++] = '-'; cout<<"- "; break;
			case times : expr2[index++] = '*'; cout<<"* "; break;
			case divide : expr2[index++] = '/'; cout<<"/ "; break;
			case mod : expr2[index++] = '%'; cout<<"% ";
		}
		pop2();
	}
	expr2[index] = 'q';
}


int main(){
	
	char c;
	int i=0, result;
	
	cout << "Infix ���� ������ �Է����ּ���(q�� ������)" << endl;
	cin >> c;
	while(c!='q'){
		expr[i++] = c;
		cin >> c;
	} 
	expr[i]=c;
	
	infixTopostfix();
	
	result = eval();
	
	cout << "��� = " << result <<endl; 
	
}
