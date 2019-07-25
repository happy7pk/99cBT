#include "stdafx.h"
#include "MonsterPatternFactory.h"


CMonsterPatternFactory::CMonsterPatternFactory()
{
}


CMonsterPatternFactory::~CMonsterPatternFactory()
{
}

vector<CMMP> CMonsterPatternFactory::GetMovePatternArray(MON_MOV_PATTERN _mmp)
{

	switch (_mmp)
	{
	case MMP01:
		return vector<CMMP>{ CMMP(VECTOR(90, 3), 600), CMMP(VECTOR(0, 0), 500, NOMOVE, 500), CMMP(VECTOR(0, 0), 500, NOMOVE, 1000), CMMP(VECTOR(0, 0), 500, NOMOVE, 1500), CMMP(VECTOR(0, 0), 500, NOMOVE, 2000), CMMP(VECTOR(0, 0), 500, NOMOVE, 2500), CMMP(VECTOR(0, 0), 500, NOMOVE, 3000), CMMP(VECTOR(180, 3), 800) };
	case MMP02:

		break;
	case MMP03:

		break;
	case MMP04:

		break;
	default:
		break;
	}

}
