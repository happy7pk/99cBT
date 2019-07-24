#include "stdafx.h"
#include "BulletManeger.h"
#include "Bullet.h"

void BulletManeger::OutRengelst()
{
	for (auto& i : Player_Bulletlst)
	{
		if (0 >= i->GetRect().left || 0 >= i->GetRect().top
			|| WINCX <= i->GetRect().right || WINCY <= i->GetRect().bottom)
			i->Dead();
	}
	for (auto& i : Monster_Bulletlst)
	{
		if (0 >= i->GetRect().left || 0 >= i->GetRect().top
			|| WINCX <= i->GetRect().right || WINCY <= i->GetRect().bottom)
			i->Dead();
	}
}

void BulletManeger::DeathCheck()
{
	list<CGameObject*>::iterator iter = Player_Bulletlst.begin();
	for (iter; iter != Player_Bulletlst.end();)
	{
		if ((*iter)->GetExist() == 0)
		{
			delete *iter;
			iter = Player_Bulletlst.erase(iter);
		}
		else
			iter++;
	}
	iter = Monster_Bulletlst.begin();
	for (iter; iter != Monster_Bulletlst.end();)
	{
		if ((*iter)->GetExist() == 0)
		{
			delete *iter;
			iter = Monster_Bulletlst.erase(iter);
		}
		else
			iter++;
	}
}

void BulletManeger::Render(HDC hDC)
{
	for (auto& i : Player_Bulletlst)
	{	
			i->Render(hDC);
	}
	for (auto& i : Monster_Bulletlst)
	{
		
			i-> Render(hDC);
	}
}

BulletManeger::BulletManeger()
{
}


BulletManeger::~BulletManeger()
{
}
