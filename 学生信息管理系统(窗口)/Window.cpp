#include "Window.h"
ExMessage Window::msg;
HWND Window::m_handle;
Window::Window(int w, int h)
{
	m_handle=::initgraph(w, h);
	::setbkmode(TRANSPARENT);
}

void Window::settxttitle(const string& title)
{
	::SetWindowText(m_handle, title.c_str());
}

int Window::width()
{
	return ::getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear()
{
	::cleardevice();
}

void Window::begindraw()
{
	::BeginBatchDraw();
}

void Window::flashdraw()
{
	::FlushBatchDraw();
}

void Window::enddraw()
{
	::EndBatchDraw();
}

void Window::close()
{
	::closegraph();
}
