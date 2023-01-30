#define _CRT_SECURE_NO_WARNINGS
#include "Window.h"
#include "Mamangment.h"
#include "bassicwidget.h"
#include "pushbotton.h" 
 Mamangment::Mamangment()
{
	 readst();
	 ::loadimage(&img, "1.png", Window::width(), Window::height());
	 fl = 0;
	 settextstyle(30, 0, "楷体");
	 //主界面按钮初始化
	 menubt.push_back(new pushbotton("查看学生"));
	 menubt.push_back(new pushbotton("增加学生"));
	 menubt.push_back(new pushbotton("删除学生"));
	 menubt.push_back(new pushbotton("修改学生"));
	 menubt.push_back(new pushbotton("查找学生"));
	 menubt.push_back(new pushbotton("退出"));
	 for (int i = 0; i < menubt.size(); i++)
	 {
		 menubt[i]->setfixedsize(250,50);
		 int bx = (Window::width() - menubt[i]->w()) / 2;
		 int vt = (Window::height() - menubt[i]->h() * menubt.size()) / 2;
		 int by =vt+ i*menubt[i]->h();
		 menubt[i]->move(bx, by);
	 }
}
int Mamangment::menu()
{
	for (int i = 0; i < menubt.size(); i++)
	{
		menubt[i]->show();
		menubt[i]->eventloop(msg_s);
		if (menubt[i]->isclick())
		{
			return i;
		}
	}
	return 8;
}
void Mamangment::run()
{
	int choice = 8;
	int n = 0;
	Window::begindraw();
	while (1)
	{
		Window::clear();
		drawback();
		if (Window::hasmsg())
		{
		   msg_s = Window::getmsg();
		   switch (msg_s.message)
		   {
		   case WM_KEYDOWN:
			   if (msg_s.vkcode == VK_ESCAPE)
			   {
				   choice = 8;
				   fl = 0;
			   }
			   break;
		   default:
			   break;
		   }
		}
		switch (choice)
		{
		case 8:
			choice=menu();
			break;
		case 1:
			add();
			break;
		case 0:
			show();
			break;
		case 2:
			omit();
			break;
		case 3:
			change();
			break;
		case 4:
			if (fl == 0)
			{
				 n=match();
				 find(n);
			}
			if (fl==1)
			{
				find(n);
			}
			if (fl == 2)
			{
				run();
			}
			break;
		case 5:
			writest();
			quit();
			break;
		default:
			break;
		}
		Window::flashdraw();
	}
	Window::enddraw();
}
void Mamangment::show()
{
	drawline();
	int y = 20;
	settextstyle(20, 0, "楷体");
	int i = 0;
	outtextxy(0, 0, "姓名");
	outtextxy(150, 0, "学号");
	outtextxy(320, 0, "成绩");
	for (i = 0; i < stu.size(); i++)
	{
		if (stu[i].grade > 0)
		{
			outtextxy(0, y, stu[i].name.c_str());
			outtextxy(150, y, stu[i].number.c_str());
			outtextxy(320, y, to_string(stu[i].grade).c_str());
			y += 30;
		}
	}
}
void Mamangment::add()
{
	student s;
	while (1)
	{
		char a[20] = { '\0' };
		char b[20] = { '\0' };
		char c[20] = { '\0' };
		InputBox(a, 20, "请输入姓名");
		InputBox(b, 20, "请输入学号");
		InputBox(c, 20, "请输入成绩");
		//char*转换为sting
		s.name = a;
		s.number = b;
		s.grade = atoi(c);
		stu.push_back(s);
		int isok = MessageBox(Window::Getwindow(), "增加完成是否继续增加", "提示框", MB_OKCANCEL);
		if (isok == IDCANCEL)
		{
			break;
		}
	}
	run();
}
void Mamangment::omit()
{
	while (1)
	{
		int m = match();
		if (m != -1)
		{
			stu.erase(stu.begin()+m);
			int isok = MessageBox(Window::Getwindow(), "删除完成是否继续删除", "提示框", MB_OKCANCEL);
			if (isok == IDCANCEL)
			{
				break;
			}
		}
		else
		{
			MessageBox(Window::Getwindow(), "学号输入错误", "对话框", MB_OK);
			break;
		}
	}
	run();
}
void Mamangment::change()
{
	int m = match();
	int h = 0;
	if (m == -1)
	{
		MessageBox(Window::Getwindow(), "学号输入错误", "对话框", MB_OK);
		goto that;
	}
	else
	{
		char a[20];
		string s;
		here:
		InputBox(a, 20, "请输入学号或姓名或成绩");
		s = a;
		if (s == "学号")
		{
			char b[20];
			InputBox(b, 20, "请输入学号");
			stu[m].number = b;
		}
		else if (s == "姓名")
		{
			char c[20];
			InputBox(c, 20, "请输入姓名");
			stu[m].name = c;
		}
		else if (s == "成绩")
		{
			char d[20];
			InputBox(d, 20, "请输入成绩");
			stu[m].grade = atoi(d);
		}
		else
		{
			MessageBox(Window::Getwindow(), "输入修改内容错误", "提示框", MB_OK);
			goto here;
		}
		h = 1;
	}
	while (1)
	{
		if (m !=0&&h==1)
		{
			int isok = MessageBox(Window::Getwindow(), "修改完成是否继续修改", "提示框", MB_OKCANCEL);
			if (isok == IDCANCEL)
			{
				break;
			}
		}
	}
	that:
	run();
}
void Mamangment::find(int m)
{
		if (m != -1)
		{
			fl = 1;
			drawline();
			settextstyle(20, 0, "楷体");
			outtextxy(0, 0, "姓名");
			outtextxy(150, 0, "学号");
			outtextxy(320, 0, "成绩");
			outtextxy(0, 20, stu[m].name.c_str());
			outtextxy(150, 20, stu[m].number.c_str());
			outtextxy(320, 20, to_string(stu[m].grade).c_str());
		}
		else
		{
			MessageBox(Window::Getwindow(), "学号输入错误", "对话框", MB_OK);
			fl = 2;
		}
}
void Mamangment::drawback()
{
	::putimage(0, 0, &img);
}
void Mamangment::quit()
{
	PostMessage(Window::Getwindow(), WM_CLOSE, 0, 0);
}
int Mamangment::match()
{
	char b[20] = { '\0' };
	InputBox(b, 20, "请输入学号");
	int i = 0;
	for (i = 0; i < stu.size(); i++)
	{
		if (stu[i].number == b && stu[i].grade > 0)
		{
			return i;
		}
	}
	return -1;
}
void Mamangment::drawline()
{
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	int x = 0;
	int y = 0;
	for (x = 0; x < 960; x++)
	{
		line(x, 0, x, 480);
	}
	for (y = 0; y < 480; y++)
	{
		line(0, y, 960, y);
	}
}
void Mamangment::readst()
{
	fstream file;
	file.open("student.txt");
	if (file.fail())
	{
		cout << "文件打开失败" << endl;
	}
	while (!file.eof())
	{
		char buf[1024] = { '\0' };
		file.getline(buf, 1024);
		student s;
		stringstream ss(buf);
		ss >> s.name >> s.number >> s.grade;
		stu.push_back(s);
	}
	file.close();
}
void Mamangment::writest()
{
	fstream file;
	file.open("student.txt");
	if (file.fail())
	{
		cout << "文件打开失败" << endl;
	}
	for (int i = 0; i < stu.size(); i++)
	{
		if (stu[i].grade > 0)
		{
			file << stu[i].number << '\t' <<"    " << stu[i].name << '\t'<<"   " << stu[i].grade << "\t";
			file << endl;
		}
	}
	file.close();
}
