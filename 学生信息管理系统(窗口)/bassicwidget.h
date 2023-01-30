#pragma once
#include "mind.h"
class bassicwidget
{
public:
	bassicwidget(int x, int y, int w, int h) :m_x(x), m_y(y), m_w(w), m_h(h) {};
	int w();
	int h();
	int x();
	int y();
	void move(int x, int y);
	void setfixedsize(int w, int h);
	virtual void show() = 0;
protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

