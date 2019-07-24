#pragma once


class CGameObject;

class CMMP //Monster Move
{
protected:
	VECTOR			m_Vector;
	float			m_MoveDistance;
	unsigned int	m_iUpdateCount;
	clock_t			m_time;
	MON_MOVE_TYPE	m_mmt;

public:
	bool IsEnd()
	{
		return m_Vector.Length * m_iUpdateCount >= m_MoveDistance;
	}

public:
	explicit CMMP(VECTOR _v, float _movedistance, MON_MOVE_TYPE mmt = MMT01)
		: m_Vector(_v), m_MoveDistance(_movedistance), m_iUpdateCount(0), m_mmt(mmt)
	{
		m_time = clock();
	}
	 ~CMMP()
	{

	}
	


public:
	CMMP() {};
	VECTOR& Moving() {

		if (m_Vector.Length == 77777)
			return VECTOR(0, 0);

		return m_Vector;
	};
	void Update()
	{
		++m_iUpdateCount;

		switch (m_mmt)
		{
		case NOMOVE:
			if (clock() - m_time > 700)
			{
				m_Vector.Length = 77777;
			}
			break;
		default:
			break;
		}
	}
};