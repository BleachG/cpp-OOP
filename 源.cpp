#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
template<class T>
class A
{
public:
	T n;
	A(T a) { n = a; }
	void show() { cout << n << endl; }
	A operator +(A m)
	{
		this->n = m.n + this->n;
		return *this;
	}
};
int main()
{
	A<int> p(3), l(4);
	p = p + l;
	cout << p.n;
	return 0;
}
