#include "stdafx.h"
#include "MAP1.h"


MAP1::MAP1()
{
}


MAP1 * MAP1::ROADMAP()
{
	static MAP1* m_map = new MAP1;
	return m_map;
}

int MAP1::Update()
{
	//¸ÊÀÇ Ãâ·ÂÁÂÇ¥ Á¶Àý
	return 0;
}

void MAP1::Render(HDC hDC)
{
	
	Rectangle(hDC, 0, 0, WINCX, WINCY);
}

void MAP1::Set_Tick(int tick)
{
	m_Tick = tick;
}

MAP1::~MAP1()
{
	
}
