#pragma once
#include "CSquare.h"

class CFreeParking : public CSquare
{
public:
	CFreeParking();
	CFreeParking(int type, string name);
	~CFreeParking();
	void display(string playerName);
};