#pragma once
#include "CSquare.h"

class CPenalty:public CSquare
{
private:
	string penaltyName;
	float penaltyAmount;

public:
	CPenalty();
	CPenalty(int type, string name);
	~CPenalty();
	void setPenalty(int diceValue);
	string getPenaltyName();
	float getPenaltyAmount();
	void display(string playerName, float playerMoney);
};