#pragma once


class CGameObject;

class CMM //Monster Move
{
protected:
	CGameObject* m_pMonster;
	unsigned int m_iUpdatedCount;

	MONSTER_MOVING_DIRECT m_Direct;

public:
	explicit CMM()
		: m_pMonster(nullptr), m_iUpdatedCount(0), m_Direct(NORMAL)
	{

	}
	explicit CMM(CGameObject* pMonster, MONSTER_MOVING_DIRECT _direct)
		:m_pMonster(pMonster) , m_iUpdatedCount(0), m_Direct(_direct)
	{

	}
	virtual ~CMM()
	{

	}

public:
	virtual void Moving() = 0;
};