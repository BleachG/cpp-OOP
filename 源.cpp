#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Point
{
public:
	int x;
	int y;
	Point(int a, int b) :x(a), y(b) {};
	double distance(Point p1, Point p2);
	Point() { x = 0; y = 0; };
};
double Point::distance(Point p1, Point p2)
{
	int s1 = abs(p1.y * p1.y - p2.y * p2.y);
	int s2 = abs(p1.x * p1.x - p2.x * p2.x);
	double s = s1 + s2;
	return sqrt(s);
}
int main()
{
	Point s1(3, 0);
	Point s2(0, 4);
	Point s3;
	cout << s1.distance(s1, s2) << endl;
	cout << s1.distance(s1, s3);
	return 0;
}
