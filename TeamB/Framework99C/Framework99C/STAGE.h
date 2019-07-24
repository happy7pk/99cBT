#pragma once

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
};

