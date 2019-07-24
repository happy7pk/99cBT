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

	unsigned int iPhase1 = 120;      //화면밖에서 등장까지의 카운트
	unsigned int iPhase2 = 500;		//머무르는 카운트
	unsigned int iPhase3 = 800;		//사라지는 + 라이프타임 카운트

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
