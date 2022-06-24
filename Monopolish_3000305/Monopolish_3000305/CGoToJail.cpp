// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

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

// sends player to jail
void CGoToJail::sendPlayerToJail(unique_ptr<Player>& player)
{
	player->setPlayerPosition(7); // change player position to jail
}

// display go to jail message
void CGoToJail::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
	cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
	cout << " Player " << player->getPlayerName() << " goes to jail " << endl;
	cout << " Player " << player->getPlayerName() << " pays " << pound << sFine << endl;
	sendPlayerToJail(player);
}