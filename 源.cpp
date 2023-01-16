#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
using namespace std;
class buliding
{
	int floor;
	int roomnum;
	int sumarea;
public:
	buliding(int a, int b, int c) :floor(a), roomnum(b), sumarea(c) {};
	void show();
};
void buliding::show()
{
	cout << floor << endl;
	cout << roomnum << endl;
	cout << sumarea << endl;

}
class houslding:public buliding
{
	int beedroom;
	int washroom;
public:
	houslding(int a, int b, int a_s, int b_s, int c_s) :beedroom(a), washroom(b), buliding(a_s, b_s, c_s) {};
	void show();
};
void houslding::show()
{
	cout << beedroom << endl;
	cout << washroom << endl;
}
class office :public buliding
{
	int telephone;
	int fire;
public:
	office(int a, int b, int a_s, int b_s, int c_s) :telephone(a),fire(b), buliding(a_s, b_s, c_s) {};
	void show();
};
void office::show()
{
	cout << telephone << endl;
	cout << fire << endl;
}
int main()
{
	office a(1, 2, 3, 4, 5);
	houslding b(6, 7, 3, 4, 5);
	a.show();
	b.show();
a.buliding::show();
return 0;
}
