#include "pushbotton.h"

void pushbotton::show()
{
	//绘制按钮图形
	setfillcolor(cur_c);
	fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
	//填充文字
	settextcolor(BLACK);
	//居中显示
	int tx = m_x+(m_w - textwidth(m_txt.c_str()))/2;
	int ty =m_y+( m_h - textheight(m_txt.c_str()))/2;
	outtextxy(tx, ty, m_txt.c_str());
}

bool pushbotton::isin()
{
	if (m_msg.x >= m_x && m_msg.y < m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
	{
		return true;
	}
	return false;
}

bool pushbotton::isclick()
{
	if (isin())
	{
		if (m_msg.message == WM_LBUTTONDOWN)
		{
			return true;
		}
	}
	return false;
}

void pushbotton::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (!isin())
	{
		cur_c = normal_c;
	}
	else
	{
		cur_c = hover_c;
	}
}
