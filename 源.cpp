#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (a>b?a:b)
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
template<class T,int maxsize=10>
class arry
{
public:
	T arr[maxsize];
     int size;
	 arry()
	 { 
		 size = -1;
	 }
	T operator[](int i)
	{
		if (i < size)
		{
			return arr[i];
		}
		else
		{
			return arr[0];
		}
	}
	void show()
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}
	void pop(T i)
	{
		if (size < maxsize)
		{
			size++;
			arr[size] = i;
		}
		else
		{
			cout << "Тњ\n" ;
		}
	}
	void push()
	{
		if (size > 0)
		{
			arr[size] = 0;
			size--;
		}
		else
		{
			cout << "Пе\n";
		}
	}
};
int main()
{
	arry<int>a;
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		a.pop(i);
	}
	a.push();
	a.show();
	return 0;
}
