// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CJail.h"

// default constructor
CJail::CJail(){}

// overloaded constructor
CJail::CJail(int type, string name) :CSquare(type, name){}

// destructor
CJail::~CJail(){}

// display jail message
void CJail::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
	cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
	cout << " Player " << player->getPlayerName() << " is just visiting " << endl;
}