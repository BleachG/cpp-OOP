#pragma once
#include "pch.h"
#include"CP2.h"
#include<math.h>
class CTransForm2
{
public:
	int num;
	CP2* P0ld;
	double Pi;
	double T[3][3];
	CTransForm2() {
		num = 0;
		P0ld = nullptr;
		Identity();
		Pi = acos(-1);
	}
	CTransForm2(int num, CP2* Pnow) {
		this->P0ld = Pnow;
		this->num = num;
		Pi = acos(-1);
	}
	void Identity();
	void MultiMatrix();
	void Translate(double tx, double ty);
	void Scale(double sx, double sy);
	void Rotate(double beta);
};


