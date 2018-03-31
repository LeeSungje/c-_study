#include<stdio.h>

int func(int x, int y){
	
	int n = (x+y)/2;
	
	if(x == y){
		return x;
	}
	
	else{
		return func(x,n)+func(n+1,y);
	}
}

int main(){
	
	printf("%d", func(16, 20));
	
	return 0;
}
