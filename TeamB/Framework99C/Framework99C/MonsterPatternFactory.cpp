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
		//상단에서 내려와 좌측으로 사라지는 패턴
		return vector<CMMP>{ CMMP(VECTOR(90, MIDDLE), 600), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 500), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 1000), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 1500), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 2000), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 2500), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 3000), CMMP(VECTOR(180, 3), 800) };
	case MMP02:
		//상단에서 내려와 우측으로 사라지는 패턴
		return vector<CMMP>{ CMMP(VECTOR(90, MIDDLE), 600), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 500), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 1000), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 1500), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 2000), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 2500), CMMP(VECTOR(0, NOMOVE), 500, NOMOVE, 3000), CMMP(VECTOR(0  , 3), 800) };
		break;
	case MMP03:

		break;
	case MMP04:

		break;
	default:
		break;
	}

}
