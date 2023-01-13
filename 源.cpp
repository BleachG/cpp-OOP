#include <iostream>
#define max(a,b) (a>b?a:b)

using namespace std;
class csqure
{
public:
	int a;
	csqure(int a_=0);
	csqure(csqure &d);
	int areasq();
	int lsq();
	~csqure();
	 static int  sumnum;
};
csqure::csqure(csqure &d)
{
	a = d.a+5;
}
csqure::csqure(int a_)
{
	a = a_;
	sumnum++;
}
csqure::~csqure()
{
	sumnum--;
}
int csqure::areasq()
	{

		return a * a;
	}
int csqure::lsq()
{
	return 4 * a;
}
int csqure::sumnum = 0;
int main()
{
	csqure s(3);
	csqure sa(s);
	/*csqure* p = new csqure(1);
	cout << s.sumnum << endl;
	delete p;
	cout << s.lsq() << endl;*/
	cout << s.areasq() << endl;
	cout << sa.areasq() << endl;
	/*cout << s.sumnum << endl;*/
	return 0;
}