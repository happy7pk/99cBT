#include "stdafx.h"
#include "Monster.h"
#include "Maingame.h"
#include "GameObject.h"
#include "PatternFactory.h"
#include "Bullet.h"
#include "BulletManeger.h"

#include "MM_Buterfly.h"
#include "MM_Transverse.h"

CMonster::CMonster()
{
}

CMonster::CMonster(MON_TYPE mt, MON_MOV_PATTERN mmp, MONSTER_MOVING_DIRECT dr)
	: Mon_Type(mt),Mon_Mov_Pattern(mmp), Mon_Mov_Direct(dr)
{
	Initialize();
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	Exist = 1;
	//���� ��ǥ, ũ�� ����
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fSpeed = 5.f;
	m_AttSpeed = 10;

	CreateMovePattern();

}

int CMonster::Update()
{
	//���ʹ� ���˻縦 ���� �ʴ´�.
	if (GetExist()==0)
		return DEAD_OBJ;
	

	m_Move->Moving();

	//-----------------------
	//�ڵ带 �Է��ϼ���.
	
	//-----------------------




	//��ü�� ������ �ִ� �Ѿ� ������Ʈ
	
	
	//�Ѿ� ���˻�
	//OBJLIST::iterator iter = m_pBulletLst.begin();
	//for (iter; iter != m_pBulletLst.end();)
	//{
	//	if ((*iter)->GetExist() == 0)
	//		iter = m_pBulletLst.erase(iter);
	//	else
	//		iter++;
	//}

	return NO_EVENT;
}

void CMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC,m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	//-----------------------
	// �ڵ带 �Է��ϼ���.
	//-----------------------



	//��ü�� ������ �ִ� �Ѿ� ���
	
}


void CMonster::IsMoving()
{
}

bool CMonster::DeathCheck()
{
	if (Exist == 0)
		return TRUE;
	return FALSE;
}

void CMonster::CreateMovePattern()
{
	switch (Mon_Mov_Pattern)
	{
	case MMP01:
		m_Move = CAbstractFactory<CMM_Buterfly>::CreateMM(this, Mon_Mov_Direct);
		break;
	case MMP02:
		m_Move = CAbstractFactory<CMM_Buterfly>::CreateMM(this, Mon_Mov_Direct);
		break;
	default:
		break;
	}
}


void CMonster::Release()
{
	SafeDelete(m_Move);
}


void CMonster::CreateBullet()
{
	BulletManeger::ROAD()->Mpush_back(new CBullet(m_tInfo.fX, m_tInfo.fY, PI / 2, m_AttSpeed));
	
}

void CMonster::CreateBullet(BULLET_TYPE bt)
{
	BulletManeger::ROAD()->Mpush_back(new CBullet(m_tInfo.fX, m_tInfo.fY, PI / 2, m_AttSpeed, bt));
}

void CMonster::CreateBullet(THETA th)
{
	BulletManeger::ROAD()->Mpush_back(new CBullet(m_tInfo.fX, m_tInfo.fY, th, m_AttSpeed));
}

void CMonster::CreateBullet(BULLET_PATTERN pattern)
{
	switch (pattern)
	{
	case P01:
		PatternFactory::ROAD()->PT01(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_DOWN);
		break;
	case P02:
		PatternFactory::ROAD()->PT02(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_DOWN);
		break;
	case P03:
		PatternFactory::ROAD()->PT03(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_DOWN);
		break;
	case P04:
		PatternFactory::ROAD()->PT04(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_DOWN);
		break;
	case P05:
		PatternFactory::ROAD()->PT05(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_DOWN);
		break;
	}
}


void CMonster::CreateBullet(int angle)
{
	CreateBullet
	(angle / 180 * PI);
}

void CMonster::CreateBullet_N(int N)
{
	PatternFactory::ROAD()->PTNN(m_tInfo.fX, m_tInfo.fY, (*BulletManeger::ROAD()->Get_mlist()), N, SHOT_DOWN);
}




