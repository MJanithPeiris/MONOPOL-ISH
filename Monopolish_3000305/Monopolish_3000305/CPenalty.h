#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"

class CPenalty:public CSquare
{
private:
	string penaltyName;
	float penaltyAmount;
	int secondDieValue;

public:
	CPenalty();
	CPenalty(int type, string name);
	~CPenalty();
	void setPenalty(int dieValue);
	string getPenaltyName();
	float getPenaltyAmount();
	void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};