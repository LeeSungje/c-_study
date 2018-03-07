#include <iostream>
using namespace std;

int main(){

	int stuNum, total=0;

	cout << "학생 수를 입력하세요: ";
	cin >> stuNum;

	int *stuScore = new int[stuNum];

  for(int i = 1 ; i<=stuNum; i++){
    cout << i << "번 학생의 점수: ";
    cin >> stuScore[i];
    total += stuScore[i];
  }

  cout << "모든 학생의 평균: " << total/stuNum << endl;

  delete []stuScore;

	return 0;
}
