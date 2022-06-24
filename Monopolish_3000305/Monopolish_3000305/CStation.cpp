// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CStation.h"

// default constructor
CStation::CStation(){}

// overloaded constructor
CStation::CStation(int type, string name, float cost, float rent) :CSquare(type, name)
{
	stCost = cost;
	stRent = rent;
	stationOwnerName = "None";
}

// destructor
CStation::~CStation(){}

// sets station cost
void CStation::setSCost(float cost)
{
	stCost = cost;
}

// returns station cost
float CStation::getSCost()
{
	return stCost;
}

// sets station rent
void CStation::setSRent(float rent)
{
	stRent = rent;
}

// returns station rent
float CStation::getSRent()
{
	return stRent;
}

// sets the owner for the station
void CStation::setSOwnerName(string ownerName)
{
	stationOwnerName = ownerName;
}

// returns the owner of the station
string CStation::getSOwnerName()
{
	return stationOwnerName;
}

// display station message
void CStation::displayPayingRentDetails(string playerName)
{
	cout << " Player " << playerName << " pays " << pound << stRent << " for ticket " << endl;
}

// display lands square details
void CStation::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
	cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
}
