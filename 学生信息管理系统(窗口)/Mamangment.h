#pragma once
#include "mind.h"
#include "pushbotton.h"
#include "student.h"
class Mamangment
{
public:
	Mamangment();
	int menu();
	//运行
	void run();
	//1.显示
	void show();
	//2.增加
	void add();
	//3.删除
	void omit();
	//4.修改
	void change();
	//5.查找
	void find(int m);
	//6 退出
	void quit();
	//绘制背景
	void drawback();
	//读
	void readst();
	//写
	void writest();
	//退出的标志变量
	bool flag;
	//学号匹配数据
	int match();
	//画白背景板
	void drawline();
private:
	ExMessage msg_s;
	IMAGE img;
	vector<pushbotton*> menubt;
	vector<student> stu;
	int fl;
};

