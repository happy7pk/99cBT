#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}

const INFO & CGameObject::GetInfo() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_tInfo;
}

const RECT & CGameObject::GetRect() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_tRect;
}

const double CGameObject::GetSpeed() const
{
	return 20; //속도
}

const bool CGameObject::GetExist() const
{
	return Exist;
}

void CGameObject::SetPos(double x, double y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
}
void CGameObject::PlusX(double x)
{
	m_tInfo.fX += x;
}

void CGameObject::PlusY(double y)
{
	m_tInfo.fY += y;
}

void CGameObject::Dead()
{
	Exist = 0;
}


CGameObject & CGameObject::operator+=(VECTOR & RHS)
{
	double x = RHS.Length * cos(RHS.Angle);
	double y = RHS.Length * sin(RHS.Angle);
	PlusX(+x);
	PlusY(+y);
	return *this;
}

CGameObject & CGameObject::operator-=(VECTOR & RHS)
{
	double x = RHS.Length * cos(RHS.Angle);
	double y = RHS.Length * sin(RHS.Angle);
	PlusX(-x);
	PlusY(-y);
	return *this;
}

bool CGameObject::Set_Col()
{
	m_Col = 1;
	return TRUE;
}

bool CGameObject::Get_COl()
{
	if (m_Col == 1) {
		m_Col = 0;
		return 1;
	}
	else
		return 0;
}


void CGameObject::UpdateRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}
