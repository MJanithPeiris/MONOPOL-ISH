#pragma once
#include "CSquare.h"

class CGoToJail : public CSquare
{
private:
	float sFine;
public:
	CGoToJail();
	CGoToJail(int type, string name, float fine);
	~CGoToJail();
	void setSFine(float fine);
	float getSFine();
	void display(string playerName);
};