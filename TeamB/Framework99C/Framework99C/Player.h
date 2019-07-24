#pragma once
#include "GameObject.h"
#include "Bullet.h"
class PatternFactory;
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;


private:
	virtual void Release() override;
	void KeyInput();
	void IsOutRenge();

private: //총알 생성 함수들
	void CreateBullet();					//기본 공격입니다.
	void CreateBullet(BULLET_TYPE);			//다른 미사일을 쏩니다
	void CreateBullet(THETA);				//세타 방향을 넣어줍니다.
	void CreateBullet(BULLET_PATTERN);		//패턴공장에 있는 패턴번호를 넣습니다.
	void CreateBullet(int angle);			//우리가 아는 각도를 넣어주면 거기로 쏩니다.					
	void CreateBullet_N(int N);				//N방향으로 분사하는 패턴을 N을 직접입력해서 생성합니다.

	

private:	
	PLAYER_LEVEL player_level;
	PLAYER_STATE player_state;
};

