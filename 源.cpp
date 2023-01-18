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
	friend A operator+(A &a,int m);
	A operator++();
	A operator--();
	A operator++(int);
	A operator--(int);
};
A operator+(A &a,int m)
{
	a.n += m;
	return a;
}
A A::operator++()
{
	++n;
	return *this;
}
A A::operator--()
{
	--n;
	return *this;
}
A A::operator++(int)
{
	n++;
	return *this;
}
A A::operator--(int)
{
	n--;
	return *this;
}
int main()
{
	A a(2);
	a=a+2;
	cout << a.n;
}