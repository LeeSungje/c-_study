#include <iostream>
using namespace std;
class Unit {
public:
int defaultArmor;
Unit(int armor) { defaultArmor = armor; }
Unit(Unit &A){
	cout<< "copy" << endl;
	defaultArmor = A.defaultArmor;
}
int GetDefaultArmor() { return defaultArmor; }
};
int GetEnhancedArmor(Unit &aUnit)
{
return aUnit.defaultArmor * 2;
}
int main()
{
Unit A(1),B(A);
	cout << "Unit A : " << GetEnhancedArmor(A) << "\n";
	cout << "Unit B : " << GetEnhancedArmor(B) << "\n";
return 0;
}
