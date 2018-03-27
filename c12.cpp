#include<iostream>

using namespace std;

class St
{
public:
	int grade;
	St(int grade)
	{	
		this->grade = grade;
	}
};

int FindMaxNumber(St a[]){
	int max = a[0].grade;
	int result = 0;
	for(int i=1; i<10; i++){
		if(a[i].grade > max){
			max = a[i].grade;
			result=i;
		}
	}
	
	return result;
}

int main(){
	
	St s[10] ={90, 188, St(85), St(155), St(47), St(92), St(87), St(30), St(89), St(65)};
	int maxGradeIndex;
	
	maxGradeIndex=FindMaxNumber(s);
	
	cout << "Best grade = " << s[maxGradeIndex].grade << '\n';
	cout << "StudentID = " << maxGradeIndex + 1 << '\n';
	
	return 0;
}
