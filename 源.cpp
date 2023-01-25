#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
template<class T>
void add(T a, T b)
{
	cout << a + b << endl;
}
int main()
{
	float a = 1.3, b = 2.61;
	add(a, b);
	return 0;
}
