#pragma once

class CMMP;
class CGameObject;
class STAGE
{
public:
	static STAGE* ROADSTAGE1();
	void set_monlist(list<CGameObject*>* rhs);
	void Set_Tick(int tick);
	void CreateMonster(MON_TYPE mt, vector<CMMP> mmpv, MON_ATT_PATTERN mat, double x, double y);

public:
	~STAGE();

public:
	int Update();
	void Initialize();


private:
	STAGE();
	int m_Tick;
	int m_PlusTick;
	list<CGameObject*>* Monster_list;



};

