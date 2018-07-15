#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct {
	float coef; //���
	int expon; //���� 
}polynomial;

// int avail = 0;

/*
int Compare(int x, int y){
	if(x<y) return -1;
	else if(x==y) return 0;
	else return 1;
}

void Input(float coefficient, int exponent){
	if (avail >= MAX_TERMS) {
		cout << "Too many terms in the polynomial" << endl;  //����ó�� 
		return;
	}
	
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}


//startd, finishd�� �ּ����޷� �޾ƾ���! 
void polynomialAdd1(int starta, int finisha, int startb, int finishb, int &startd, int &finishd){
	
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
				if(coefficient == 0) break; //���ߴµ� 0�̸� ���� �ʿ� ���� 
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
	
	//a�� b �� �� �ϳ������� while�� ������ ���� �ֱ� ������, ������ ���� �κ� d�� �־��ָ鼭 �ذ� 
	for(int i=starta; i<=finisha; i++){
		Input(terms[i].coef, terms[i].expon);
	}
	
	for(int i=startb; i<=finishb; i++){
		Input(terms[i].coef, terms[i].expon);
	}
	
	finishd = avail-1;
}
*/

int Compare(int x, int y){
	if(x<y) return -1;
	else if(x==y) return 0;
	else return 1;
}

void Input(polynomial *tmp2, int &tmp2_avail, float coefficient, int exponent){
	
	tmp2[tmp2_avail].coef = coefficient;
	tmp2[tmp2_avail++].expon = exponent;
}

//tmp�� result�� ���� tmp2�� ����, �״��� tmp2 ������ result�� �ű� 
void polynomialAdd2(polynomial *result, polynomial *tmp, int start_tmp, int finish_tmp, int start_result, int &finish_result, polynomial *tmp2, int &tmp2_avail){
	
	float coefficient;
		
	while(start_tmp<=finish_tmp && start_result<=finish_result){
		switch(Compare(result[start_result].expon, tmp[start_tmp].expon)){
			case -1:
				Input(tmp2, tmp2_avail, tmp[start_tmp].coef, tmp[start_tmp].expon);
				start_tmp++;
				break;
				
			case 0:
				coefficient = result[start_result].coef + tmp[start_tmp].coef;
				if(coefficient == 0) break; //���ߴµ� 0�̸� ���� �ʿ� ���� 
				Input(tmp2, tmp2_avail, coefficient, tmp[start_tmp].expon);
				start_result++; start_tmp++;
				break;
				
			case 1:
				Input(tmp2, tmp2_avail, result[start_result].coef, result[start_result].expon);
				start_result++;
				break;
			
			default:
				break;
		}
	}
	
	//tmp�� result �� �� �ϳ������� while�� ������ ���� �ֱ� ������, ������ ���� �κ� tmp2�� �־��� 
	for(; start_tmp<=finish_tmp; start_tmp++){
		Input(tmp2, tmp2_avail, tmp[start_tmp].coef, tmp[start_tmp].expon);
	}
	
	for(int i = start_result; i <=finish_result; i++){
		Input(tmp2, tmp2_avail, result[i].coef, result[i].expon);
	}
	
	
	//tmp2�� result�� �ֱ����� result �ʱ�ȭ
	for(int i=0; i<=finish_result; i++){
		result[i].coef = 0;
		result[i].expon = 0;
	} 
	
	
	//tmp2�� result�� �ֱ� 
	for(int i=0; i<tmp2_avail; i++){
		result[i].coef = tmp2[i].coef;
		result[i].expon = tmp2[i].expon;
	}
	
	finish_result = tmp2_avail-1;
	tmp2_avail = 0;
}

void polynomialMul(polynomial *a, polynomial *b, polynomial *result, polynomial *tmp, int size_a, int size_b, int &finish_result){

	int start_result=0; 
	finish_result=-1;
	
	polynomial *tmp2 = new polynomial[size_a*size_b];
	
	//�ʱ�ȭ 
	for(int i=0; i<size_a*size_b; i++){
		tmp2[i].coef=0;
		tmp2[i].expon=0;
	}
	
	int tmp2_avail = 0;
	
	if(size_a > 0 && size_b > 0){
		
		for(int i=0; i<size_a; i++){
			for(int j=0; j<size_b; j++){
				tmp[j].coef = a[i].coef * b[j].coef;
				tmp[j].expon = a[i].expon + b[j].expon;
			}
			polynomialAdd2(result, tmp, 0, size_b-1, start_result, finish_result, tmp2, tmp2_avail);
		}
		
	}
	
	delete [] tmp2;
}


