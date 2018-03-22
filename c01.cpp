#include<stdio.h>
int main()
{
int a, b, c, d;
a = 10;
b = a + 10;
c = a + b;
d = a + b + c;
printf("a,b,c,d,의 값-> %d, %d, %d, %d\n",a,b,c,d);


b = a, c = a, d = a;

printf("a,b,c,d,의 값-> %d, %d, %d, %d\n",a,b,c,d);

return 0;
}
