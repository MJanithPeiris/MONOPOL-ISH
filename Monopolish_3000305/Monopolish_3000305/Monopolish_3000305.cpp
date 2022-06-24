// 3000305
// M. Janith Iresha Peiris

#include <iostream>
#include <Windows.h>
#include <string>
#include "Player.h"
#include "ReadFile.h"
#include <memory>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

// function prototyping
void displayWelcome();
void displayThankYou();
void setBoardPosition(unique_ptr<Player>& player1, unique_ptr<Player>& player2, unique_ptr<Player>& player3, unique_ptr<Player>& player4);
void displayBoard(string p1[], string p2[], string p3[], string p4[]);
int random();
void displayGameOver();
int runGameFlow(unique_ptr<FileRead>& file, unique_ptr<Player>& player1, unique_ptr<Player>& player2,
                 unique_ptr<Player>& player3, unique_ptr<Player>& player4, bool* isRentIncreased);
void handleGameScene(unique_ptr<FileRead>& file, unique_ptr<Player>& playerMain, unique_ptr<Player>& subPlayer1,
                       unique_ptr<Player>& subPlayer2, unique_ptr<Player>& subPlayer3, int pDice);
void increaseRent(unique_ptr<FileRead>& file, unique_ptr<Player>& player, bool* isRentIncreased);
void decreaseRent(unique_ptr<FileRead>& file, unique_ptr<Player>& player, bool* isRentIncreased);
bool * checkOwnSameProperties(unique_ptr<FileRead>& file, unique_ptr<Player>& player1);
void sellProperty(unique_ptr<FileRead>& file, unique_ptr<Player>& player, bool* isRentIncreased);
void buyLentProperties(unique_ptr<FileRead>& file, unique_ptr<Player>& player);
int checkBankruptPlayers(bool player1, bool player2, bool player3, bool player4);
void outputFinalResults(unique_ptr<Player>& player1, unique_ptr<Player>& player2,
    unique_ptr<Player>& player3, unique_ptr<Player>& player4);


int main()
{
    // maximize the console to get better view 
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    unique_ptr<FileRead> file = make_unique<FileRead>(); // unique pointer for FileRead
    unique_ptr<Player> player1 = make_unique<Player>("Dog", 1500, 1); // unique pointer for player 1
    unique_ptr<Player> player2 = make_unique<Player>("Car", 1500, 1); // unique pointer for player 2
    unique_ptr<Player> player3 = make_unique<Player>("Shoe", 1500, 1); // unique pointer for player 3
    unique_ptr<Player> player4 = make_unique<Player>("Hat", 1500, 1); // unique pointer for player 4

    
    int seed;
    bool* isRentIncreased = new bool[8]{ false };
    bool threePlayersBankrupted = false;

    cout << endl << "########################################" << endl << endl;

    if (file->readMonopolyTextFile()) // call the read monopoly.txt method. if there is an error in the file opening, then it will give an error message
    {
        cout << " Could not open the file - 'monopoly.txt'" << endl;
    }
    else // if monopoly text file read successfully then display the successful message
    {
        for (auto& i : file->getSquare()) // display the read data from file
        {
            i->display();
        }
        cout << "\n Monopoly.txt is read successfully !!" << endl;
    }

    if (file->readSeedTextFile(seed)) // call the read seed.txt method. if there is an error in the file opening, then it will give an error message
    {
        cout << " Could not open the file - 'seed.txt'" << endl;
    }
    else // if seed text file read successfully then display the successful message
    {
        cout << "\n Seed value is : " << seed << endl;
        cout << " Seed.txt is read successfully !!" << endl;
    }

    cout << endl << "########################################" << endl;
    cout << endl << " Loading Monopolish";
    for (int i = 0; i < 16; ++i)
    {
        Sleep(200); // make a 0.2s delay per loop. altogether 3.2s delay before start the game
        cout << ".";
    }
    system("cls"); // clear the screen before start the game

    // display the welcome to monopoly text
    displayWelcome();
    system("pause");

    // display the monopoly board before start the game
    setBoardPosition(player1, player2, player3, player4);
    system("pause");

    srand(seed); // pass the seed value to srand method

    for (unsigned short i = 0; i < 20; i++) // count the 20 dies rolls for game
    {
        cout << "\t\t\t ---- Round No : " << i + 1 << " ---- " << endl; // display the round number

        // game flow
        int wonPlayer = runGameFlow(file, player1, player2, player3, player4, isRentIncreased);

        if (wonPlayer != 0) // check one player is won
        {
            displayGameOver(); // display game over message
            string playerName;
            cout << " Player ";
            switch (wonPlayer) // get player name according to the wonPlayer
            {
            case 1: playerName = player1->getPlayerName(); break;
            case 2: playerName = player2->getPlayerName(); break;
            case 3: playerName = player3->getPlayerName(); break;
            case 4: playerName = player4->getPlayerName(); break;
            default: break;
            }
            cout << playerName << " has a monopoly and " << playerName << " is declared the winner." << endl;
            threePlayersBankrupted = true; // make 3 players are bankrupted
            break;
        }
        
        Sleep(1000);
        //system("pause");
    }

    // display the winner if other 3 players are not bankrupted
    if (!threePlayersBankrupted) 
    {
        displayGameOver(); // display game over message

        player1->displayCurrentBalance();
        player2->displayCurrentBalance();
        player3->displayCurrentBalance();
        player4->displayCurrentBalance();

        outputFinalResults(player1, player2, player3,player4);
    }
    
       // display the thank you screen
    displayThankYou();

    // delete all the pointers
    Player* p1 = player1.release();
    Player* p2 = player2.release();
    Player* p3 = player3.release();
    Player* p4 = player4.release();
    FileRead* f = file.release();
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete f;
    delete[] isRentIncreased;

    // check memory leaks
    _CrtDumpMemoryLeaks();

    return 0;
}

