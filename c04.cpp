#include <stdio.h>
void func(int a){
printf("func �Լ��� ����Ǿ����ϴ�.\n");
}
int main(){
	void (*pfunc)(int);
	pfunc = func;
	func(3);
	pfunc(3);
	return 0;
}

