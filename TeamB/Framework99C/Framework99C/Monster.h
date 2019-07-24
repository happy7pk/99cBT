#pragma once
#include "GameObject.h"

class CMMP;

class CMonster :
	public CGameObject
{
public:
	CMonster();
	CMonster(MON_TYPE mt, vector<CMMP> mmpv, MON_ATT_PATTERN map);
	virtual ~CMonster();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();

public: //�Ѿ� ���� �Լ���
	void CreateBullet();					//�⺻ �����Դϴ�.
	void CreateBullet(BULLET_TYPE);			//�ٸ� �̻����� ���ϴ�
	void CreateBullet(THETA);				//��Ÿ ������ �־��ݴϴ�.
	void CreateBullet(BULLET_PATTERN);		//���ϰ��忡 �ִ� ���Ϲ�ȣ�� �ֽ��ϴ�.
	void CreateBullet(int angle);			//�츮�� �ƴ� ������ �־��ָ� �ű�� ���ϴ�.					
	void CreateBullet_N(int N);				//N�������� �л��ϴ� ������ N�� �����Է��ؼ� �����մϴ�.


	bool DeathCheck();

private:

private:
	MON_STATE				Mon_State;
	MON_TYPE				Mon_Type;
	MON_ATT_PATTERN			Mon_Atk_Pattern;
	vector<CMMP>			Mon_Mov_Pattern;
	int						m_iMovArrIndex;
	
};

//������ ���������� STAGE���� ����
