#include "stdafx.h"
#include "MAP1.h"
#include "Resource.h"


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
	//맵의 출력좌표 조절
	return 0;
}

void MAP1::Render(HDC hDC, HDC MemDC)
{

//	MemDC = CreateCompatibleDC(hDC); // 메모리 DC를 가져옴
//	MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
//	OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);
//	BitBlt(hDC, 0, 0, WINCX, WINCY, MemDC, 0, 0, SRCCOPY);
//	SelectObject(MemDC, OldBitmap);
//	//Rectangle(hDC, 0, 0, WINCX, WINCY);

	
	
}

void MAP1::Set_Tick(int tick)
{
	m_Tick = tick;
}

MAP1::~MAP1()
{
	
}
