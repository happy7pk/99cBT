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
	//��� ƽ��ȭ�� Plustick���� ����

	//���� ƽ�� ������ ���� ���� ����
	//CreateMonster ��� ���
	//1.����Ÿ��, 2.�̵�Ÿ��, 3.���� Ÿ��, x��ǥ, y��ǥ
	if (m_Tick == 10) {

		for (int i = 0; i < 10; ++i)
		{
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 220, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 240, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 260, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 280, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 300, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 320, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 340, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 360, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 380, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 400, -400);
		}
		

		++m_Tick;
	}
	else if (m_Tick == 150)
	{
		for (int i = 0; i < 10; ++i)
		{
			
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 220, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 240, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 260, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 280, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 300, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 320, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 340, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 360, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 380, -400);
			CreateMonster(MT01, m_PatternVector[MMP01], MAP01, 400, -400);
		}
	}

	

	return 0;
}

void STAGE::Initialize()
{
	m_PatternVector.reserve(50);

	m_PatternVector.push_back(vector<CMMP>{ CMMP(VECTOR(90,3),600),CMMP(VECTOR(0,0),500,NOMOVE, 500), CMMP(VECTOR(0, 0), 500, NOMOVE, 1000), CMMP(VECTOR(0, 0), 500, NOMOVE, 1500), CMMP(VECTOR(0, 0), 500, NOMOVE, 2000), CMMP(VECTOR(0, 0), 500, NOMOVE, 2500), CMMP(VECTOR(0, 0), 500, NOMOVE,3000), CMMP(VECTOR(180, 2), 800) });
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
