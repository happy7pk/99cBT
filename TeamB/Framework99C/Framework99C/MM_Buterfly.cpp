#include "stdafx.h"
#include "MM_Buterfly.h"
#include "Monster.h"

CMM_Buterfly::CMM_Buterfly()
{
}

CMM_Buterfly::CMM_Buterfly(CGameObject * pMonster, MONSTER_MOVING_DIRECT _direct)
	:CMM(pMonster,_direct)
{
}


CMM_Buterfly::~CMM_Buterfly()
{
}

void CMM_Buterfly::Moving()
{
	++m_iUpdatedCount;

	unsigned int iPhase1 = 50;      //화면밖에서 등장까지의 카운트
	unsigned int iPhase2 = 240;		//머무르는 카운트
	unsigned int iPhase3 = 290;		//사라지는 + 라이프타임 카운트

	if (m_iUpdatedCount <= iPhase1)
	{
		m_pMonster->PlusX(m_pMonster->GetSpeed() * m_Direct / sqrtf(2.f));
		m_pMonster->PlusY(m_pMonster->GetSpeed() * -1 / sqrtf(2.f));
	}
	else if (m_iUpdatedCount > iPhase1 && m_iUpdatedCount <= iPhase2)
	{
		if (m_iUpdatedCount % 10 == 0)
		{
			dynamic_cast<CMonster*>(m_pMonster)->CreateBullet(180);
		}
	}
	else if (m_iUpdatedCount > iPhase2 && m_iUpdatedCount <= iPhase3)
	{
		m_pMonster->PlusX(m_pMonster->GetSpeed() * m_Direct * -1 / sqrtf(2.f));
		m_pMonster->PlusY(m_pMonster->GetSpeed() * -1 / sqrtf(2.f));
	}
	else
	{
		m_pMonster->Dead();
	}
}
