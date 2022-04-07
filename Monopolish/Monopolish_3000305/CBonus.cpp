#include "CBonus.h"

// default constructor
CBonus::CBonus(){}

// overloaded constructor
CBonus::CBonus(int type, string name):CSquare(type,name)
{
	bonusAmount = 0;
	bonusName = " ";
}

// destructor
CBonus::~CBonus(){}

// sets bonus name and amount
void CBonus::setBonus(int diceValue)
{
	switch (diceValue)
	{
	case 1:bonusName = "Find some money."; bonusAmount = 20; break;
	case 2:bonusName = "Win a coding competition."; bonusAmount = 50; break;
	case 3:bonusName = "Receive a rent rebate."; bonusAmount = 100; break;
	case 4:bonusName = "Win the lottery."; bonusAmount = 150; break;
	case 5:bonusName = "Receive a bequest."; bonusAmount = 200; break;
	case 6:bonusName = "It’s your birthday."; bonusAmount = 300; break;
	default: bonusName = "Error Wrong die number!! "; bonusAmount = 0;
	}
}

// returns bonus name
string CBonus::getBonusName()
{
	return bonusName;
}

// returns bonus amount
float CBonus::getBonusAmount()
{
	return bonusAmount;
}

// display bonus message
void CBonus::display(string playerName, float playerMoney)
{
	cout << " " << bonusName << " Gain " << pound << bonusAmount << endl;
	cout << " Player " << playerName << " current balance is " << pound << playerMoney << endl;
}