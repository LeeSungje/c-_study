#include<stdio.h>

/*완전수(?)구하는 문제*/
int main(){
	
	int i, j, sum;
	
	for(i=19; i<50; i++){
		sum = 0;
		
		for(j=1; j<i; j++){
			if(i%j==0)
				sum += j;	//자신(i)을 제외한 약수들의 합 
		}
		
		if(i == sum)
			printf("%d", i); //자신(i) = 자신(i)을 제외한 약수들의 합
	}
	
	return 0;
}