// display the welcome text
void displayWelcome()
{
    cout << endl << endl;
    cout << "\t\t WW          WW  EEEEEEEEE  LL         CCCCCC     OOOO      MM          MM        TTTTTTTTTTTT     OOOO        " << endl;
    cout << "\t\t WW    WW    WW  EE         LL        CC        OO    OO    MMM        MMM             TT        OO    OO      " << endl;
    cout << "\t\t WW   WWWW   WW  EE         LL       CC        OO      OO   MM MM    MM MM             TT       OO      OO     " << endl;
    cout << "\t\t WW  WW  WW  WW  EEEEEE     LL      CCC       OOO      OOO  MM  MM  MM  MM             TT      OOO      OOO    " << endl;
    cout << "\t\t WW WW    WW WW  EE         LL       CC        OO      OO   MM   MMMM   MM             TT       OO      OO     " << endl;
    cout << "\t\t WWW        WWW  EE         LL        CC        OO    OO    MM    MM    MM             TT        OO    OO      " << endl;
    cout << "\t\t WW          WW  EEEEEEEEE  LLLLLLLLL  CCCCCC     OOOO      MM          MM             TT          OOOO        " << endl << endl;

    cout << " \t  MM          MM      OOOO      NN      NN      OOOO      PPPPPPP        OOOO      LL                IIIIIIIIII    SSSS    HH     HH    " << endl;
    cout << " \t  MMM        MMM    OO    OO    NNNN    NN    OO    OO    PP    PP     OO    OO    LL                    II      SS    SS  HH     HH    " << endl;
    cout << " \t  MM MM    MM MM   OO      OO   NN NN   NN   OO      OO   PP    PP    OO      OO   LL                    II      SS        HH     HH    " << endl;
    cout << " \t  MM  MM  MM  MM  OOO      OOO  NN  NN  NN  OOO      OOO  PPPPPPP    OOO      OOO  LL        |||||||     II        SSSS    HHHHHHHHH    " << endl;
    cout << " \t  MM   MMMM   MM   OO      OO   NN   NN NN   OO      OO   PP          OO      OO   LL                    II            SS  HH     HH    " << endl;
    cout << " \t  MM    MM    MM    OO    OO    NN    NNNN    OO    OO    PP           OO    OO    LL                    II      SS    SS  HH     HH    " << endl;
    cout << " \t  MM          MM      OOOO      NN      NN      OOOO      PP             OOOO      LLLLLLLLL         IIIIIIIIII    SSSSS   HH     HH    " << endl << endl;
}

// display the thank you text
void displayThankYou()
{
    cout << endl << endl << endl;
    cout << "\t\t TTTTTTTTTTTT  HH       HH        AA        NN      NN  KK     KK        YY        YY      OOOO      UU         UU   " << endl;
    cout << "\t\t      TT       HH       HH       A  A       NNNN    NN  KK   KK           YY      YY     OO    OO    UU         UU   " << endl;
    cout << "\t\t      TT       HH       HH      A    A      NN NN   NN  KK KK              YY    YY     OO      OO   UU         UU   " << endl;
    cout << "\t\t      TT       HHHHHHHHHHH     AAAAAAAA     NN  NN  NN  KKK                 YYYYYY     OOO      OOO  UU         UU   " << endl;
    cout << "\t\t      TT       HH       HH    AA      AA    NN   NN NN  KK KK                 YY        OO      OO    UU       UU    " << endl;
    cout << "\t\t      TT       HH       HH   AA        AA   NN    NNNN  KK   KK               YY         OO    OO      UU     UU     " << endl;
    cout << "\t\t      TT       HH       HH  AA          AA  NN      NN  KK     KK             YY           OOOO          UUUUU       " << endl << endl;

    cout << "\t   FFFFFFFFF     OOOO      RRRRRRR          PPPPPPP   LL               AA       YY        YY  IIIIIIIIII   NN      NN     GGGGGGGG       " << endl;
    cout << "\t   FF          OO    OO    RR     RR        PP    PP  LL              A  A       YY      YY       II       NNNN    NN    GG      GG      " << endl;
    cout << "\t   FF         OO      OO   RR     RR        PP    PP  LL             A    A       YY    YY        II       NN NN   NN   GG               " << endl;
    cout << "\t   FFFFF     OOO      OOO  RRRRRRR          PPPPPPP   LL            AAAAAAAA       YYYYYY         II       NN  NN  NN  GGG     GGGGGG    " << endl;
    cout << "\t   FF         OO      OO   RR RR            PP        LL           AA      AA        YY           II       NN   NN NN   GG      GG GG    " << endl;
    cout << "\t   FF          OO    OO    RR   RR          PP        LL          AA        AA       YY           II       NN    NNNN    GG    GG  GG    " << endl;
    cout << "\t   FF            OOOO      RR     RR        PP        LLLLLLLLL  AA          AA      YY       IIIIIIIIII   NN      NN      GGGGG   GG    " << endl << endl << endl;

    cout << "\t\t\t\t\t\t\t ---- Created by Janith Iresha Peiris ----" << endl;
    cout << "\t\t\t\t\t\t     ---- UClan ID : G20924165 / UCL ID : 3000305 ----" << endl;
}

