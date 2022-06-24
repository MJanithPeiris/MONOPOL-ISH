// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include <iostream>
#include "CProperty.h"

using namespace std;

// default constructor
CProperty::CProperty() {}

// overloaded constructor
CProperty::CProperty(int type, string name, float cost, float rent, int colourGroup) :CSquare(type, name) {
    sCost = cost;
    sRent = rent;
    sColourGroup = colourGroup;
    propertyOwnerName = "None";
}

// distructor
CProperty::~CProperty()
{

}

// sets property cost
void CProperty::setSCost(float cost)
{
    sCost = cost;
}

// returns sCost
float CProperty::getSCost()
{
    return sCost;
}

// sets property rent
void CProperty::setSRent(float rent)
{
    sRent = rent;
}

// returns property rent
float CProperty::getSRent()
{
    return sRent;
}

// sets property colour group
void CProperty::setSColourGroup(int colourGroup)
{
    sColourGroup = colourGroup;
}

// returns property colour group
int CProperty::getSColourGroup()
{
    return sColourGroup;
}

// sets the owner for the property
void CProperty::setSOwnerName(string ownerName)
{
    propertyOwnerName = ownerName;
}

// returns the owner of the property
string CProperty::getSOwnerName()
{
    return propertyOwnerName;
}

// display type name cost rent and colour group
void CProperty::display()
{
    cout << " " << sType << " - " << sName << " - " << sCost << " - " << sRent << " - " << sColourGroup << endl;
}

// display player paying rent details
void CProperty::displayPayingRentDetails(string playerName)
{
    cout << " " << playerName << " pays " << sRent << endl;
}

// display lands square details
void CProperty::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
    cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
}