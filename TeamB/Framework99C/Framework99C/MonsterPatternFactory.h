#pragma once

class CMonsterPatternFactory
{
private:
	CMonsterPatternFactory();
public:
	~CMonsterPatternFactory();

public:
	static vector<CMMP> GetMovePatternArray(MON_MOV_PATTERN _mmp);
};