// set the player board position according to actual player position 
void setBoardPosition(unique_ptr<Player>& player1, unique_ptr<Player>& player2, unique_ptr<Player>& player3, unique_ptr<Player>& player4)
{
    string player1Pos[26];
    string player2Pos[26];
    string player3Pos[26];
    string player4Pos[26];

    for (int i = 0; i < 26; ++i) // assign all to 4 spaces 
    {
        player1Pos[i] = "    ";
        player2Pos[i] = "    ";
        player3Pos[i] = "    ";
        player4Pos[i] = "    ";
    }

    // assign player name to corresponding player position
    player1Pos[player1->getPlayerPosition() - 1] = " " + player1->getPlayerName();
    player2Pos[player2->getPlayerPosition() - 1] = " " + player2->getPlayerName();
    player3Pos[player3->getPlayerPosition() - 1] = player3->getPlayerName();
    player4Pos[player4->getPlayerPosition() - 1] = " " + player4->getPlayerName();

    // display the monopoly board
    displayBoard(player1Pos, player2Pos, player3Pos, player4Pos);
}

// display the monopoly board
void displayBoard(string p1[], string p2[], string p3[], string p4[])
{
    cout << endl;
    cout << "                       Brown      Brown                 Orange     Orange     Orange                         " << endl;
    cout << "                       Road       Street    Station      Road      Street      Way                           " << endl;
    cout << "          _______________________________________________________________________________________            " << endl;
    cout << "         | " << p1[6] << "     | " << p1[7] << "     | " << p1[8] << "     | " << p1[9] << "     | " << p1[10] << "     | " << p1[11] << "     | " << p1[12] << "     | " << p1[13] << "     |          " << endl;
    cout << "         |     " << p2[6] << " |     " << p2[7] << " |     " << p2[8] << " |     " << p2[9] << " |     " << p2[10] << " |     " << p2[11] << " |     " << p2[12] << " |     " << p2[13] << " | Free     " << endl;
    cout << "    JAIL | " << p3[6] << "     | " << p3[7] << "     | " << p3[8] << "     | " << p3[9] << "     | " << p3[10] << "     | " << p3[11] << "     | " << p3[12] << "     | " << p3[13] << "     | Parking  " << endl;
    cout << "         |     " << p4[6] << " |     " << p4[7] << " |     " << p4[8] << " |     " << p4[9] << " |     " << p4[10] << " |     " << p4[11] << " |     " << p4[12] << " |     " << p4[13] << " |          " << endl;
    cout << "         |__________|__________|__________|__________|__________|__________|__________|__________|                                 " << endl;
    cout << "         | " << p1[5] << "     |                                                                 | " << p1[14] << "     |          " << endl;
    cout << "    Grey |     " << p2[5] << " |                                                                 |     " << p2[14] << " | Yellow   " << endl;
    cout << "  Street | " << p3[5] << "     |                                                                 | " << p3[14] << "     | Road     " << endl;
    cout << "         |     " << p4[5] << " |                                                                 |     " << p4[14] << " |          " << endl;
    cout << "         |__________|                                                                 |__________|                                 " << endl;
    cout << "         | " << p1[4] << "     |                                                                 | " << p1[15] << "     |          " << endl;
    cout << "    Grey |     " << p2[4] << " |                                                                 |     " << p2[15] << " | Yellow   " << endl;
    cout << "    Road | " << p3[4] << "     |                                                                 | " << p3[15] << "     | Street   " << endl;
    cout << "         |     " << p4[4] << " |                                                                 |     " << p4[15] << " |          " << endl;
    cout << "         |__________|                                                                 |__________|                                 " << endl;
    cout << "         | " << p1[3] << "     |                                                                 | " << p1[16] << "     |          " << endl;
    cout << "         |     " << p2[3] << " |                                                                 |     " << p2[16] << " | Penalty  " << endl;
    cout << "   Bonus | " << p3[3] << "     |                           Monopolish                            | " << p3[16] << "     |          " << endl;
    cout << "         |     " << p4[3] << " |                                                                 |     " << p4[16] << " |          " << endl;
    cout << "         |__________|                                                                 |__________|                                 " << endl;
    cout << "         | " << p1[2] << "     |                                                                 | " << p1[17] << "     |          " << endl;
    cout << "     Red |     " << p2[2] << " |                                                                 |     " << p2[17] << " | Green    " << endl;
    cout << "  Street | " << p3[2] << "     |                                                                 | " << p3[17] << "     | Road     " << endl;
    cout << "         |     " << p4[2] << " |                                                                 |     " << p4[17] << " |          " << endl;
    cout << "         |__________|                                                                 |__________|                                 " << endl;
    cout << "         | " << p1[1] << "     |                                                                 | " << p1[18] << "     |          " << endl;
    cout << "     Red |     " << p2[1] << " |                                                                 |     " << p2[18] << " | Green    " << endl;
    cout << "    Road | " << p3[1] << "     |                                                                 | " << p3[18] << "     | Street   " << endl;
    cout << "         |     " << p4[1] << " |                                                                 |     " << p4[18] << " |          " << endl;
    cout << "         |__________|_________________________________________________________________|__________|                                 " << endl;
    cout << "         | " << p1[0] << "     | " << p1[25] << "     | " << p1[24] << "     | " << p1[23] << "     | " << p1[22] << "     | " << p1[21] << "     | " << p1[20] << "     | " << p1[19] << "     |        " << endl;
    cout << "         |     " << p2[0] << " |     " << p2[25] << " |     " << p2[14] << " |     " << p2[23] << " |     " << p2[22] << " |     " << p2[21] << " |     " << p2[20] << " |     " << p2[19] << " | GO TO  " << endl;
    cout << "      GO | " << p3[0] << "     | " << p3[25] << "     | " << p3[24] << "     | " << p3[23] << "     | " << p3[22] << "     | " << p3[21] << "     | " << p3[20] << "     | " << p3[19] << "     | Jail   " << endl;
    cout << "         |     " << p4[0] << " |     " << p4[25] << " |     " << p4[14] << " |     " << p4[23] << " |     " << p4[22] << " |     " << p4[21] << " |     " << p4[20] << " |     " << p4[19] << " |        " << endl;
    cout << "         |__________|__________|__________|__________|__________|__________|__________|__________|           " << endl;
    cout << "                       Purple     Purple    Station      Blue       Blue       Blue                          " << endl;
    cout << "                        Road       Road                  Road      Street      Way                           " << endl << endl;
}

