#pragma once
#include <memory>
#include <string>

class FileRead;
using namespace std;

const char pound = 156; // pound symbol

class Player {
private:
    string pName;
    float pMoney;
    int pPosition;
    bool pIsHavingProperty[26]{ false }; // store having properties
    bool pIsBankrupted;
public:
    Player();
    Player(string name, float money, int position);
    ~Player();
    void setPlayerName(string name);
    string getPlayerName();
    void setPlayerPosition(int position);
    int getPlayerPosition();
    void setPlayerMoney(float money);
    float getPlayerMoney();
	void setPlayerHavingProperty(int position, bool isHaving);
    bool getPlayerHavingProperty(int position);
	void setIsBankrupt();
    bool getIsBankrupt();
    void displayCurrentBalance();
    void displayDieRollDetails(int randomNumber);
    void displayPlayerPosition(string propertyName);
    void displayRoundComplete();
    void displayBuyingDetails(unique_ptr<FileRead>& file);
    void displayPayingRentDetails(float propertyRent);
    void displayPropertyMortgageMessage(string propertyName);
    void displayPlayerBankruptMessage();
    void displayWinningMessage();
    void displayWinByHavingMonopoly();
};