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

private: //�Ѿ� ���� �Լ���
	void CreateBullet();					//�⺻ �����Դϴ�.
	void CreateBullet(BULLET_TYPE);			//�ٸ� �̻����� ���ϴ�
	void CreateBullet(THETA);				//��Ÿ ������ �־��ݴϴ�.
	void CreateBullet(BULLET_PATTERN);		//���ϰ��忡 �ִ� ���Ϲ�ȣ�� �ֽ��ϴ�.
	void CreateBullet(int angle);			//�츮�� �ƴ� ������ �־��ָ� �ű�� ���ϴ�.					
	void CreateBullet_N(int N);				//N�������� �л��ϴ� ������ N�� �����Է��ؼ� �����մϴ�.

	

private:	
	PLAYER_LEVEL player_level;
	PLAYER_STATE player_state;
};