// generate the random number for die
int random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

// display game over text
void displayGameOver()
{
    cout << endl << endl << endl;
    cout << "\t\t     GGGGGGGG           AA        MM          MM  EEEEEEEEE           OOOO     VV          VV  EEEEEEEEE  RRRRRRR        !!    " << endl;
    cout << "\t\t    GG      GG         A  A       MMM        MMM  EE                OO    OO    VV        VV   EE         RR     RR     !!!!   " << endl;
    cout << "\t\t   GG                 A    A      MM MM    MM MM  EE               OO      OO    VV      VV    EE         RR     RR     !!!!   " << endl;
    cout << "\t\t  GGG     GGGGGG     AAAAAAAA     MM  MM  MM  MM  EEEEEE          OOO      OOO    VV    VV     EEEEEE     RRRRRRR        !!    " << endl;
    cout << "\t\t   GG      GG GG    AA      AA    MM   MMMM   MM  EE               OO      OO      VV  VV      EE         RR RR          !!    " << endl;
    cout << "\t\t    GG    GG  GG   AA        AA   MM    MM    MM  EE                OO    OO        VVVV       EE         RR   RR             " << endl;
    cout << "\t\t      GGGGG   GG  AA          AA  MM          MM  EEEEEEEEE           OOOO           VV        EEEEEEEEE  RR     RR      !!    " << endl << endl;
}

// game flow
int runGameFlow(unique_ptr<FileRead>& file, unique_ptr<Player>& player1, unique_ptr<Player>& player2,
                 unique_ptr<Player>& player3, unique_ptr<Player>& player4, bool* isRentIncreased)
{
    int pDice;

    if (!player1->getIsBankrupt()) // check if the player is bankrupted
    {
        pDice = random(); // get a random number for die roll
        // 
        handleGameScene(file, player1, player2, player3, player4, pDice);
        // if player has owned all properties of the same colour then double the rent of those properties
        cout << endl;
        increaseRent(file, player1, isRentIncreased);
    }
    cout << endl;
    if (!player2->getIsBankrupt())
    {
        pDice = random();
        handleGameScene(file, player2, player1, player3, player4, pDice);
        // if player has owned all properties of the same colour then double the rent of those properties
        cout << endl;
        increaseRent(file, player2, isRentIncreased);
    }
    cout << endl;
    if (!player3->getIsBankrupt())
    {
        pDice = random();
        handleGameScene(file, player3, player2, player1, player4, pDice);
        // if player has owned all properties of the same colour then double the rent of those properties
        cout << endl;
        increaseRent(file, player3, isRentIncreased);
    }
    cout << endl;
    if (!player4->getIsBankrupt())
    {
        pDice = random();
        handleGameScene(file, player4, player2, player3, player1, pDice);
        // if player has owned all properties of the same colour then double the rent of those properties
        cout << endl;
        increaseRent(file, player4, isRentIncreased);
    }
    cout << endl;

    setBoardPosition(player1, player2, player3, player4); // display player position on the board

    if (player1->getPlayerMoney() <= 0) // if player money is lower than or equal to 0 then sell the lowest valued property
        sellProperty(file, player1, isRentIncreased);
    else // if player money is greater that 0 then buy the sold properties
        buyLentProperties(file, player1);

    if (player2->getPlayerMoney() <= 0)
        sellProperty(file, player2, isRentIncreased);
    else
        buyLentProperties(file, player2);

    if (player3->getPlayerMoney() <= 0)
        sellProperty(file, player3, isRentIncreased);
    else
        buyLentProperties(file, player3);

    if (player4->getPlayerMoney() <= 0)
        sellProperty(file, player4, isRentIncreased);
    else
        buyLentProperties(file, player4);
    
    // check which player won the game due to bankruptcy of other players
    int wonPlayer = checkBankruptPlayers(player1->getIsBankrupt(), player2->getIsBankrupt(), player3->getIsBankrupt(),
                                         player4->getIsBankrupt());

    // display the current balance of the players
    player1->displayCurrentBalance();
    player2->displayCurrentBalance();
    player3->displayCurrentBalance();
    player4->displayCurrentBalance();

    if (wonPlayer != 0) // check one player is won
    {
        return wonPlayer;
    }
    
    cout << endl;
    return 0;
}

