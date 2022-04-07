#include "CJail.h"

// default constructor
CJail::CJail(){}

// overloaded constructor
CJail::CJail(int type, string name) :CSquare(type, name){}

// destructor
CJail::~CJail(){}

// display jail message
void CJail::display(string playerName)
{
	cout << " Player " << playerName << " is just visiting " << endl;
}