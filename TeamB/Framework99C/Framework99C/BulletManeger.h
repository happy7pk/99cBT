#pragma once
class BulletManeger
{
public:

	static BulletManeger* ROAD() {
		static BulletManeger* bulletmaneger = new BulletManeger;
		return bulletmaneger;
	}
	
	void Mpush_back(CGameObject* rhs) {
		Monster_Bulletlst.push_back(rhs);
	}
	void Ppush_back(CGameObject* rhs) {
		Player_Bulletlst.push_back(rhs);
	}
	
	~BulletManeger();

	list<CGameObject*>* Get_plist() {
		return &(this->Player_Bulletlst);
	}
	list<CGameObject*>* Get_mlist() {
		return &(this->Monster_Bulletlst);
	}

	void OutRengelst();
	void DeathCheck();
	void Render(HDC hDC);
private:
	BulletManeger();
	list<CGameObject*> Player_Bulletlst;
	list<CGameObject*> Monster_Bulletlst;
};

