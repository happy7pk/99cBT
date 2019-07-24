#pragma once

// ������ ����

// �߻� ���丮 ����
// ������Ʈ�� ������ �� ����� ��Ҹ� ��Ƽ� ĸ��ȭ�� ������ ����.
class CGameObject;

#include "MM.h"

template <typename T>
class CAbstractFactory
{
public:
	static CGameObject* CreateObject()
	{
		CGameObject* pInstance = new T;
		pInstance->Initialize();

		return pInstance;
	}

	static CGameObject* CreateObject(double x, double y)
	{
		CGameObject* pInstance = new T;
		pInstance->Initialize();
		pInstance->SetPos(x, y);

		return pInstance;
	}

	static CMMP* CreateMM(CGameObject* pMonster, MONSTER_MOVING_DIRECT _direct)
	{
		CMMP* pInstance = new T(pMonster, _direct);
		return pInstance;
	}

};