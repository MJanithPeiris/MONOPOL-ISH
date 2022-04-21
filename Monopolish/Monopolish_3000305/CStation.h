#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"

class CStation : public CSquare
{
private:
	float stCost;
	float stRent;
	string stationOwnerName;
public:
	CStation();
	CStation(int type, string name, float cost, float rent);
	~CStation();
	void setSCost(float cost);
	float getSCost();
	void setSRent(float rent);
	float getSRent();
	void setSOwnerName(string ownerName);
	string getSOwnerName();
	void displayPayingRentDetails(string playerName);
	void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};