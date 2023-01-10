#include "pch.h"
#include "TarnsForm2.h"
void CTransForm2::Identity()//µ•Œªæÿ’Û
{
	T[0][0] = 1.0; T[0][1] = 0.0; T[0][2] = 0.0;
	T[1][0] = 0.0; T[1][1] = 1.0; T[1][2] = 0.0;
	T[2][0] = 0.0; T[2][1] = 0.0; T[2][2] = 1.0;
}
void CTransForm2::MultiMatrix()//æÿ’Ûœ‡≥À
{
	CP2* PNew = new CP2[num];
	for (int i = 0; i < num; i++)
	{
		PNew[i] = P0ld[i];
	}
	for (int j = 0; j < num; j++)
	{
		P0ld[j].x = PNew[j].x * T[0][0] + PNew[j].y * T[1][0] + PNew[j].w * T[2][0];
		P0ld[j].y = PNew[j].x * T[0][1] + PNew[j].y * T[1][1] + PNew[j].w * T[2][1];
		P0ld[j].w = PNew[j].x * T[0][2] + PNew[j].y * T[1][2] + PNew[j].w * T[2][2];
	}
	delete[]PNew;
}


void CTransForm2::Translate(double tx, double ty)//∆Ω“∆±‰ªªæÿ’Û
{
	Identity();
	T[2][0] = tx;
	T[2][1] = ty;
	MultiMatrix();  //æÿ’Ûœ‡≥À
}
void CTransForm2::Scale(double sx, double sy)//Àı∑≈±‰ªªæÿ’Û
{
	Identity();
	T[0][0] = sx;
	T[1][1] = sy;
	MultiMatrix();
}
void CTransForm2::Rotate(double beta)//–˝◊™±‰ªªæÿ’Û
{
	Identity();
	double rad = beta * Pi / 180;
	T[0][0] = cos(rad); T[0][1] = sin(rad);
	T[1][0] = -sin(rad); T[1][1] = cos(rad);
	MultiMatrix();
}

