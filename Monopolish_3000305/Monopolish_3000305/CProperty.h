#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include "CSquare.h"


class CProperty : public CSquare {
private:
    float sCost;
    float sRent;
    int sColourGroup;
    string propertyOwnerName;
public:
    CProperty();
    CProperty(int type, string name, float cost, float rent, int colourGroup);
    ~CProperty();
    void setSCost(float cost);
    float getSCost();
    void setSRent(float rent);
    float getSRent();
    void setSColourGroup(int colourGroup);
    int getSColourGroup();
    void setSOwnerName(string ownerName);
    string getSOwnerName();
    void display();
    void displayPayingRentDetails(string playerName);
    void displayPlayerLandsOnDetails(unique_ptr<Player>& player);
};