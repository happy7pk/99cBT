#include "stdafx.h"
#include "PatternFactory.h"
#include "Bullet.h"

PatternFactory::PatternFactory()
{
}




void PatternFactory::PT01(double x, double y,OBJLIST & Blist, int pm)
{
	THETA temp = PI*pm, angle = PI / 4;;
	for (int i = 0; i < 3; i++) {
		temp += angle;
		Blist.push_back(new CBullet(x, y, temp, basic_Speed));
	}
}

void PatternFactory::PT02(double x, double y, OBJLIST & Blist, int pm)
{
}

void PatternFactory::PT03(double x, double y, OBJLIST & Blist, int pm)
{
}

void PatternFactory::PT04(double x, double y, OBJLIST & Blist, int pm)
{
}

void PatternFactory::PT05(double x, double y, OBJLIST & Blist, int pm)
{
}

void PatternFactory::PTNN(double x, double y, OBJLIST & Blist, int N, int pm)
{
	THETA temp = PI, angle = -pm* PI / N;;
	for (int i = 0; i < N-1; i++) {
	temp += angle;
	Blist.push_back(new CBullet(x, y, temp, basic_Speed));
	
	}
}

PatternFactory::~PatternFactory()
{
}
