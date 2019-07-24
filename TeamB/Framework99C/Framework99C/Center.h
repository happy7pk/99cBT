#pragma once
#include "GameObject.h"

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

public: //세터



private:
	Center();
	~Center();
	MAIN_STATE main_state = PLAY;       // 메인 상태
	PLAYER_STATE player_state = PS01; // 플레이어 상태


};

