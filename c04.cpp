#include <stdio.h>
int main(void)
{
	int i=2, c=0, count=0;
	
	for(; i<=50; i++){
		count = 0;
		for(int k=1; k<=i && count<=2; k++){
			if(i%k == 0) 
				count++;
		}
		if(count == 2){
			c++;
			if(c%5 == 1)
				printf("%d", i);

			else if(c%5 == 0)
				printf(" %d\n", i);
		
			else 
				printf(" %d", i);
		}
	}

	
	return 0;
}
