#pragma once
#include "mind.h"
using namespace std;
class Window
{
public:
	Window(int w, int h);
	void settxttitle(const string &title);
	static int width();
	static int height();
	static void clear();
	static void begindraw();
	static void flashdraw();
	static void enddraw();
	static void close();
	//����������������
	inline static bool hasmsg() { return::peekmessage(&msg, EM_MOUSE | EM_KEY); };
	inline static const ExMessage& getmsg() { return msg; };
	static HWND Getwindow() { return m_handle; };
private:
	static ExMessage msg;//�����Ϣ�ͼ�����Ϣ
	static HWND m_handle;//���ھ��
};

