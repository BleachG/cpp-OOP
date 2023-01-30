#include "bassicwidget.h"

int bassicwidget::w()
{
    return m_w;
}

int bassicwidget::h()
{
    return m_h;
}

int bassicwidget::x()
{
    return m_x;
}

int bassicwidget::y()
{
    return m_y;
}

void bassicwidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

void bassicwidget::setfixedsize(int w, int h)
{
    this->m_w = w;
    this->m_h = h;
}
