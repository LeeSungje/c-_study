#include<stdio.h>

/*������(?)���ϴ� ����*/
int main(){
	
	int i, j, sum;
	
	for(i=19; i<50; i++){
		sum = 0;
		
		for(j=1; j<i; j++){
			if(i%j==0)
				sum += j;	//�ڽ�(i)�� ������ ������� �� 
		}
		
		if(i == sum)
			printf("%d", i); //�ڽ�(i) = �ڽ�(i)�� ������ ������� ��
	}
	
	return 0;
}
