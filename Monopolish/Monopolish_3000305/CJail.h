#pragma once
#include "CSquare.h"

class CJail : public CSquare
{
public:
	CJail();
	CJail(int type, string name);
	~CJail();
	void display(string playerName);
};