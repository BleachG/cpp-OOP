#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
using namespace std;
class squre
{
private:
	int a;
public:
	squre(int m) :a(m) {}
    virtual void getarea() { cout << a * a << endl; }
};
class recetangle : public squre
{
private:
	int m, n;
public:
  recetangle(int m_s,int n_s,int a_s):squre(a_s),m(m_s),n(n_s){}
  void getarea() { cout << m * n<<endl; }
};
int main()
{
	squre*a=new recetangle(2, 3, 1);
	a->getarea();
	return 0;
}