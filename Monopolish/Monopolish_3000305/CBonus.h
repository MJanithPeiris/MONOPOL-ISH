#pragma once
#include "CSquare.h"

class CBonus: public CSquare
{
private:
	string bonusName;
	float bonusAmount;

public:
	CBonus();
	CBonus(int type, string name);
	~CBonus();
	void setBonus(int diceValue);
	string getBonusName();
	float getBonusAmount();
	void display(string playerName, float playerMoney);
};