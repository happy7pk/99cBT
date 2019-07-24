#pragma once
class CCollsionMgr
{
public:
	CCollsionMgr();
	~CCollsionMgr();

public:
	static void CollisionRect(const OBJLIST& dstLst, const OBJLIST& srcLst);
private:
};

