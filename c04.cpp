#include <stdio.h>
void func(int a){
printf("func 함수가 실행되었습니다.\n");
}
int main(){
	void (*pfunc)(int);
	pfunc = func;
	func(3);
	pfunc(3);
	return 0;
}

