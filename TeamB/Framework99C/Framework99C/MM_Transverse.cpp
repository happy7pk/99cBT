#include "stdafx.h"
#include "MM_Transverse.h"

#include "Monster.h"


CMM_Transverse::CMM_Transverse()
{
}

CMM_Transverse::CMM_Transverse(CGameObject * pMonster, MONSTER_MOVING_DIRECT _direct)
	:CMM(pMonster, _direct)
{

}


CMM_Transverse::~CMM_Transverse()
{
}

void CMM_Transverse::Moving()
{
	++m_iUpdatedCount;

	unsigned int iPhase1 = 120;      //ȭ��ۿ��� ��������� ī��Ʈ
	unsigned int iPhase2 = 500;		//�ӹ����� ī��Ʈ
	unsigned int iPhase3 = 800;		//������� + ������Ÿ�� ī��Ʈ

	if (m_iUpdatedCount <= iPhase1)
	{
		m_pMonster->PlusX(m_pMonster->GetSpeed() * m_Direct );
	}
	else if (m_iUpdatedCount > iPhase1 && m_iUpdatedCount <= iPhase2)
	{
		if (m_iUpdatedCount % 100 == 0)
		{
			dynamic_cast<CMonster*>(m_pMonster)->CreateBullet(90);
		}
	}
	else if (m_iUpdatedCount > iPhase2 && m_iUpdatedCount <= iPhase3)
	{
		m_pMonster->PlusX(m_pMonster->GetSpeed() * m_Direct);
	}
	else
	{
		m_pMonster->Dead();
	}
}
