#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"

class CBonus: public CSquare
{
private:
	string bonusName;
	float bonusAmount;
	int secondDieValue;

public:
	CBonus();
	CBonus(int type, string name);
	~CBonus();
	void setBonus(int dieValue);
	string getBonusName();
	float getBonusAmount();
	void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};