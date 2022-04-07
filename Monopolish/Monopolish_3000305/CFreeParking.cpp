#include "CFreeParking.h"

// default constructor
CFreeParking::CFreeParking(){}

// overloaded constructor
CFreeParking::CFreeParking(int type, string name) :CSquare(type, name){}

// destructor
CFreeParking::~CFreeParking(){}

// display free parking message
void CFreeParking::display(string playerName)
{
	cout << " Player " << playerName << " is resting " << endl;
}