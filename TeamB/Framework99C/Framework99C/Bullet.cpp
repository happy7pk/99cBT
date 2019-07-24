#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet(){}
CBullet::CBullet(double x, double y,VECTOR vec, BULLET_TYPE bt)
	:Vec(vec),m_bullet_type(bt)
{
	m_bullet_type = bt;
	m_tInfo.fX = x;
	m_tInfo.fY = y;
	Initialize();

}
CBullet::CBullet(double x, double y, THETA th, double length, BULLET_TYPE bt)
{
	m_bullet_type = bt;
	switch (m_bullet_type)
	{
	case BT01:
		Exist = 1;
		m_tInfo.fX = x;
		m_tInfo.fY = y;
		Vec.Angle = th/180*PI;
		Vec.Length = length;
		m_tInfo.fCX = 20.f;
		m_tInfo.fCY = 20.f;
		m_fSpeed = 5.f;
		Initialize();
		break;
	case BT02:
		Exist = 1;
		m_tInfo.fX = x;
		m_tInfo.fY = y;
		Vec.Angle = th;
		Vec.Length = length;
		m_tInfo.fCX = 10.f;
		m_tInfo.fCY = 10.f;
		m_fSpeed = 10.f;
		Initialize();
		break;
	
	}
	
}
CBullet::~CBullet() {Release();}
void CBullet::Release(){}


void CBullet::Initialize()
{

	switch (m_bullet_type)
	{
	case BT01:
		m_tInfo.fCX = 20.f;
		m_tInfo.fCY = 20.f;
		m_fSpeed = 5.f;
		break;


	}
	
}

int CBullet::Update()
{
	if (Exist == 0)return 1;

	IsMoving();
	IsOutRange();	

	return 0;
}

void CBullet::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	switch (m_bullet_type)
	{
	case BT01:
		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		break;
	}

}



void CBullet::IsMoving()
{
	m_tInfo.fX += Vec.Length*cos(Vec.Angle);
	m_tInfo.fY += Vec.Length*sin(Vec.Angle);
}

void CBullet::IsOutRange()
{
	CGameObject::UpdateRect();
	if (0 >= m_tRect.left || 0 >= m_tRect.top
		|| WINCX <= m_tRect.right || WINCY <= m_tRect.bottom)
		Exist = FALSE;
}
