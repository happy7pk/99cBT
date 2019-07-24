#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "PatternFactory.h"
#include "BulletManeger.h"
CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}



void CPlayer::Initialize()
{
	Exist = 1;
	//���� ��ǥ, ũ�� ����
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_AttSpeed = 10;
	m_fSpeed = 5;
}

int CPlayer::Update()
{
	KeyInput();
	//IsOutRenge();


	//
	//-----------------------
	//�ڵ带 �Է��ϼ���.
	//-----------------------

	

	return NO_EVENT;
}

void CPlayer::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	//-----------------------
	//�ڵ带 �Է��ϼ���.
	//-----------------------


}

void CPlayer::Release()
{
}


void CPlayer::KeyInput()
{	
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		CreateBullet_N(36);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		CreateBullet(P01);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{ 
		CreateBullet(70);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		CreateBullet();
	}
	if (GetAsyncKeyState(0x41) & 0x8000)
	{
		CreateBullet_N(5);
	}
}

void CPlayer::IsOutRenge()
{
	//�÷��̾��� ���˻�
}

void CPlayer::CreateBullet()
{
	BulletManeger::ROAD()->Ppush_back(new CBullet(m_tInfo.fX, m_tInfo.fY,-PI/2, m_AttSpeed));
}

void CPlayer::CreateBullet(BULLET_TYPE bt)
{
	BulletManeger::ROAD()->Ppush_back(new CBullet(m_tInfo.fX, m_tInfo.fY, -PI / 2, m_AttSpeed,bt));
}

void CPlayer::CreateBullet(THETA th)
{
	BulletManeger::ROAD()->Ppush_back(new CBullet(m_tInfo.fX, m_tInfo.fY, th, m_AttSpeed));
}

void CPlayer::CreateBullet(BULLET_PATTERN pattern)
{
	switch (pattern)
	{
	case P01:
		PatternFactory::ROAD()->PT01(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(),SHOT_UP);
		break;
	case P02:
		PatternFactory::ROAD()->PT02(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(),SHOT_UP);
		break;
	case P03:
		PatternFactory::ROAD()->PT03(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_UP);
		break;
	case P04:
		PatternFactory::ROAD()->PT04(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_UP);
		break;
	case P05:
		PatternFactory::ROAD()->PT05(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), SHOT_UP);
		break;
	}
}

void CPlayer::CreateBullet(int angle)
{
	CreateBullet(angle / 180 * PI);
}

void CPlayer::CreateBullet_N(int N)
{
	PatternFactory::ROAD()->PTNN(m_tInfo.fX, m_tInfo.fY, *BulletManeger::ROAD()->Get_plist(), N, SHOT_UP);
}
