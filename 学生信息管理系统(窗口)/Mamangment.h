#pragma once
#include "mind.h"
#include "pushbotton.h"
#include "student.h"
class Mamangment
{
public:
	Mamangment();
	int menu();
	//����
	void run();
	//1.��ʾ
	void show();
	//2.����
	void add();
	//3.ɾ��
	void omit();
	//4.�޸�
	void change();
	//5.����
	void find(int m);
	//6 �˳�
	void quit();
	//���Ʊ���
	void drawback();
	//��
	void readst();
	//д
	void writest();
	//�˳��ı�־����
	bool flag;
	//ѧ��ƥ������
	int match();
	//���ױ�����
	void drawline();
private:
	ExMessage msg_s;
	IMAGE img;
	vector<pushbotton*> menubt;
	vector<student> stu;
	int fl;
};

