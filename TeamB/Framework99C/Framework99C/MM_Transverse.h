#pragma once
#include "MM.h"
class CMM_Transverse :
	public CMM
{
public:
	CMM_Transverse();
	CMM_Transverse(CGameObject* pMonster, MONSTER_MOVING_DIRECT _direct);
	virtual ~CMM_Transverse();

	// CMM��(��) ���� ��ӵ�
	virtual void Moving() override;
};

