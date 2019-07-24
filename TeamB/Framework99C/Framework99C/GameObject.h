#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	const INFO& GetInfo() const;
	const RECT& GetRect() const;
	const double GetSpeed() const;
	const bool GetExist() const;

public:
	void SetPos(double x, double y);
	void PlusX(double x);
	void PlusY(double y);
	void Dead();

	// virtual
public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

public:
	CGameObject& operator+=(VECTOR &RHS);
	CGameObject& operator-=(VECTOR &RHS);


protected:
	virtual void Release() = 0;
 
protected:
	void UpdateRect();

protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	double	m_fSpeed;
	bool	Exist=1;
	double   m_AttSpeed;

};

