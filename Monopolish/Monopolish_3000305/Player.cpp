#include "Player.h"
#include <iostream>
#include <string>
#include "ReadFile.h"

using  namespace std;

// default constructor
Player::Player(){}

// overloaded constructor
Player::Player(string name, float money, int position)
{
    pName = name;
    pMoney = money;
    pPosition = position;
    pIsBankrupted = false;
}

// destructor
Player::~Player(){}

// sets player name
void Player::setPlayerName(string name)
{
    pName = name;
}

// returns player name
string Player::getPlayerName()
{
    return pName;
}

// sets player money
void Player::setPlayerMoney(float money)
{
    pMoney = money;
}

// returns player money
float Player::getPlayerMoney()
{
    return pMoney;
}

// sets player position
void Player::setPlayerPosition(int position)
{
    pPosition = position;
}

// returns player position
int Player::getPlayerPosition()
{
    return pPosition;
}

// sets player having properties
void Player::setPlayerHavingProperty(int position, bool isHaving)
{
    pIsHavingProperty[position] = isHaving;
}

// returns player having properties
bool Player::getPlayerHavingProperty(int position)
{
    return pIsHavingProperty[position];
}

// sets player is bankrupted or not
void Player::setIsBankrupt()
{
    pIsBankrupted = true;
}

// returns player is bankrupted or not
bool Player::getIsBankrupt()
{
    return pIsBankrupted;
}

// display players' current money
void Player::displayCurrentBalance()
{
    cout << " " << pName << " has " << pound <<pMoney << endl;
}

// display players' dice roll details
void Player::displayDieRollDetails(int randomNumber)
{
    cout << " Player : " << pName << " rolls " << randomNumber << endl;
}

// display players' position
void Player::displayPlayerPosition(string propertyName)
{
    cout << " Player " << pName << " lands on " << propertyName << endl;
}

// display player completes a round message
void Player::displayRoundComplete()
{
    cout << " " << pName << " passes GO and collects " << pound << "200 " << endl;
}

// display player paying rent details
void Player::displayPayingRentDetails(float propertyRent)
{
    cout << " " << pName << " pays " << propertyRent << endl;
}

// display player buying property details
void Player::displayBuyingDetails(unique_ptr<FileRead>& file)
{
    cout <<" " << pName << " buys " << file->getSquare()[pPosition - 1]->getSName() << " for " << pound << file->getSquare()[pPosition - 1]->getSCost() << endl;
}

// display player mortgage the property details
void Player::displayPropertyMortgageMessage(string propertyName)
{
    cout << " " << pName << " mortgage the " << propertyName << endl;
}

// display player is bankrupted message
void Player::displayPlayerBankruptMessage()
{
    cout << " Player : " << pName << " is Bankrupted and Lost the game!!" << endl;
}

// display player wins message
void Player::displayWinningMessage()
{
    cout << "\n " << pName << " wins!!" << endl;
}

// display winning message when a player win by bankrupting other 3 players
void Player::displayWinByHavingMonopoly()
{
    cout << "\n " << pName << " has a monopoly and " << pName << " is declared the winner.";
    displayWinningMessage();
}