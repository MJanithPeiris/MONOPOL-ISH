#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"

class CFreeParking : public CSquare
{
public:
	CFreeParking();
	CFreeParking(int type, string name);
	~CFreeParking();
	void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};