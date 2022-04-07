#pragma once
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
	void setOwnerName(string ownerName);
	string getOwnerName();
	void display(string playerName);
};