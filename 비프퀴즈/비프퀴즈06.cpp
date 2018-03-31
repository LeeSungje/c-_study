#include<stdio.h>

int arr[]={5,1,0,4,3,6};
int func(int x, int y){
	
	int n = (x+y)/2;
	
	if(x == y){
		return arr[x];
	}
	
	else{
		return func(x,n)-func(n+1,y);
	}
}

int main(){
	
	printf("%d", func(0, 5));
	
	return 0;
}
