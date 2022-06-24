// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CBonus.h"

// default constructor
CBonus::CBonus(){}

// overloaded constructor
CBonus::CBonus(int type, string name):CSquare(type,name)
{
	bonusAmount = 0;
	bonusName = " ";
	secondDieValue = 0;
}

// destructor
CBonus::~CBonus(){}

// sets bonus name and amount
void CBonus::setBonus(int dieValue)
{
	switch (dieValue) // assign the bonus according to the die value
	{
	case 1:bonusName = "Find some money."; bonusAmount = 20; secondDieValue = 1; break;
	case 2:bonusName = "Win a coding competition."; bonusAmount = 50; secondDieValue = 2; break;
	case 3:bonusName = "Receive a rent rebate."; bonusAmount = 100; secondDieValue = 3; break;
	case 4:bonusName = "Win the lottery."; bonusAmount = 150; secondDieValue = 4; break;
	case 5:bonusName = "Receive a bequest."; bonusAmount = 200; secondDieValue = 5; break;
	case 6:bonusName = "It’s your birthday."; bonusAmount = 300; secondDieValue = 6; break;
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
void CBonus::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
	cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
	player->displayDieRollDetails(secondDieValue); // display die value
	cout << " " << bonusName << " Gain " << pound << bonusAmount << endl;
	cout << " Player " << player->getPlayerName() << " current balance is " << pound << player->getPlayerMoney() << endl;
}