// when player lands on a square, do the calculations according to the square ruls
void handleGameScene(unique_ptr<FileRead>& file, unique_ptr<Player>& playerMain, unique_ptr<Player>& subPlayer1,
                       unique_ptr<Player>& subPlayer2, unique_ptr<Player>& subPlayer3, int pDice)
{
	playerMain->displayDiceRollDetails(pDice); // display player name & dice value
    playerMain->setPlayerPosition(playerMain->getPlayerPosition() + pDice); // set player position according to the dice value
    
    if (playerMain->getPlayerPosition() > 26) // check player position exceed the square count
    {
        playerMain->setPlayerPosition(playerMain->getPlayerPosition() - 26); // if exceed deduct 26 (square count) from the position
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() + 200); // player collects £200
        playerMain->displayRoundComplete(); // display round complete message
    }
    playerMain->displayPlayerPosition(file); // display player lands on details
    int mainPlayerPosition = playerMain->getPlayerPosition(); // get player position
    
    switch (file->getSquare()[mainPlayerPosition - 1]->getSType()) // check the square type
    {
        int secondDieValue;
    case 1: // property
      //  cout << " Came to 1 " << endl;//

      // check main player doesn't own a particular property and  another player owns it. if it is true then main player will pay the rent
        if (!playerMain->getPlayerHavingProperty(mainPlayerPosition - 1) && (subPlayer1->getPlayerHavingProperty(mainPlayerPosition - 1) ||
            subPlayer2->getPlayerHavingProperty(mainPlayerPosition - 1) || subPlayer3->getPlayerHavingProperty(mainPlayerPosition - 1)))
        {
            // deduct the property rent from main player money 
            playerMain->setPlayerMoney(playerMain->getPlayerMoney() - file->getSquare()[mainPlayerPosition - 1]->getSRent());

            // check which player owns that property and add the rent to players' money
            if (subPlayer1->getPlayerHavingProperty(mainPlayerPosition - 1))
                subPlayer1->setPlayerMoney(subPlayer1->getPlayerMoney() + file->getSquare()[mainPlayerPosition - 1]->getSRent());

            if (subPlayer2->getPlayerHavingProperty(mainPlayerPosition - 1))
                subPlayer2->setPlayerMoney(subPlayer2->getPlayerMoney() + file->getSquare()[mainPlayerPosition - 1]->getSRent());

            if (subPlayer3->getPlayerHavingProperty(mainPlayerPosition - 1))
                subPlayer3->setPlayerMoney(subPlayer3->getPlayerMoney() + file->getSquare()[mainPlayerPosition - 1]->getSRent());

            playerMain->displayPayingRentDetails(file); // display pay property rent details
        }

        // check any player doesn't own the property. if it is true main player will buy that property
        if (!playerMain->getPlayerOwnedProperty(mainPlayerPosition - 1) && (!subPlayer1->getPlayerOwnedProperty(mainPlayerPosition - 1) &&
            !subPlayer2->getPlayerOwnedProperty(mainPlayerPosition - 1) && !subPlayer3->getPlayerOwnedProperty(mainPlayerPosition - 1)))
        {
            // if (playerMain->getPlayerMoney() > file->getSquare()[playerPosition - 1]->getSCost()) {
          //      cout << " Player money : " << playerMain->getPlayerMoney() << endl; //

            // set property ownership to main player
            playerMain->setPlayerOwnedProperty(mainPlayerPosition - 1, true);
            playerMain->setPlayerHavingProperty(mainPlayerPosition - 1, true);

            // deduct the property cost from player money
            playerMain->setPlayerMoney(playerMain->getPlayerMoney() - file->getSquare()[mainPlayerPosition - 1]->getSCost());
            playerMain->displayBuyingDetails(file); // display property buying details


            //     cout << " Updated Player money : " << playerMain->getPlayerMoney() << endl; //
            // }

         //    cout << " Square buy : " << playerMain->getPlayerOwnedProperty(playerPosition - 1) << endl; //
         //    cout << " Square h buy : " << playerMain->getPlayerHavingProperty(playerPosition - 1) << endl; //



            //      cout << " Square buy : " << playerMain->getPlayerOwnedProperty(playerPosition - 1) << endl; //
             //     cout << " Square h buy : " << playerMain->getPlayerHavingProperty(playerPosition - 1) << endl; //
        }
        break;

    case 3: // Railway station, Bus station
       // cout << " Came to a station " << endl;//

      // check main player doesn't own a particular station and  another player owns it. if it is true then main player will pay the rent
        if (!playerMain->getPlayerHavingProperty(mainPlayerPosition - 1) && (subPlayer1->getPlayerHavingProperty(mainPlayerPosition - 1) ||
            subPlayer2->getPlayerHavingProperty(mainPlayerPosition - 1) || subPlayer3->getPlayerHavingProperty(mainPlayerPosition - 1)))
        {
            // deduct the station rent from main player money 
            playerMain->setPlayerMoney(playerMain->getPlayerMoney() - file->getSquare()[mainPlayerPosition - 1]->getStRent());

            // check which player owns that station and add the rent to players' money
            if (subPlayer1->getPlayerOwnedProperty(mainPlayerPosition - 1))
                subPlayer1->setPlayerMoney(subPlayer1->getPlayerMoney() + file->getSquare()[mainPlayerPosition - 1]->getStRent());

            if (subPlayer2->getPlayerOwnedProperty(mainPlayerPosition - 1))
                subPlayer2->setPlayerMoney(subPlayer2->getPlayerMoney() + file->getSquare()[mainPlayerPosition - 1]->getStRent());

            if (subPlayer3->getPlayerOwnedProperty(mainPlayerPosition - 1))
                subPlayer3->setPlayerMoney(subPlayer3->getPlayerMoney() + file->getSquare()[mainPlayerPosition - 1]->getStRent());

            file->getSquare()[mainPlayerPosition - 1]->display(playerMain->getPlayerName()); // display pay station rent details
        }

        // check any player doesn't own the station. if it is true main player will buy that property
        if (!playerMain->getPlayerOwnedProperty(mainPlayerPosition - 1) && (!subPlayer1->getPlayerOwnedProperty(mainPlayerPosition - 1) &&
            !subPlayer2->getPlayerOwnedProperty(mainPlayerPosition - 1) && !subPlayer3->getPlayerOwnedProperty(mainPlayerPosition - 1)))
        {
            //   cout << " Square cost : " << file->getSquare()[playerPosition - 1]->getSCost() << endl; //
              // if (playerMain->getPlayerMoney() > file->getSquare()[playerPosition - 1]->getSCost()) {
           //        cout << " Player money : " << playerMain->getPlayerMoney() << endl; //

             // set property ownership to main player
            playerMain->setPlayerOwnedProperty(mainPlayerPosition - 1, true);
            playerMain->setPlayerHavingProperty(mainPlayerPosition - 1, true);

            // deduct the property cost from player money
            playerMain->setPlayerMoney(playerMain->getPlayerMoney() - file->getSquare()[mainPlayerPosition - 1]->getStCost());
            playerMain->displayBuyingDetails(file);  // display station buying details

            //          cout << " Updated Player money : " << playerMain->getPlayerMoney() << endl; //
                 // }
             //     cout << " Square buy : " << playerMain->getPlayerOwnedProperty(playerPosition - 1) << endl; //
             //     cout << " Square h buy : " << playerMain->getPlayerHavingProperty(playerPosition - 1) << endl; //

            //     cout << " Square buy : " << playerMain->getPlayerOwnedProperty(playerPosition - 1) << endl; //
           //      cout << " Square h buy : " << playerMain->getPlayerHavingProperty(playerPosition - 1) << endl; //
        }
        break;

    case 4: // bonus
       // cout << " Came to Bonus \n Roll the die again to claim the bonus " << endl;//
        secondDieValue = random(); // get a random number to claim the bonus
        //  playerMain->displayDiceRollDetails(secondDieValue);//

        file->getSquare()[3]->setBonus(secondDieValue); // set the bonus name and value
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() + file->getSquare()[3]->getBonusAmount()); // add the bonus amount to player money
        file->getSquare()[3]->display(playerMain->getPlayerName(), playerMain->getPlayerMoney()); // display the claimed bonus details
        break;

    case 5: // penalty
      //  cout << " Came to penalty \n Roll the die again to claim the penalty " << endl;//
        secondDieValue = random(); // get a random number to claim the penalty
        //   playerMain->displayDiceRollDetails(secondDieValue);//

        file->getSquare()[mainPlayerPosition - 1]->setPenalty(secondDieValue);// set the penalty name and value
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() - file->getSquare()[mainPlayerPosition - 1]->getPenaltyAmount());// deduct the penalty amount to player money
        file->getSquare()[mainPlayerPosition - 1]->display(playerMain->getPlayerName(), playerMain->getPlayerMoney()); // display the claimed penalty details
        break;

    case 6: // jail
       // cout << " Came to jail " << endl;//
        file->getSquare()[mainPlayerPosition - 1]->display(playerMain->getPlayerName()); // display message according to jail
        break;

    case 7: // go to jail
       // cout << " Came to go to jail " << endl;//

        file->getSquare()[mainPlayerPosition - 1]->display(playerMain->getPlayerName()); // display message according to go to jail
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() - file->getSquare()[mainPlayerPosition - 1]->getSFine()); // deduct jail fine (£50) from players' money
        playerMain->setPlayerPosition(7); // change player position to jail
        break;

    case 8: // free parking
      //  cout << " Came to free parking " << endl;//
        file->getSquare()[mainPlayerPosition - 1]->display(playerMain->getPlayerName()); // display message according to free parking
        break;

    default:// cout << " You are in Starting point " << endl; 
        break;
    }
}

