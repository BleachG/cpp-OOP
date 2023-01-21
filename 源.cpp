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
	friend ostream& operator<<(ostream& os, A am);
	friend istream& operator>>(istream& is, A& am);
};
ostream& operator<<(ostream& os, A am)
{
	os << "复数为:";
	if (am.a != 0)
	{
		os << am.a ;
	}
	if (am.b != 0)
	{
		os << "+" << am.b << "i"<<endl;
	}
	return os;
}
istream& operator>>(istream& is, A& am)
{
	cout << "请输入复数" << endl;
	is >> am.a;
	is >> am.b;
	return is;
}
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
	A a;
	cin >> a;
	cout << a;
	return 0;
}