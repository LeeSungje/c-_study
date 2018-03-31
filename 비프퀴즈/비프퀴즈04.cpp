#include<stdio.h>

int main(){
	
	int a=0, i = 1, n = 2016, result=0;
	
	while(n>0){
		
		if(n%10 == 2){
			result+=(n%10)+a;
		}
		
		else if(n%10 < 2){
			result+=(n%10)*i;
		}
		
		else{
			result+=(n%10)*100;
		}
		
		a+=n%10;
		i*=10;
		n/=10;
	} 
	
	printf("%d", result);
	
	return 0;
}
