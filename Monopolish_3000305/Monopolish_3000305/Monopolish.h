// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#pragma once
#include <string>
#include <memory>
#include "Player.h"
#include "GameCreator.h"

// function prototyping
void displayWelcome();
void displayThankYou();
void displayGameOver();
void displayRoundComplete(string playerName);
void setBoardPosition(unique_ptr<Player>& player1, unique_ptr<Player>& player2, unique_ptr<Player>& player3,
    unique_ptr<Player>& player4);
void displayBoard(string p1[], string p2[], string p3[], string p4[]);
int random();
int runGameFlow(c_square& squares, unique_ptr<Player>& player1, unique_ptr<Player>& player2,
    unique_ptr<Player>& player3, unique_ptr<Player>& player4, unique_ptr<bool> isRentIncreased[]);
void handleGameFlow(c_square& squares, unique_ptr<Player>& playerMain, unique_ptr<Player>& subPlayer1,
    unique_ptr<Player>& subPlayer2, unique_ptr<Player>& subPlayer3, int pDie);
void payRent(c_square& squares, unique_ptr<Player>& playerMain, unique_ptr<Player>& subPlayer1,
    unique_ptr<Player>& subPlayer2, unique_ptr<Player>& subPlayer3, int mainPlayerPosition);
void buyProperty(c_square& squares, unique_ptr<Player>& playerMain, int mainPlayerPosition);
void increaseRent(c_square& squares, unique_ptr<Player>& player, unique_ptr<bool> isRentIncreased[]);
void decreaseRent(c_square& squares, unique_ptr<Player>& player, unique_ptr<bool> isRentIncreased[]);
bool* checkOwnSameProperties(c_square& squares, unique_ptr<Player>& player1);
void mortgageProperty(c_square& squares, unique_ptr<Player>& player, unique_ptr<bool> isRentIncreased[]);
void buyMortgageProperties(c_square& squares, unique_ptr<Player>& player);
int findMinimumValueProperty(c_square& squares, unique_ptr<Player>& player, bool isSelling);
int checkWinningPlayerWithoutBankrupt(bool player1, bool player2, bool player3, bool player4);
void outputFinalWinningPlayer(unique_ptr<Player>& player1, unique_ptr<Player>& player2,
    unique_ptr<Player>& player3, unique_ptr<Player>& player4);