int main(){
	
	ifstream file("test.txt");
	string line, buf;
    vector<string> tokens[2];
	
	if (file.is_open())
    {
		int j=0;
		
        while (getline(file, line)) // �� �پ� �о� ó���� �����Ѵ�.
        {
        	stringstream ss(line);
			while( ss >> buf){
				tokens[j].push_back(buf);
			}
			j++;
    	}
    }
    file.close(); // ���� �ݱ�
    
    int size_a=0, size_b=0;
    
    size_a = atoi(tokens[0][0].c_str());
    polynomial *a  = new polynomial[size_a];
    for(int i=1, k=0; i<=2*size_a; i+=2){
        a[k].coef = atoi(tokens[0][i].c_str());
        a[k].expon = atoi(tokens[0][i+1].c_str());
        k++;
	}	

	size_b = atoi(tokens[1][0].c_str());
    polynomial *b = new polynomial[size_b];
    for(int i=1, k=0; i<=2*size_b; i+=2){
        b[k].coef = atoi(tokens[1][i].c_str());
       	b[k].expon = atoi(tokens[1][i+1].c_str());
       	k++;
	}

	polynomial *result = new polynomial[size_a*size_b];
	polynomial *tmp = new polynomial[size_b];
	
	int finish_result;
	
	for(int i=0; i<size_a*size_b; i++){ //�ʱ�ȭ 
		result[i].coef=0;
		result[i].expon=0;
	}
	for(int i=0; i<size_b; i++){
		tmp[i].coef=0;
		tmp[i].expon=0;
	}
	
	polynomialMul(a, b, result, tmp, size_a, size_b, finish_result);
	
	// ù��° �� ��� ��� 
	for(int i=0; i<size_a; i++){
		float c = a[i].coef;
		int e = a[i].expon;
		
		if(i==0){
			if(e==0){
				cout << c << endl;
			}
			else if(e==1){
				if(c==1){
					cout << "X";
				}
				else cout << c << "X";
			} 
			else{
				if(c==1){
					cout << "X^" << e ;
				}
				else cout << c << "X^" << e ;
			}
		}
		else{
			if(e==0){
				if(c>0) cout << "+" << c << endl;
				else cout << c << endl;
			}
			else if(e==1){
				if(c>0){
					if(c==1) cout << "+X";
					else cout << "+" << c << "X";
				} 
				else{
					if(c==-1) cout << "-X";
					else cout << c << "X";
				}
			}
			else{
				if(c>0){
					if(c==1) cout << "+X^" << e;
					else cout << "+" << c << "X^" << e;
				} 
				else{
					if(c==-1) cout << "-X^" << e;
					else cout << c << "X^" << e;
				}
			}
		}
	}
	
	// �ι�° �� ��� 
	for(int i=0; i<size_b; i++){
		float c = b[i].coef;
		int e = b[i].expon;
		
		if(i==0){
			if(e==0){
				cout << c << endl;
			}
			else if(e==1){
				if(c==1){
					cout << "X";
				}
				else cout << c << "X";
			} 
			else{
				if(c==1){
					cout << "X^" << e ;
				}
				else cout << c << "X^" << e ;
			}
		}
		else{
			if(e==0){
				if(c>0) cout << "+" << c << endl;
				else cout << c << endl;
			}
			else if(e==1){
				if(c>0){
					if(c==1) cout << "+X";
					else cout << "+" << c << "X";
				} 
				else{
					if(c==-1) cout << "-X";
					else cout << c << "X";
				}
			}
			else{
				if(c>0){
					if(c==1) cout << "+X^" << e;
					else cout << "+" << c << "X^" << e;
				} 
				else{
					if(c==-1) cout << "-X^" << e;
					else cout << c << "X^" << e;
				}
			}
		}
	}
	
	//���� ���� ���(result) ��� 
	for(int i=0; i<=finish_result; i++){
		float c = result[i].coef;
		int e = result[i].expon;
		
		if(i==0){
			if(e==0){
				cout << c << endl;
			}
			else if(e==1){
				if(c==1){
					cout << "X";
				}
				else cout << c << "X";
			} 
			else{
				if(c==1){
					cout << "X^" << e ;
				}
				else cout << c << "X^" << e ;
			}
		}
		else{
			if(e==0){
				if(c>0) cout << "+" << c << endl;
				else cout << c << endl;
			}
			else if(e==1){
				if(c>0){
					if(c==1) cout << "+X";
					else cout << "+" << c << "X";
				} 
				else{
					if(c==-1) cout << "-X";
					else cout << c << "X";
				}
			}
			else{
				if(c>0){
					if(c==1) cout << "+X^" << e;
					else cout << "+" << c << "X^" << e;
				} 
				else{
					if(c==-1) cout << "-X^" << e;
					else cout << c << "X^" << e;
				}
			}
		}
	}
	
/*	
	int starta, finisha, startb, finishb, startd, finishd;
	int x,y;
	
	starta = 0;
	
	cout << "ù��° ���׽� �Է�" << endl;
	cin >> x >> y;
	
	while(x!=0 || y!=0){	// 0 0 �ԷµǸ� ù��° ���׽� �Է� �����ٴ� �� 
		terms[avail].coef = x;
		terms[avail++].expon = y;
		
		cin >> x >> y;
	}
	
	finisha = (avail <= 0) ? avail : avail-1;
	startb = avail;
	
	cout << "�ι�° ���׽� �Է�" << endl;
	cin >> x >> y;
	
	while(x!=0 || y!=0){
		terms[avail].coef = x;
		terms[avail++].expon = y;
		
		cin >> x >> y;
	}
	
	finishb = (avail <= 0) ? avail : avail-1;
	startd = avail;
	
	polynomialAdd1(starta, finisha, startb, finishb, startd, finishd);
	
	for(int i=0; i<avail; i++){
		cout << terms[i].coef << " , " << terms[i].expon << endl;
	}
	
*/	

	delete [] a;
	delete [] b;
	delete [] tmp;
	delete [] result;
	
	return 0;
}
