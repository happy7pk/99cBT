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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_tInfo;
}

const RECT & CGameObject::GetRect() const
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_tRect;
}

const double CGameObject::GetSpeed() const
{
	return 20; //�ӵ�
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

void CGameObject::UpdateRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}
