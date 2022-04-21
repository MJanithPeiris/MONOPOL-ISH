#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"

class CJail : public CSquare
{
public:
	CJail();
	CJail(int type, string name);
	~CJail();
	void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};