#pragma once

class CMonsterPatternFactory
{
private:
	CMonsterPatternFactory();
public:
	~CMonsterPatternFactory();

public:
	static CMonsterPatternFactory* ROAD()
	{
		static CMonsterPatternFactory* pInstance = new CMonsterPatternFactory;
		return pInstance;
	}

public:
	vector<CMMP> GetMovePatternArray(MON_MOV_PATTERN _mmp);
};

