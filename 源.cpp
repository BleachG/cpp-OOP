#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Recetangle
{
private:
	int length;
	int width;
public:
	Recetangle(int a, int b) :length(a), width(b) {};
	Recetangle() { length = 0, width = 0; };
	friend int area(Recetangle s);
};
int area(Recetangle s)
{
	return s.length * s.width;
}
int main()
{
	Recetangle s1(3, 4);
	cout << area(s1);
	return 0;
}