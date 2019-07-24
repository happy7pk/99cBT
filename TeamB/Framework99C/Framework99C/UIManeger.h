#pragma once
class UIManeger
{
public:
	
	static UIManeger* ROAD() {
		static UIManeger* ui = new UIManeger;
		return ui;
	}




private:
	UIManeger();
	~UIManeger();
};

