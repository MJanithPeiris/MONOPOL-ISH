#pragma once
#include "CSquare.h"


class CProperties : public CSquare {
private:
    float sCost;
    float sRent;
    int sColourGroup;
    string propertyOwnerName;
public:
    CProperties();
    CProperties(int type, string name, float cost, float rent, int colourGroup);
    ~CProperties();
    void setSCost(float cost);
    float getSCost();
    void setSRent(float rent);
    float getSRent();
    void setSColourGroup(int colourGroup);
    int getSColourGroup();
    void setOwnerName(string ownerName);
    string getOwnerName();
    void display();
};