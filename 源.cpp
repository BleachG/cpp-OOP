#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
using namespace std;
class A
{
public:
	int n;
	A(int a = 0) { n = a; }
	A operator+(A a);
};
A  A::operator+(A a)
{
	A temp;
	temp.n = n + a.n;
	return temp;
}
int main()
{
	A m(1);
	A n(2);
	A a = A(1) + A(2);
	A b = m.operator+(n);
	cout << b.n << endl;
}