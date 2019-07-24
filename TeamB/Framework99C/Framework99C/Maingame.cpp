#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"
#include "MAP1.h"
#include "STAGE.h"
#include "BulletManeger.h"
#include "GameObject.h"
CMaingame::CMaingame()	{}
CMaingame::~CMaingame(){Release();}

void CMaingame::Initialize()
{
	m_ObjLst[PLAYER].push_back(new CPlayer);
	m_ObjLst[PLAYER].front()->Initialize();
	STAGE::ROADSTAGE1()->set_monlist(&m_ObjLst[MONSTER]);
	// GetDC: 출력 DC 생성 함수.
	BulletManeger::ROAD();
		
	m_hDC = GetDC(g_hWnd);
	m_tick = 0;


	//TEST
	m_ObjLst[MONSTER].push_back(new CMonster(MT01, MMP01, NORMAL));
	m_ObjLst[MONSTER].front()->Initialize();
	
}

void CMaingame::Update()
{


	m_Curtick = clock();
	if (m_Curtick - m_Oldtick < 1000)
	{
		m_tick++;
		m_Oldtick = clock();
	}
	SendTick();

	MAP1::ROADMAP()	   ->Update();
	STAGE::ROADSTAGE1()->Update();
	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto& pObject : m_ObjLst[i])
			pObject->Update();
	}
	
	for (auto i : *BulletManeger::ROAD()->Get_mlist())
		i->Update();
	for (auto i : *BulletManeger::ROAD()->Get_plist())
		i->Update();


	//충돌체크
	BulletManeger::ROAD()->OutRengelst();
	CCollsionMgr::CollisionRect(m_ObjLst[PLAYER], m_ObjLst[MONSTER]);
	CCollsionMgr::CollisionRect(*(BulletManeger::ROAD()->Get_mlist()) , m_ObjLst[PLAYER]);
	CCollsionMgr::CollisionRect(*(BulletManeger::ROAD()->Get_plist()), m_ObjLst[MONSTER]);
	

	list<CGameObject*>::iterator iter = m_ObjLst[MONSTER].begin();

	for (iter; iter != m_ObjLst[MONSTER].end();)
	{
		if (dynamic_cast<CMonster*>(*iter)->DeathCheck())
			iter = m_ObjLst[MONSTER].erase(iter);
		else
			iter++;
	}
	BulletManeger::ROAD()->DeathCheck();
	
}

void CMaingame::Render()
{
	
	MAP1::ROADMAP()->Render(m_hDC, m_MemDC);


	for (auto i : *(BulletManeger::ROAD()->Get_mlist()))
		i->Render(m_hDC);
	for (auto i : *(BulletManeger::ROAD()->Get_plist()))
		i->Render(m_hDC);

	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto& pObject : m_ObjLst[i])
			pObject->Render(m_hDC);
	}

}


void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	for (int i = 0; i < OBJECT_END; ++i)
	{
		for_each(m_ObjLst[i].begin(), m_ObjLst[i].end(), SafeDelete<CGameObject*>);
		m_ObjLst[i].clear();
	}	
}

void CMaingame::SendTick()
{
	MAP1::ROADMAP()->Set_Tick(m_tick);
	STAGE::ROADSTAGE1()->Set_Tick(m_tick);
}

void CMaingame::MonDeathCheck()
{
	list<CGameObject*>::iterator iter = m_ObjLst[MONSTER].begin();
	for (iter; iter != m_ObjLst[MONSTER].end();)
	{
		if ((*iter)->GetExist() == 0)
		{
			delete *iter;
			iter = m_ObjLst[MONSTER].erase(iter);
		}
		else
			iter++;
	}
}
