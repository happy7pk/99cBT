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
	if (m_Tick < m_PlusTick)
		return 0;
	m_PlusTick = m_Tick;
	//��� ƽ��ȭ�� Plustick���� ����

	//���� ƽ�� ������ ���� ���� ����
	//CreateMonster ��� ���
	//1.����Ÿ��, 2.�̵�Ÿ��, 3.���� Ÿ��, x��ǥ, y��ǥ
	if (m_Tick == 10) {

		for (int i = 0; i < 10; ++i)
		{
			CreateMonster(MT01, MMP02, NORMAL, -1800 + i * 10, 400);
		}
		

		++m_Tick;
	}
	else if (m_Tick == 150)
	{

	}

	

	return 0;
}

void STAGE::CreateMonster(MON_TYPE mt, MON_MOV_PATTERN mmp, MONSTER_MOVING_DIRECT dr, double x, double y)
{
	Monster_list->push_back(new CMonster(mt, PA01,dr));
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
