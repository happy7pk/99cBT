#pragma once

#ifndef __STRUCT_H__

typedef struct tagInfo
{
	double fX = 0.f;
	double fY = 0.f;
	double fCX = 0.f;
	double fCY = 0.f;
}INFO;

struct VECTOR {
	THETA Angle;
	double Length;

public:
	VECTOR(){}
	VECTOR(THETA th, double len) //阿档肺 积己规过
	:Angle(th/180*PI),Length(len){}
};

#define __STRUCT_H__
#endif
