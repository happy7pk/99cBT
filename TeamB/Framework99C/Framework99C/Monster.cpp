#include "stdafx.h"
#include "Monster.h"
#include "Maingame.h"
#include "GameObject.h"
#include "PatternFactory.h"
#include "Bullet.h"
#include "BulletManeger.h"

#include "MM.h"


CMonster::CMonster()
{
}

CMonster::CMonster(MON_TYPE mt, vector<CMMP> mmpv, MON_ATT_PATTERN map)
	: Mon_Type(mt), Mon_Mov_Pattern(mmpv),Mon_Atk_Pattern(map), m_iMovArrIndex(0)
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

	//시작 좌표, 크기 설정

	switch (Mon_Type)
	{
	case MT01:
		m_tInfo.fCX = MOB_SIZE_MEDIUM;
		m_tInfo.fCY = MOB_SIZE_MEDIUM;
		m_fSpeed = 1.0f;
		m_AttSpeed = 10;
		break;
	case MT02:
		m_tInfo.fCX = MOB_SIZE_MEDIUM;
		m_tInfo.fCY = MOB_SIZE_MEDIUM;
		m_fSpeed = 1.0f;
		m_AttSpeed = 10;
		break;
	case MT03:
		m_tInfo.fCX = MOB_SIZE_SMALL;
		m_tInfo.fCY = MOB_SIZE_SMALL;
		m_fSpeed = 1.0f;
		m_AttSpeed = 10;
		break;
	case MT04:
		m_tInfo.fCX = MOB_SIZE_LARGE;
		m_tInfo.fCY = MOB_SIZE_LARGE;
		m_fSpeed = 1.0f;
		m_AttSpeed = 10;
		break;
	default:
		break;
	}
	


}


int CMonster::Update()
{
	//몬스터는 경계검사를 하지 않는다.
	if (GetExist()==0)
		return DEAD_OBJ;
	
	if (Mon_Mov_Pattern.size() > m_iMovArrIndex)
	{
		this->operator+=(Mon_Mov_Pattern[m_iMovArrIndex].Moving());
		Mon_Mov_Pattern[m_iMovArrIndex].Update();

		if (Mon_Mov_Pattern[m_iMovArrIndex].IsEnd())
		{
			CreateBullet(90);
			++m_iMovArrIndex;
		}
	}
	else
	{
		Dead();
	}
	

	//-----------------------
	//코드를 입력하세요.
	
	//-----------------------




	//객체가 가지고 있는 총알 업데이트
	
	
	//총알 경계검사
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
	// 코드를 입력하세요.
	//-----------------------



	//객체가 가지고 있는 총알 출력
	
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



void CMonster::Release()
{
	
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
	THETA temp;
	temp = angle;
	temp /= 180;
	temp *= PI;

	CreateBullet(temp);
}

void CMonster::CreateBullet_N(int N)
{
	PatternFactory::ROAD()->PTNN(m_tInfo.fX, m_tInfo.fY, (*BulletManeger::ROAD()->Get_mlist()), N, SHOT_DOWN);
}