// increase the property rent after player buys all the properties of same colour code
void increaseRent(unique_ptr<FileRead>& file, unique_ptr<Player>& player, bool* isRentIncreased)
{
     bool* isAllPropertyOwn = checkOwnSameProperties(file, player); // check all the properties related to same colour group is owned by same player
     /*cout << endl << " Increase Function " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << isAllPropertyOwn[i] << " - ";
    }
    cout << endl << endl;*/

    for(int propertyIndex = 0 ; propertyIndex < 8 ; propertyIndex++)
    {
	    for (int squareIndex = 0; squareIndex < file->getSquare().size(); ++squareIndex)
	    {
            //check previously rent was increased and all properties owned by same player and square type is 1 and colour group is equal to propertyIndex
            if (!isRentIncreased[propertyIndex] && isAllPropertyOwn[propertyIndex] && file->getSquare()[squareIndex]->getSType() == 1 &&
	            file->getSquare()[squareIndex]->getSColourGroup() == propertyIndex)
            {
                cout <<" Property Name : " << file->getSquare()[squareIndex]->getSName() << " rent is increased " << pound << file->getSquare()[squareIndex]->getSRent();
                file->getSquare()[squareIndex]->setSRent(file->getSquare()[squareIndex]->getSRent()*2); // double the property rent
                cout << " to " << pound << file->getSquare()[squareIndex]->getSRent() << endl;
            }
	    }
        if(isAllPropertyOwn[propertyIndex]) // check all the properties of same colour group is owned by same player
        {
            isRentIncreased[propertyIndex] = true; // make that property rent increased is true
        }
    }

	/*for (int i = 0; i < 8; ++i)
	{
        cout << isRentIncreased[i] << " - ";
	}
    cout << endl << endl;*/
}

