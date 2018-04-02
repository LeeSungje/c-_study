#include<stdio.h>
int main()
{
	int a[2]={10,20};
	int *ptr = a;
	
	printf("%d\n", *ptr);
	printf("%d\n", (*ptr)++);
	printf("%d\n", *ptr++);
	printf("%d\n", *ptr);
	return 0;
}
