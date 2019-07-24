#pragma once
class MAP1
{
public:

	static MAP1* ROADMAP();
	int Update();
	void Render(HDC hDC);
	void Set_Tick(int tick);
	~MAP1();
	
private:
	MAP1();
	int m_Tick;



	
};

