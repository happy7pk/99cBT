#include "stdafx.h"
#include "CollsionMgr.h"
#include "GameObject.h"

CCollsionMgr::CCollsionMgr()
{
}
CCollsionMgr::~CCollsionMgr()
{
}

void CCollsionMgr::CollisionRect(const OBJLIST& dstLst, const OBJLIST& srcLst)
{
	RECT rc = {};

	for (auto& pDest : dstLst)
	{
		if (pDest->GetExist() == 0)
			continue;
		for (auto& pSource : srcLst)
		{
			if (pSource->GetExist() == 0)
				continue;
	
			if (IntersectRect(&rc, &(pDest->GetRect()), &(pSource->GetRect())))
			{
				pDest->Dead();
				pSource->Dead();
			}
			else {
				pDest->Get_Col();
				pSource->Get_Col();
			}
		}
	}
}
