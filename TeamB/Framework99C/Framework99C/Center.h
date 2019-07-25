#pragma once
#include "GameObject.h"
#include "Player.h"
class Center
{
public:
	static Center* ROAD() {
		static Center* cnt = new Center;
		return cnt;
	}

	MAIN_STATE Get_MainState() {
		return main_state;
	}
	void Set_MainState(MAIN_STATE ms) {
		main_state = PLAY;
	}

	PLAYER_STATE Get_PlayerState() {
		return player_state;
	}
	void Set_PlayerState(PLAYER_STATE ps) {
		player_state = ps;
	}

public: //����
	void Set_Player(CGameObject* p)
	{
		m_pPlayer = p;
	}


public: //����
	THETA Get_pVec(double x, double y) { //�÷��̾��ϰ� ��ü���� ���� ��ȯ
		double lx = x - m_pPlayer->GetInfo().fX;
		double ly = y - m_pPlayer->GetInfo().fY;
		double angle = atan2(lx, ly);
		return angle;
	}
	VECTOR Get_pVec(double x, double y, double speed) // �÷��̾ ���� ���͹�ȯ
	{
		VECTOR temp;
		double lx = x - m_pPlayer->GetInfo().fX;
		double ly = y - m_pPlayer->GetInfo().fY;
		double angle = atan2(lx, ly);
		temp.Angle = angle;
		temp.Length = speed;
		return temp;
	}

private:
	Center();
	~Center();
	MAIN_STATE main_state = PLAY;       // ���� ����
	PLAYER_STATE player_state = PS01; // �÷��̾� ����
	CGameObject* m_pPlayer;

};

