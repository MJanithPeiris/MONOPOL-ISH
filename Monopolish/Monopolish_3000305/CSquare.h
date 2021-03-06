#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include <string>
#include "Player.h"
#include <iostream>

using namespace std;

class CSquare {
protected:
    int sType;
    string sName;
public:
    CSquare(); // default constructor
    CSquare(int type, string name); // overloaded constructor
    virtual ~CSquare(); // destructor
    // CSquare class methods
	void setSType(int type);
    int getSType();
    void setSName(string name);
    string getSName();
    // CProperty class methods
    virtual void setSCost(float cost);
    virtual float getSCost();
    virtual void setSRent(float rent);
    virtual float getSRent();
    virtual void setSColourGroup(int colourGroup);
    virtual int getSColourGroup();
    virtual void setSOwnerName(string ownerName);
    virtual string getSOwnerName();
    // CGoToJail class methods
    virtual void setSFine(float fine);
    virtual float getSFine();
    // CBonus class methods
    virtual void setBonus(int diceValue);
    virtual string getBonusName();
    virtual float getBonusAmount();
    // CPenalty class methods
    virtual void setPenalty(int diceValue);
    virtual string getPenaltyName();
    virtual float getPenaltyAmount();
    // display methods
    virtual void display();
    virtual void displayPayingRentDetails(string playerName);
    virtual void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};