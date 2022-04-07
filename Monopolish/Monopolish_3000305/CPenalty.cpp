#include "CPenalty.h"

// default constructor
CPenalty::CPenalty(){}

// overloaded constructor
CPenalty::CPenalty(int type, string name) :CSquare(type, name)
{
	penaltyAmount = 0;
	penaltyName = " ";
}

// destructor
CPenalty::~CPenalty(){}

// sets penalty name and amount
void CPenalty::setPenalty(int diceValue)
{
	switch (diceValue)
	{
	case 1:penaltyName = "Buy a coffee in Starbucks."; penaltyAmount = 20; break;
	case 2:penaltyName = "Pay your broadband bill."; penaltyAmount = 50; break;
	case 3:penaltyName = "Visit the SU shop for food."; penaltyAmount = 100; break;
	case 4:penaltyName = "Buy an assignment solution."; penaltyAmount = 150; break;
	case 5:penaltyName = "Go for a romantic meal."; penaltyAmount = 200; break;
	case 6:penaltyName = "Pay some university fees."; penaltyAmount = 300; break;
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
void CPenalty::display(string playerName, float playerMoney)
{
	cout << " " << penaltyName << " Loose " << pound << penaltyAmount << endl;
	cout << " Player " << playerName << " current balance is " << pound << playerMoney << endl;
}