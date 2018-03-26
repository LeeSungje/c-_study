#include<iostream>

using namespace std;

class Student
{
public:
	Student()
	{
	grade = 0;
	}
	Student(int argGrade): grade(argGrade){}
	~Student(){}
	int GetGrade() { return grade; }
private:
	int grade;
};

class Calculator
{
public:
	Calculator()
	{
	numberOfStudent = 0;
	}
	void AddStudent(Student argStudent);
	int Sum();
private:
	Student student[50];
protected:
	int numberOfStudent;
};

void Calculator::AddStudent(Student argStudent)
{
	student[numberOfStudent++] = argStudent;
}

int Calculator::Sum()
{
	int sum = 0;
	for (int i = 0; i < numberOfStudent; i++)
	sum += student[i].GetGrade();
	return sum;
}

class CalculatorEx : public Calculator
{
public:
	CalculatorEx(){}
	~CalculatorEx(){}
	double Average(){
		return (double)Sum()/numberOfStudent;
	}
};
	
int main()
{
	Student student1(30);
	Student student2(90);
	Student student3(100);
	Student student4(50);
	
	CalculatorEx cal;
	
	cal.AddStudent(student1);
	cal.AddStudent(student2);
	cal.AddStudent(student3);
	cal.AddStudent(student4);
	
	cout << "Sum of grades : " << cal.Sum() << endl;
	cout << "Average of grades : " << cal.Average() << endl;

return 0;
}
