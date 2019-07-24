#pragma once
class CGameObject;
class PatternFactory
{
public:

	static PatternFactory* ROAD() {
		static PatternFactory* pf = new PatternFactory;
		return pf;
	}

	void PT01(double x,double y, OBJLIST& Blist,int pm);
	void PT02(double x,double y, OBJLIST& Blist,int pm);
	void PT03(double x,double y, OBJLIST& Blist,int pm);
	void PT04(double x,double y, OBJLIST& Blist,int pm);
	void PT05(double x,double y, OBJLIST& Blist,int pm);
	void PTNN(double x, double y, OBJLIST& Blist, int N, int pm);
	~PatternFactory();



private:
	PatternFactory();
	double basic_Speed = 10;
};

