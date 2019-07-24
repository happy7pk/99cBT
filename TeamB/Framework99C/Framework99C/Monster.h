#pragma once
#include "GameObject.h"

class CMM;

class CMonster :
	public CGameObject
{
public:
	CMonster();
	CMonster(MON_TYPE,MON_MOV_PATTERN, MONSTER_MOVING_DIRECT);
	virtual ~CMonster();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();

public: //총알 생성 함수들
	void CreateBullet();					//기본 공격입니다.
	void CreateBullet(BULLET_TYPE);			//다른 미사일을 쏩니다
	void CreateBullet(THETA);				//세타 방향을 넣어줍니다.
	void CreateBullet(BULLET_PATTERN);		//패턴공장에 있는 패턴번호를 넣습니다.
	void CreateBullet(int angle);			//우리가 아는 각도를 넣어주면 거기로 쏩니다.					
	void CreateBullet_N(int N);				//N방향으로 분사하는 패턴을 N을 직접입력해서 생성합니다.


	bool DeathCheck();

private:
	void CreateMovePattern();

private:
	MON_STATE				Mon_State;
	MON_TYPE				Mon_Type;
	MON_MOV_PATTERN			Mon_Mov_Pattern;
	MONSTER_MOVING_DIRECT	Mon_Mov_Direct;
	CMM*					m_Move;
};

//몬스터의 해제시점은 STAGE에서 관리
