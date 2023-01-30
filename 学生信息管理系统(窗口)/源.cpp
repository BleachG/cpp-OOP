#include "Mamangment.h"
#include "Window.h"
#include "mind.h"
int main()
{
	Window w(960, 640);
	w.settxttitle("学生成绩信息管理系统");
	Mamangment m;
	m.run();
	return 0;
}