#pragma once
#include "mind.h"
using namespace std;
class student
{
public:
	string name;
	string number;
	int grade;
	student(const string& n, const string& num, int g) :name(n), number(num), grade(g) {};
	student() { this->name = '\0'; this->number = '\0'; this->grade = 0; }
};

