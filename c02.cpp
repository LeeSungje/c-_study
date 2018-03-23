#include<stdio.h>
int main()
{
	int i;
	char c;
	
	printf("입력 : ");
	scanf("%d", &i);
	
	c = i;

	printf("출력(int)->%d\n", i); 
	printf("출력(char)->%d\n", c);
	
	return 0;
}
