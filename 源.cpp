#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
using namespace std;
class circle
{
private:
	int radious;
public:
   float area();
   circle(int r) { radious = r; }
};
float circle::area()
{
	return 3.14 * radious * radious;
}
class table
{
private:
	int height;
public:
	int show();
	table(int h) :height(h) {};
};
int table::show()
{
	return height;
}
class roundtable :public circle, public table
{
private:
	char color[20];
public:
	roundtable(char a[20], int h, int r) :circle(r), table(h) { strcpy(color, a); };
	void showcolor() { cout << color; };
};
int main()
{
	char a[20];
	cout << "ÇëÊäÈëÑÕÉ«" << endl;
	cin >> a;
	int h, r;
	cin >> h;
	cin >> r;
	roundtable s(a, h, r);
	cout << s.area() << " " << s.show()<<endl;
	s.showcolor();
	return 0;
}