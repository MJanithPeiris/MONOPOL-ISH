// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CPenalty.h"

// default constructor
CPenalty::CPenalty(){}

// overloaded constructor
CPenalty::CPenalty(int type, string name) :CSquare(type, name)
{
	penaltyAmount = 0;
	penaltyName = " ";
	secondDieValue = 0;
}

// destructor
CPenalty::~CPenalty(){}

// sets penalty name and amount
void CPenalty::setPenalty(int dieValue)
{
	switch (dieValue) // assign the penalty according to the die value
	{
	case 1:penaltyName = "Buy a coffee in Starbucks."; penaltyAmount = 20; secondDieValue = 1; break;
	case 2:penaltyName = "Pay your broadband bill."; penaltyAmount = 50; secondDieValue = 2; break;
	case 3:penaltyName = "Visit the SU shop for food."; penaltyAmount = 100; secondDieValue = 3; break;
	case 4:penaltyName = "Buy an assignment solution."; penaltyAmount = 150; secondDieValue = 4; break;
	case 5:penaltyName = "Go for a romantic meal."; penaltyAmount = 200; secondDieValue = 5; break;
	case 6:penaltyName = "Pay some university fees."; penaltyAmount = 300; secondDieValue = 6; break;
	default: penaltyName = "Error Wrong die number!!"; penaltyAmount = 0; 
	}
}

// returns penalty name
string CPenalty::getPenaltyName()
{
	return penaltyName;
}

// returns penalty amount
float CPenalty::getPenaltyAmount()
{
	return penaltyAmount;
}

// display penalty message
void CPenalty::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
	cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
	player->displayDieRollDetails(secondDieValue); // display die value
	cout << " " << penaltyName << " Loose " << pound << penaltyAmount << endl;
	cout << " Player " << player->getPlayerName() << " current balance is " << pound << player->getPlayerMoney() << endl;
}