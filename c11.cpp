#include<iostream>

using namespace std;

int FindMaxNumber(int* argGrade){
	int max = (*argGrade);
	int result = 0;
	for(int i=1; i<10; i++){
		if(*(argGrade+i) > max){
			max = *(argGrade+i);
			result=i;
		}
	}
	
	return result;
}

int main(){
	
	int aGrade[10] = { 90, 88, 100, 55, 47, 92, 87, 30, 189, 65 };
	int maxGradeIndex = 0;
	maxGradeIndex = FindMaxNumber(aGrade);
	cout << "Best grade = " << aGrade[maxGradeIndex] << '\n';
	cout << "StudentID = " << maxGradeIndex + 1 << '\n';
	
	return 0;
}
