#pragma once
#include "bassicwidget.h"
#include "mind.h"
using namespace std;
class pushbotton :
    public bassicwidget
{public:
    pushbotton(const string& txt, int x=150, int y=150, int w = 100, int h = 30) :bassicwidget(x, y, w, h), m_txt(txt) {};
    void show();
    bool isin();//判断鼠标是否在按钮
    bool isclick();//判断鼠标是否点击按钮
    void eventloop(const ExMessage& msg);
private:
    string m_txt;
    ExMessage m_msg;
    COLORREF normal_c= RGB(232, 232, 236);
    COLORREF hover_c=RED;
    COLORREF cur_c= RGB(232, 232, 236);
};

