#include "stdafx.h"
#include "STAGE.h"
#include "Monster.h"
#include "Bullet.h"
STAGE::STAGE()
{
}


STAGE* STAGE::ROADSTAGE1()
{
	static STAGE* Stage1 = new STAGE;
	return Stage1;
}

void STAGE::set_monlist(list<CGameObject*>* rhs)
{
	Monster_list = rhs;
}

int STAGE::Update()
{
	//현재 틱의 범위에 따라 몬스터 생성
	//CreateMonster 사용 방법
	//1.몬스터타입, 2.이동타입, 3.공격 타입, x좌표, y좌표
	if (m_Tick == 10) {

		for (int i = 0; i < 10; ++i)
		{
			CreateMonster(MT01, MMP01, NORMAL, -400 + i * 10, 1000 + i * 10);
		}
		

		++m_Tick;
	}
	else if (m_Tick == 150)
	{
		for (int i = 0; i < 10; ++i)
		{
			CreateMonster(MT01, MMP01, NORMAL, -400 + i * 10, 1000 + i * 10);
		}
	}

	if (m_Tick == 100)
	{
		dynamic_cast<CMonster*>(Monster_list->back())->CreateBullet_N(18);
		++m_Tick;
	}



	return 0;
}

void STAGE::CreateMonster(MON_TYPE mt, MON_MOV_PATTERN mmp, MONSTER_MOVING_DIRECT dr, double x, double y)
{
	Monster_list->push_back(new CMonster(mt,mmp,dr));
	Monster_list->back()->SetPos(x, y);
	dynamic_cast<CMonster*>(Monster_list->back())->CreateBullet_N(18);
}

void STAGE::Set_Tick(int tick)
{
	m_Tick = tick;
}


STAGE::~STAGE()
{
}
