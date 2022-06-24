// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"
#include <iostream>

// default constructor
CSquare::CSquare() {}

// overloaded constructor
CSquare::CSquare(int type, string name)
{
    sType = type;
    sName = name;
}

// destructor
CSquare::~CSquare() {}

// sets square type
void CSquare::setSType(int type)
{
    sType = type;
}

// returns square type value
int CSquare::getSType()
{
    return sType;
}

// sets square name
void CSquare::setSName(string name)
{
    sName = name;
}

// returns square name value
string CSquare::getSName()
{
    return sName;
}

// sets property rent. derived class method
void CSquare::setSRent(float rent)
{

}

// returns property rent value. derived class method
float CSquare::getSRent()
{
    return 0;
}

// sets property cost. derived class method
void CSquare::setSCost(float cost)
{

}

// returns property cost. derived class method
float CSquare::getSCost()
{
    return 0;
}

// sets property colour group. derived class method
void CSquare::setSColourGroup(int colourGroup)
{
	
}

// returns property colour group. derived class method
int CSquare::getSColourGroup()
{
    return 0;
}

// sets property or station owners' name. derived class method
void CSquare::setSOwnerName(string ownerName)
{

}

// returns property or station owners' name. derived class method
string CSquare::getSOwnerName()
{
    return " ";
}

// sets go to jail fine. derived class method
void CSquare::setSFine(float fine)
{
    
}

// returns go to jail fine. derived class method
float CSquare::getSFine()
{
    return 0;
}

// sets bonusAmount and bonusName. derived class method
void CSquare::setBonus(int diceValue)
{

}

// returns bonusAmount. derived class method
float CSquare::getBonusAmount()
{
    return  0;
}

// returns bonusName. derived class method
string CSquare::getBonusName()
{
    return " ";
}

// returns bonusAmount. derived class method
void CSquare::setPenalty(int diceValue)
{

}

// returns penaltyName. derived class method
string CSquare::getPenaltyName()
{
    return 0;
}

// returns penaltyAmount. derived class method
float CSquare::getPenaltyAmount()
{
    return 0;
}

// display type and name
void CSquare::display()
{
    cout <<" " << sType << " - " << sName << endl;
}

// derived class display method
void CSquare::displayPayingRentDetails(string playerName)
{
    
}

// display lands square details
void CSquare::displayPlayerLandsOnDetails(unique_ptr<Player>& player)
{
    cout << " Player " << player->getPlayerName() << " lands on " << sName << endl;
}
