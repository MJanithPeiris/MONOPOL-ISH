#include <iostream>
#include "CProperties.h"

using namespace std;

// default constructor
CProperties::CProperties() {}

// overloaded constructor
CProperties::CProperties(int type, string name, float cost, float rent, int colourGroup) :CSquare(type, name) {
    sCost = cost;
    sRent = rent;
    sColourGroup = colourGroup;
    propertyOwnerName = "None";
}

// distructor
CProperties::~CProperties()
{

}

// sets property cost
void CProperties::setSCost(float cost)
{
    sCost = cost;
}

// returns sCost
float CProperties::getSCost()
{
    return sCost;
}

// sets property rent
void CProperties::setSRent(float rent)
{
    sRent = rent;
}

// returns property rent
float CProperties::getSRent()
{
    return sRent;
}

// sets property colour group
void CProperties::setSColourGroup(int colourGroup)
{
    sColourGroup = colourGroup;
}

// returns property colour group
int CProperties::getSColourGroup()
{
    return sColourGroup;
}

// sets the owner for the property
void CProperties::setOwnerName(string ownerName)
{
    propertyOwnerName = ownerName;
}

// returns the owner of the property
string CProperties::getOwnerName()
{
    return propertyOwnerName;
}

// display type name cost rent and colour group
void CProperties::display()
{
    cout << " " << sType << " - " << sName << " - " << sCost << " - " << sRent << " - " << sColourGroup << endl;
}