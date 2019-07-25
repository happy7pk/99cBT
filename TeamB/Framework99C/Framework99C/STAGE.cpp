#include "stdafx.h"
#include "STAGE.h"
#include "Monster.h"
#include "Bullet.h"

STAGE::STAGE()
{
	Initialize();
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
	if (m_Tick < m_PlusTick)
		return 0;
	m_PlusTick = m_Tick;
	//모든 틱변화는 Plustick으로 관리

	//현재 틱의 범위에 따라 몬스터 생성
	//CreateMonster 사용 방법
	//1.몬스터타입, 2.이동타입, 3.공격 타입, x좌표, y좌표
	if (10 == m_Tick) {


		CreateMonster(MT04, MMPA(MMP01), MAP01, 300, -100);

		CreateMonster(MT03, MMPA(MMP01), MAP01, 150, -500);
		CreateMonster(MT03, MMPA(MMP01), MAP01, 230, -500);
		CreateMonster(MT03, MMPA(MMP01), MAP01, 310, -500);
		CreateMonster(MT03, MMPA(MMP01), MAP01, 380, -500);
		CreateMonster(MT03, MMPA(MMP01), MAP01, 460, -500);


		for (int i = 0; i < 3; ++i)
		{
			CreateMonster(MT01, MMPA(MMP01), MAP01, 150, -300 - 80 * i);
			CreateMonster(MT01, MMPA(MMP01), MAP01, 230, -300 - 80 * i);
			CreateMonster(MT01, MMPA(MMP01), MAP01, 310, -300 - 80 * i);
			CreateMonster(MT01, MMPA(MMP01), MAP01, 380, -300 - 80 * i);
			CreateMonster(MT01, MMPA(MMP01), MAP01, 460, -300 - 80 * i);
		}

		for (int i = 0; i < 3; ++i)
		{
			CreateMonster(MT02, MMPA(MMP01), MAP01, 150, -300 - 80 * i);
			CreateMonster(MT02, MMPA(MMP01), MAP01, 230, -300 - 80 * i);
			CreateMonster(MT02, MMPA(MMP01), MAP01, 310, -300 - 80 * i);
			CreateMonster(MT02, MMPA(MMP01), MAP01, 380, -300 - 80 * i);
			CreateMonster(MT02, MMPA(MMP01), MAP01, 460, -300 - 80 * i);
		}
		

		++m_Tick;
	}
	else if (400 == m_Tick)
	{
	}
	else if (800 == m_Tick)
	{
	}
	else if (1200 == m_Tick)
	{
	}
	

	return 0;
}

void STAGE::Initialize()
{

}

void STAGE::CreateMonster(MON_TYPE mt, vector<CMMP> mmpv, MON_ATT_PATTERN mat, double x, double y)
{
	Monster_list->push_back(new CMonster(mt, mmpv, mat));
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
