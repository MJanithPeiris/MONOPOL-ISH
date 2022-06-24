// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CFreeParking.h"

// default constructor
CFreeParking::CFreeParking(){}

// overloaded constructor
CFreeParking::CFreeParking(int type, string name) :CSquare(type, name){}

// destructor
CFreeParking::~CFreeParking(){}

// display free parking message
void CFreeParking::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
	cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
	cout << " Player " << player->getPlayerName() << " is resting " << endl;
}