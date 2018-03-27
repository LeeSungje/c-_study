#include<iostream>
#include<cstring>

using namespace std;

#define MAX_SIZE 10
template <typename TYPE>
class stack {
TYPE data[MAX_SIZE];
int nCount;
public:
stack() { nCount = 0; }
void add(TYPE in) {
data[nCount++] = in;
if (nCount == MAX_SIZE) {
cout << "overflow : " << nCount << endl;
}
}
TYPE pop(void) {
if ( nCount <= 0 ) {
cout << "empty" << endl;
return data[0];
}
else {
return data[--nCount];
}
}
};

int main( )
{
stack<int> stack1;
stack<float> stack2;
int i;
float j;
for(i=0;i<10;i++)
stack1.add( i );

cout << "Stack1 : ";
for(i=0;i<10;i++)
cout << stack1.pop() << " ";

cout << endl;

return 0;
}