// decrease the property rent after player sells one property of same colour code after buying all properties of same colour
void decreaseRent(unique_ptr<FileRead>& file, unique_ptr<Player>& player, bool* isRentIncreased)
{
    bool* isAllPropertyOwn = checkOwnSameProperties(file, player); // check all the properties related to same colour group is owned by same player

    //cout << endl << " Decrease Function " << endl;
    /*for (int i = 0; i < 8; i++)
    {
        cout << isAllPropertyOwn[i] << " - ";
    }
    cout << endl << endl;*/

    for (int propertyIndex = 0; propertyIndex < 8; propertyIndex++)
    {
        for (int squareIndex = 0; squareIndex < file->getSquare().size(); ++squareIndex)
        {
            //check previously rent was not increased and all properties didn't own by same player and square type is 1 and colour group is equal to propertyIndex 
            if (isRentIncreased[propertyIndex] && !isAllPropertyOwn[propertyIndex] && file->getSquare()[squareIndex]->getSType() == 1 &&
                file->getSquare()[squareIndex]->getSColourGroup() == propertyIndex)
            {
                cout << " Property Name : " << file->getSquare()[squareIndex]->getSName() << " rent is decreased " << pound << file->getSquare()[squareIndex]->getSRent();
                file->getSquare()[squareIndex]->setSRent(file->getSquare()[squareIndex]->getSRent() / 2);
                cout << " to " << pound << file->getSquare()[squareIndex]->getSRent() << endl;
            }
        }
        if (!isAllPropertyOwn[propertyIndex]) // check all the properties of same colour group is not owned by same player
        {
            isRentIncreased[propertyIndex] = false; // make that property rent increased is false
        }
    }
    /*for (int i = 0; i < 8; ++i)
    {
        cout << isRentIncreased[i] << " - ";
    }
    cout << endl << endl;*/
}

