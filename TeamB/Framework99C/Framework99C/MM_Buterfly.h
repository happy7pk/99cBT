#pragma once
#include "MM.h"
class CMM_Buterfly :
	public CMM
{
public:
	CMM_Buterfly();
	CMM_Buterfly(CGameObject* pMonster, MONSTER_MOVING_DIRECT _direct);
	virtual ~CMM_Buterfly();

	// CMM��(��) ���� ��ӵ�
	virtual void Moving() override;
};

