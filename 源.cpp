#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
using namespace std;
class A
{
public:
	float a,b;
	A(float m=0, float n=0) { a = m; b = n; };
	A operator +(A p);
	A operator -(A p);
	A operator *(A p);
	A operator /(A p);
};
A A::operator+(A p)
{
	a = a + p.a;
	b = b + p.b;
	return *this;
}
A A::operator-(A p)
{
	a = a - p.a;
	b = b - p.b;
	return *this;
}
A A::operator*(A p)
{
	float m = a;
	a = a * p.a - b * p.b;
	b = m * p.b + b * p.a;
	return *this;
}
A A::operator/(A p)
{
	float m = a;
	a = a * p.a + b * p.b/(p.a*p.a+p.b*p.b);
	b = b*p.a-m*p.b/(p.a * p.a + p.b * p.b);
	return *this;
}
int main()
{
	A a(1, 1);
	A b(1, 0);
	a = a / b;
	cout << a.a << endl << a.b;
}