// check all the properties related to same colour group is owned by same player
bool * checkOwnSameProperties(unique_ptr<FileRead>& file, unique_ptr<Player>& player)
{
    static bool isPropertyOwned[8]{ false };
    /*bool* playerProp;
    if (m == 1)
    {
        playerProp = new bool [26]  { 0,1,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1 };
    }
    else
    {
        playerProp = new bool[26]{ 0,1,1,0,1,0,0,1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1 };
    }*/

    /*for (int i = 0; i < 8; i++)
    {
        cout << propertyOwn[i] << " - ";
    }
    cout << endl;*/

    for (int propertyColourIndex = 0; propertyColourIndex < 8; propertyColourIndex++)
    {
        bool isOwned = false;
        for (int squareIndex = 0; squareIndex < file->getSquare().size(); squareIndex++)
        {
            // check square type is equal to 1 and property colour group is equal to propertyColourGroup to get all same colour group properties 
            if (file->getSquare()[squareIndex]->getSType() == 1 && file->getSquare()[squareIndex]->getSColourGroup() == propertyColourIndex)
            {
                if (player->getPlayerHavingProperty(squareIndex)) // check player owns that property each property of same colour group
                {
                    isOwned = true;
                }
                else // if player doesn't own any property of same colour group
                {
                    isOwned = false;
                	break;
                }
            }
        }
        isPropertyOwned[propertyColourIndex] = isOwned; // store the status of each colour group
    }
    
    /*for(int i = 0; i < 8 ; i++)
    {
        cout << propertyOwn[i] << " - ";
    }
    cout << endl << endl;*/
    return isPropertyOwned;
}

// after player gets lower amount than 0 then player will sell their properties
void sellProperty(unique_ptr<FileRead>& file, unique_ptr<Player>& player, bool* isRentIncreased)
{
    while(player->getPlayerMoney() <= 0) // continue until player gets positive amount of money
    {
        for(int i = 0; i < 26 ; i++)
        {
	        if(player->getPlayerHavingProperty(i)) // check players' own properties
	        {
                player->setPlayerMoney(player->getPlayerMoney() + file->getSquare()[i]->getSCost()); // add property cost to players' money
                player->setPlayerHavingProperty(i,false); // mortgage the property
                break;// after selling one property check player has positive amount of money
	        }
            if(i == 25) // check player has no property
            {
                player->setIsBankrupt(true); // change that player as bankrupt player
                player->displayPlayerBankruptMessage(); // display player bankrupt message
            }
        }

        // if player has sold one property that player owned all properties of the same colour then reduce the rent of those properties
        decreaseRent(file, player, isRentIncreased);

        /*cout << " Player money : " << player->getPlayerMoney() << endl;
        cout << endl;

        for (int i = 0; i < 26; i++)
        {
            cout << player->getPlayerOwnedProperty(i) << " - ";
        }
        cout << endl;*/
    }
}

// player buys lent properties
void buyLentProperties(unique_ptr<FileRead>& file, unique_ptr<Player>& player)
{
    for(int i = 0; i<26; i++)
    {
        // check player owned that property previously and not having it now and buying cost will not cause negative amount of money and player is not bankrupted
        if (player->getPlayerOwnedProperty(i) && !player->getPlayerHavingProperty(i) && (player->getPlayerMoney() - file
	        ->getSquare()[i]->getSCost()) > 0 && !player->getIsBankrupt())
        {
            player->setPlayerHavingProperty(i,true); // buy that property again to player
            player->setPlayerMoney(player->getPlayerMoney() - file->getSquare()[i]->getSCost()); // deduct the property cost from players' money
        }
    }
}

// check whether which player will win when the other 3 players are bankrupted
int checkBankruptPlayers(bool player1, bool player2, bool player3, bool player4)
{
    if (!player1 && player2 && player3 && player4) // check whether the player 1 will win
        return 1;
    if (player1 && !player2 && player3 && player4) // check whether the player 2 will win
        return 2;
    if (player1 && player2 && !player3 && player4) // check whether the player 3 will win
        return 3;
    if (player1 && player2 && player3 && !player4) // check whether the player 4 will win
        return 4;

    return 0;
}

// display the winner
void outputFinalResults(unique_ptr<Player>& player1, unique_ptr<Player>& player2,
    unique_ptr<Player>& player3, unique_ptr<Player>& player4)
{
    if (player1->getPlayerMoney() > player2->getPlayerMoney()) // check player1 money is grater than player2 money
    {
        if (player1->getPlayerMoney() > player3->getPlayerMoney()) { // check player1 money is grater than player3 money
            if (player1->getPlayerMoney() > player4->getPlayerMoney())// check player1 money is grater than player4 money
                player1->displayWinningMessage();
            else
                player4->displayWinningMessage();
        }
        else
        {
            if (player3->getPlayerMoney() > player4->getPlayerMoney()) // check player3 money is grater than player4 money
                player3->displayWinningMessage();
            else
                player4->displayWinningMessage();
        }
    }
    else
    {
        if (player2->getPlayerMoney() > player3->getPlayerMoney()) // check player2 money is grater than player3 money
        {
            if (player2->getPlayerMoney() > player4->getPlayerMoney()) // check player2 money is grater than player4 money
                player2->displayWinningMessage();
            else
                player4->displayWinningMessage();
        }
        else
        {
            if (player3->getPlayerMoney() > player4->getPlayerMoney()) // check player3 money is grater than player4 money
                player3->displayWinningMessage();
            else
                player4->displayWinningMessage();
        }
    }
}
