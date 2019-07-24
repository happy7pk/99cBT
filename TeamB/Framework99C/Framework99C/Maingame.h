#pragma once

class MAP1;
class STAGE;
class CGameObject;
class CMaingame
{
public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();

public:
	void SendTick();
	void MonDeathCheck();

public:
	HDC					m_hDC;	
	list<CGameObject*>	m_ObjLst[OBJECT_END];
	clock_t				m_Oldtick;
	clock_t				m_Curtick;
	int					m_tick;


};

