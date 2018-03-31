#include<stdio.h>

int main(){
	
	int a=2,b=2;
	
	while(b>0){
		a++;
		b--;
	}
	
	do{
		a--;
		b++;
	}while(a>0);
	
	printf("%d", b);
	
	return 0;
}
