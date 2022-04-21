#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"

class CGoToJail : public CSquare
{
private:
	float sFine;
	void sendPlayerToJail(unique_ptr<Player>& player);
public:
	CGoToJail();
	CGoToJail(int type, string name, float fine);
	~CGoToJail();
	void setSFine(float fine);
	float getSFine();
	void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};