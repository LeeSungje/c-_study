#include<stdio.h>

int main(){
	
	char arr1[]={"abcde"};
	char arr2[]={'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	
	int len1 = sizeof(arr1) - 3;
	int len2 = sizeof(arr2) - 3;
	
	printf("%c%c", arr1[len2], arr2[len1]);
	
	return 0;
}
