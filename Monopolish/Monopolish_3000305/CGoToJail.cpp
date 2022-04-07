#include "CGoToJail.h"

// default constructor
CGoToJail::CGoToJail(){}

// overloaded constructor
CGoToJail::CGoToJail(int type, string name, float fine) :CSquare(type, name)
{
	sFine = fine;
}

// destructor
CGoToJail::~CGoToJail(){}

// sets square fine
void CGoToJail::setSFine(float fine)
{
	sFine = fine;
}

// returns square fine
float CGoToJail::getSFine()
{
	return sFine;
}

// display go to jail message
void CGoToJail::display(string playerName)
{
	cout << " Player " << playerName << " goes to jail " << endl;
	cout << " Player " << playerName << " pays " << pound << "50 " << endl;
}