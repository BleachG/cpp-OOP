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
	 settextstyle(30, 0, "����");
	 //�����水ť��ʼ��
	 menubt.push_back(new pushbotton("�鿴ѧ��"));
	 menubt.push_back(new pushbotton("����ѧ��"));
	 menubt.push_back(new pushbotton("ɾ��ѧ��"));
	 menubt.push_back(new pushbotton("�޸�ѧ��"));
	 menubt.push_back(new pushbotton("����ѧ��"));
	 menubt.push_back(new pushbotton("�˳�"));
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
	settextstyle(20, 0, "����");
	int i = 0;
	outtextxy(0, 0, "����");
	outtextxy(150, 0, "ѧ��");
	outtextxy(320, 0, "�ɼ�");
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
		InputBox(a, 20, "����������");
		InputBox(b, 20, "������ѧ��");
		InputBox(c, 20, "������ɼ�");
		//char*ת��Ϊsting
		s.name = a;
		s.number = b;
		s.grade = atoi(c);
		stu.push_back(s);
		int isok = MessageBox(Window::Getwindow(), "��������Ƿ��������", "��ʾ��", MB_OKCANCEL);
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
			int isok = MessageBox(Window::Getwindow(), "ɾ������Ƿ����ɾ��", "��ʾ��", MB_OKCANCEL);
			if (isok == IDCANCEL)
			{
				break;
			}
		}
		else
		{
			MessageBox(Window::Getwindow(), "ѧ���������", "�Ի���", MB_OK);
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
		MessageBox(Window::Getwindow(), "ѧ���������", "�Ի���", MB_OK);
		goto that;
	}
	else
	{
		char a[20];
		string s;
		here:
		InputBox(a, 20, "������ѧ�Ż�������ɼ�");
		s = a;
		if (s == "ѧ��")
		{
			char b[20];
			InputBox(b, 20, "������ѧ��");
			stu[m].number = b;
		}
		else if (s == "����")
		{
			char c[20];
			InputBox(c, 20, "����������");
			stu[m].name = c;
		}
		else if (s == "�ɼ�")
		{
			char d[20];
			InputBox(d, 20, "������ɼ�");
			stu[m].grade = atoi(d);
		}
		else
		{
			MessageBox(Window::Getwindow(), "�����޸����ݴ���", "��ʾ��", MB_OK);
			goto here;
		}
		h = 1;
	}
	while (1)
	{
		if (m !=0&&h==1)
		{
			int isok = MessageBox(Window::Getwindow(), "�޸�����Ƿ�����޸�", "��ʾ��", MB_OKCANCEL);
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
			settextstyle(20, 0, "����");
			outtextxy(0, 0, "����");
			outtextxy(150, 0, "ѧ��");
			outtextxy(320, 0, "�ɼ�");
			outtextxy(0, 20, stu[m].name.c_str());
			outtextxy(150, 20, stu[m].number.c_str());
			outtextxy(320, 20, to_string(stu[m].grade).c_str());
		}
		else
		{
			MessageBox(Window::Getwindow(), "ѧ���������", "�Ի���", MB_OK);
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
	InputBox(b, 20, "������ѧ��");
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
		cout << "�ļ���ʧ��" << endl;
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
		cout << "�ļ���ʧ��" << endl;
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
