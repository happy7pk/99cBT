#pragma once
#include "GameObject.h"
class CBullet :
	public CGameObject
{
public:
	CBullet(double x, double y,VECTOR vec, BULLET_TYPE bt=BT01);
	CBullet(double x, double y,THETA, double, BULLET_TYPE bt=BT01);
	virtual ~CBullet();

public:


public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;
	CBullet();

private:
	void IsMoving();
	void IsOutRange();

	

private:
	VECTOR Vec;
	BULLET_TYPE m_bullet_type;
	THETA angle;
};

