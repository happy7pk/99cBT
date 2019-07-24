#pragma once

class CMMP;
class CGameObject;
class STAGE
{
public:
	static STAGE* ROADSTAGE1();
	void set_monlist(list<CGameObject*>* rhs);
	int Update();
	void CreateMonster(MON_TYPE, MON_MOV_PATTERN, MONSTER_MOVING_DIRECT, double x, double y);
	void Set_Tick(int tick);
	~STAGE();

private:
	STAGE();
	int m_Tick;
	int m_PlusTick;
	list<CGameObject*>* Monster_list;

	vector<CMMP> PA01[3] = { CMMP(VECTOR(120,5),300),CMMP(VECTOR(90,4),200),CMMP(VECTOR(-90,10),900) };


};

