#include<iostream>

#define MAX_TERMS 101 

using namespace std;

typedef struct {
	float coef; //계수
	int expon; //지수 
}polynomial;

polynomial terms[MAX_TERMS];

int avail = 0;

int Compare(int x, int y){
	if(x<y) return -1;
	else if(x==y) return 0;
	else return 1;
}

void Input(float coefficient, int exponent){
	if (avail >= MAX_TERMS) {
		cout << "Too many terms in the polynomial" << endl;  //예외처리 
		return;
	}
	
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}


//startd, finishd는 주소전달로 받아야함! 
void polynomialAdd(int starta, int finisha, int startb, int finishb, int &startd, int &finishd){
	
	float coefficient;
	startd=avail;
	
	while(starta<=finisha && startb<=finishb){
		switch(Compare(terms[starta].expon, terms[startb].expon)){
			case -1:
				Input(terms[startb].coef, terms[startb].expon);
				startb++;
				break;
				
			case 0:
				coefficient = terms[starta].coef + terms[startb].coef;
				if(coefficient == 0) break; //더했는데 0이면 넣을 필요 없음 
				Input(coefficient, terms[startb].expon);
				starta++; startb++;
				break;
				
			case 1:
				Input(terms[starta].coef, terms[starta].expon);
				starta++;
				break;
			
			default:
				break;
		}
	}
	
	//a나 b 둘 중 하나때문에 while이 끝났을 수도 있기 때문에, 나머지 남은 부분 d에 넣어주면서 해결 
	for(int i=starta; i<=finisha; i++){
		Input(terms[i].coef, terms[i].expon);
	}
	
	for(int i=startb; i<=finishb; i++){
		Input(terms[i].coef, terms[i].expon);
	}
	
	finishd = avail-1;
}

int main(){
	
	int starta, finisha, startb, finishb, startd, finishd;
	int x,y;
	
	starta = 0;
	
	cout << "첫번째 다항식 입력" << endl;
	cin >> x >> y;
	
	while(x!=0 || y!=0){	// 0 0 입력되면 첫번째 다항식 입력 끝났다는 뜻 
		terms[avail].coef = x;
		terms[avail++].expon = y;
		
		cin >> x >> y;
	}
	
	finisha = (avail <= 0) ? avail : avail-1;
	startb = avail;
	
	cout << "두번째 다항식 입력" << endl;
	cin >> x >> y;
	
	while(x!=0 || y!=0){
		terms[avail].coef = x;
		terms[avail++].expon = y;
		
		cin >> x >> y;
	}
	
	finishb = (avail <= 0) ? avail : avail-1;
	startd = avail;
	
	polynomialAdd(starta, finisha, startb, finishb, startd, finishd);
	
	for(int i=0; i<avail; i++){
		cout << terms[i].coef << " , " << terms[i].expon << endl;
	}
	
	
	
	return 0;
}
