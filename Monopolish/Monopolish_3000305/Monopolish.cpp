// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include <iostream>
#include <Windows.h>
#include "Monopolish.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


int main()
{
    // maximize the console to get better view 
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    {
        int seed;
        unique_ptr<bool> isRentIncreased[8];
        bool threePlayersAreBankrupted = false;
        bool isMonopolyFileRead = false;
        bool isSeedFileRead = false;

        vector<unique_ptr<CSquare>> squares; // CSquare vector of unique pointers
        unique_ptr<GameCreator> gameCreator = make_unique<GameCreator>(); // unique pointer for GameCreator
        unique_ptr<Player> player1 = make_unique<Player>("Dog", 1500, 1); // unique pointer for player 1
        unique_ptr<Player> player2 = make_unique<Player>("Car", 1500, 1); // unique pointer for player 2
        unique_ptr<Player> player3 = make_unique<Player>("Shoe", 1500, 1); // unique pointer for player 3
        unique_ptr<Player> player4 = make_unique<Player>("Hat", 1500, 1); // unique pointer for player 4

        cout << endl << "########################################" << endl << endl;
        cout << " // Created by M.Janith Iresha Peiris \n // UClan ID : G20924165 \n // UCL ID : 3000305" << endl << endl;

        if (gameCreator->readMonopolyTextFile()) // call the read monopoly.txt method. if there is an error in the File opening, then it will give an error message
        {
            cout << " Could not open the File 'monopoly.txt'" << endl;
        }
        else // if monopoly text File read successfully then display the successful message
        {
            gameCreator->getSquares(squares);
            for (auto& square : squares) // display the read data from MonopolishFile
            {
                square->display();
            }
            cout << "\n Monopoly.txt is read successfully !!" << endl;
            isMonopolyFileRead = true;
        }

        if (gameCreator->readSeedTextFile(seed)) // call the read seed.txt method. if there is an error in the File opening, then it will give an error message
        {
            cout << " Could not open the File 'seed.txt'" << endl;
        }
        else // if seed text File read successfully then display the successful message
        {
            cout << "\n Seed value is : " << seed << endl;
            cout << " Seed.txt is read successfully !!" << endl;
            isSeedFileRead = true;
        }

        cout << endl << "########################################" << endl;
        cout << endl << " Loading Monopolish";
        for (int i = 0; i < 16; i++)
        {
            Sleep(200); // make a 0.2s delay per loop. altogether 3.2s delay before start the game
            cout << ".";
        }
        system("cls"); // clear the screen before start the game

        if (isMonopolyFileRead && isSeedFileRead) { // check both files read correctly
            // display the welcome to monopoly text
            displayWelcome();
            system("pause");

            // display the monopoly board before start the game
            setBoardPosition(player1, player2, player3, player4);
            Sleep(1000);

            srand(seed); // pass the seed value to srand method

            for (unsigned short roundNumber = 0; roundNumber < 20; roundNumber++) // count the 20 dice rolls for game
            {
                cout << " ---------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t ---- Round No : " << roundNumber + 1 << " ---- " << endl; // display the round number

                // game flow
                int wonPlayer = runGameFlow(squares, player1, player2, player3, player4, isRentIncreased);

                if (wonPlayer != 0) // check one player is won
                {
                    displayGameOver(); // display game over message
                    cout << " Player ";
                    switch (wonPlayer) // get player name according to the wonPlayer
                    {
                    case 1: player1->displayWinByHavingMonopoly(); break;
                    case 2: player2->displayWinByHavingMonopoly(); break;
                    case 3: player3->displayWinByHavingMonopoly(); break;
                    case 4: player4->displayWinByHavingMonopoly(); break;
                    default: break;
                    }
                    threePlayersAreBankrupted = true;
                    break;
                }

                Sleep(1000);
                //system("pause");
            }

            // display the winner if other 3 players are not bankrupted
            if (!threePlayersAreBankrupted)
            {
                displayGameOver(); // display game over message

                cout << " ----Final money status of Players---- \n";
                player1->displayCurrentBalance();
                player2->displayCurrentBalance();
                player3->displayCurrentBalance();
                player4->displayCurrentBalance();

                outputFinalWinningPlayer(player1, player2, player3, player4);
            }

            // display the thank you screen
            displayThankYou();
        }
    	else
        {
            cout << " Error in file reading..!! Try again..!!" << endl;
        }
    }

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

// display player completes a round message
void displayRoundComplete(string playerName)
{
    cout << " " << playerName << " passes GO and collects " << pound << "200 " << endl;
}

// set the player board position according to actual player position 
void setBoardPosition(unique_ptr<Player>& player1, unique_ptr<Player>& player2, unique_ptr<Player>& player3, unique_ptr<Player>& player4)
{
    string player1Pos[26];
    string player2Pos[26];
    string player3Pos[26];
    string player4Pos[26];

    for (int index = 0; index < 26; ++index) // assign all to 4 spaces 
    {
        player1Pos[index] = "    ";
        player2Pos[index] = "    ";
        player3Pos[index] = "    ";
        player4Pos[index] = "    ";
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
    cout << endl;
    cout << "\t\t     GGGGGGGG           AA        MM          MM  EEEEEEEEE           OOOO     VV          VV  EEEEEEEEE  RRRRRRR        !!    " << endl;
    cout << "\t\t    GG      GG         A  A       MMM        MMM  EE                OO    OO    VV        VV   EE         RR     RR     !!!!   " << endl;
    cout << "\t\t   GG                 A    A      MM MM    MM MM  EE               OO      OO    VV      VV    EE         RR     RR     !!!!   " << endl;
    cout << "\t\t  GGG     GGGGGG     AAAAAAAA     MM  MM  MM  MM  EEEEEE          OOO      OOO    VV    VV     EEEEEE     RRRRRRR        !!    " << endl;
    cout << "\t\t   GG      GG GG    AA      AA    MM   MMMM   MM  EE               OO      OO      VV  VV      EE         RR RR          !!    " << endl;
    cout << "\t\t    GG    GG  GG   AA        AA   MM    MM    MM  EE                OO    OO        VVVV       EE         RR   RR             " << endl;
    cout << "\t\t      GGGGG   GG  AA          AA  MM          MM  EEEEEEEEE           OOOO           VV        EEEEEEEEE  RR     RR      !!    " << endl << endl;
}

// game flow
int runGameFlow(c_square& squares, unique_ptr<Player>& player1, unique_ptr<Player>& player2,
                 unique_ptr<Player>& player3, unique_ptr<Player>& player4, unique_ptr<bool> isRentIncreased[])
{
    int pDice;
    if (!player1->getIsBankrupt()) // check if the player is bankrupted
    {
        pDice = random(); // get a random number for die roll
        handleGameFlow(squares, player1, player2, player3, player4, pDice);
        if (player1->getPlayerMoney() <= 0) // if player money is lower than or equal to 0 then sell the lowest valued property
            mortgageProperty(squares, player1, isRentIncreased);
        else // if player money is greater that 0 then buy the sold properties
            buyMortgageProperties(squares, player1);
    	cout << endl;
        // if player has owned all properties of the same colour then double the rent of those properties
        increaseRent(squares, player1, isRentIncreased);
    }
    cout << endl;
    if (!player2->getIsBankrupt())
    {
        pDice = random();
        handleGameFlow(squares, player2, player1, player3, player4, pDice);
        if (player2->getPlayerMoney() <= 0)
            mortgageProperty(squares, player2, isRentIncreased);
        else
            buyMortgageProperties(squares, player2);
    	cout << endl;
        // if player has owned all properties of the same colour then double the rent of those properties
        increaseRent(squares, player2, isRentIncreased);
    }
    cout << endl;
    if (!player3->getIsBankrupt())
    {
        pDice = random();
        handleGameFlow(squares, player3, player2, player1, player4, pDice);
        if (player3->getPlayerMoney() <= 0)
            mortgageProperty(squares, player3, isRentIncreased);
        else
            buyMortgageProperties(squares, player3);
    	cout << endl;
        // if player has owned all properties of the same colour then double the rent of those properties
        increaseRent(squares, player3, isRentIncreased);
    }
    cout << endl;
    if (!player4->getIsBankrupt())
    {
        pDice = random();
        handleGameFlow(squares, player4, player2, player3, player1, pDice);
        if (player4->getPlayerMoney() <= 0)
            mortgageProperty(squares, player4, isRentIncreased);
        else
            buyMortgageProperties(squares, player4);
    	cout << endl;
        // if player has owned all properties of the same colour then double the rent of those properties
        increaseRent(squares, player4, isRentIncreased);
    }
    cout << endl;

    setBoardPosition(player1, player2, player3, player4); // display player position on the board
        
    // check which player won the game due to bankruptcy of other players
    int wonPlayer = checkWinningPlayerWithoutBankrupt(player1->getIsBankrupt(), player2->getIsBankrupt(), player3->getIsBankrupt(),
                                         player4->getIsBankrupt());

    // display the current balance of the players
    cout << " ----Current money status of Players---- \n";
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

// when player lands on a mSquares, do the calculations and display messages according to the mSquares rules
void handleGameFlow(c_square& squares, unique_ptr<Player>& playerMain, unique_ptr<Player>& subPlayer1,
                       unique_ptr<Player>& subPlayer2, unique_ptr<Player>& subPlayer3, int pDie)
{
    bool isRoundComplete = false;
	playerMain->displayDieRollDetails(pDie); // display player name & die value
    playerMain->setPlayerPosition(playerMain->getPlayerPosition() + pDie); // set player position according to the dice value
    
    if (playerMain->getPlayerPosition() > 26) // check player position exceed the mSquares count
    {
        playerMain->setPlayerPosition(playerMain->getPlayerPosition() - 26); // if exceed deduct 26 (mSquares count) from the position
        isRoundComplete = true;
    }
    
    int mainPlayerPosition = playerMain->getPlayerPosition(); // get player position

    if(isRoundComplete) // if player completes one round
    {
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() + 200); // player collects £200
        displayRoundComplete(playerMain->getPlayerName()); // display round complete message
    }

    int secondDieValue = 0;
    // roll the die for second time if player lands on bonus or penalty
	if(squares[mainPlayerPosition - 1]->getSType() == 4 || squares[mainPlayerPosition - 1]->getSType() == 5)
	{
        secondDieValue = random(); // get a random number to claim the penalty
	}

    squares[mainPlayerPosition - 1]->setBonus(secondDieValue); // set the bonus name and value
    playerMain->setPlayerMoney(playerMain->getPlayerMoney() + squares[mainPlayerPosition - 1]->getBonusAmount()); // add the bonus amount to player money

    squares[mainPlayerPosition - 1]->setPenalty(secondDieValue);// set the penalty name and value
    playerMain->setPlayerMoney(playerMain->getPlayerMoney() - squares[mainPlayerPosition - 1]->getPenaltyAmount());// deduct the penalty amount to player money
    
    playerMain->setPlayerMoney(playerMain->getPlayerMoney() - squares[mainPlayerPosition - 1]->getSFine()); // deduct jail fine (£50) from players' money

    squares[mainPlayerPosition - 1]->displayPlayerLandsOnDetails(playerMain); // display player lands on details

    payRent(squares, playerMain, subPlayer1, subPlayer2, subPlayer3, mainPlayerPosition);
    buyProperty(squares, playerMain, mainPlayerPosition);
}

// pay the rent if it is already owned another player
void payRent(c_square& squares, unique_ptr<Player>& playerMain, unique_ptr<Player>& subPlayer1,
    unique_ptr<Player>& subPlayer2, unique_ptr<Player>& subPlayer3, int mainPlayerPosition)
{
    // check main player doesn't own a particular property or station and  another player owns it. if it is true then main player will pay the rent
    if (!playerMain->getPlayerHavingProperty(mainPlayerPosition - 1) && (subPlayer1->getPlayerHavingProperty(mainPlayerPosition - 1) ||
        subPlayer2->getPlayerHavingProperty(mainPlayerPosition - 1) || subPlayer3->getPlayerHavingProperty(mainPlayerPosition - 1)) && 
        (squares[mainPlayerPosition - 1]->getSOwnerName() != "None"))
    {
        // deduct the property rent from main player money 
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() - squares[mainPlayerPosition - 1]->getSRent());

        // check which player owns that property and add the rent to players' money
        if (subPlayer1->getPlayerHavingProperty(mainPlayerPosition - 1))
            subPlayer1->setPlayerMoney(subPlayer1->getPlayerMoney() + squares[mainPlayerPosition - 1]->getSRent());

        else if (subPlayer2->getPlayerHavingProperty(mainPlayerPosition - 1))
            subPlayer2->setPlayerMoney(subPlayer2->getPlayerMoney() + squares[mainPlayerPosition - 1]->getSRent());

        else if (subPlayer3->getPlayerHavingProperty(mainPlayerPosition - 1))
            subPlayer3->setPlayerMoney(subPlayer3->getPlayerMoney() + squares[mainPlayerPosition - 1]->getSRent());

        squares[mainPlayerPosition - 1]->displayPayingRentDetails(playerMain->getPlayerName()); // display pay rent details
    }
}

// player buys a property or station if no one owns it
void buyProperty(c_square& squares, unique_ptr<Player>& playerMain, int mainPlayerPosition)
{
    // check any player doesn't own the property or station. if it is true main player will buy that property or station
    if (squares[mainPlayerPosition-1]->getSOwnerName() == "None" && playerMain->getPlayerMoney() > 0)
    {
        squares[mainPlayerPosition - 1]->setSOwnerName(playerMain->getPlayerName());
        //playerMain->setPlayerOwnedProperty(mainPlayerPosition - 1, true);
        playerMain->setPlayerHavingProperty(mainPlayerPosition - 1, true);

        // deduct the property cost from player money
        playerMain->setPlayerMoney(playerMain->getPlayerMoney() - squares[mainPlayerPosition - 1]->getSCost());
        playerMain->displayBuyingDetails(squares); // display property buying details
    }
}

// increase the property rent after player buys all the properties of same colour code
void increaseRent(c_square& squares, unique_ptr<Player>& player, unique_ptr<bool> isRentIncreased[])
{
    bool* isAllPropertyOwn = checkOwnSameProperties(squares, player); // check all the properties related to same colour group is owned by same player

    for (int propertyColourIndex = 0; propertyColourIndex < 8; propertyColourIndex++)
    {
        for (auto& square : squares)
        {
            //check previously rent was increased and all properties owned by same player and mSquares type is 1 and colour group is equal to propertyIndex
            if (!isRentIncreased[propertyColourIndex] && isAllPropertyOwn[propertyColourIndex] && square->getSType() == 1 &&
                square->getSColourGroup() == propertyColourIndex)
            {
                cout << " Property Name : " << square->getSName() << " rent is increased " << pound << square->getSRent();
                square->setSRent(square->getSRent() * 2); // double the property rent
                cout << " to " << pound << square->getSRent() << endl;
            }
        }
        if (isAllPropertyOwn[propertyColourIndex]) // check all the properties of same colour group is owned by same player
        {
            isRentIncreased[propertyColourIndex] = make_unique<bool>(true); // make that property rent increased is true
        }
    }
}

// decrease the property rent after player sells one property of same colour code after buying all properties of same colour
void decreaseRent(c_square& squares, unique_ptr<Player>& player, unique_ptr<bool> isRentIncreased[])
{
    bool* isAllPropertyOwn = checkOwnSameProperties(squares, player); // check all the properties related to same colour group is owned by same player

    for (int propertyIndex = 0; propertyIndex < 8; propertyIndex++)
    {
        for (auto& square : squares)
        {
            //check previously rent was not increased and all properties didn't own by same player and mSquares type is 1 and colour group is equal to propertyIndex 
            if (isRentIncreased[propertyIndex] && !isAllPropertyOwn[propertyIndex] && square->getSType() == 1 &&
                square->getSColourGroup() == propertyIndex)
            {
                cout << " Property Name : " << square->getSName() << " rent is decreased " << pound << square->getSRent();
                square->setSRent(square->getSRent() / 2);
                cout << " to " << pound << square->getSRent() << endl;
            }
        }
        if (!isAllPropertyOwn[propertyIndex]) // check all the properties of same colour group is not owned by same player
        {
            isRentIncreased[propertyIndex] = make_unique<bool>(false); // make that property rent increased is false
        }
    }
}

// check all the properties related to same colour group is owned by same player
bool* checkOwnSameProperties(c_square& squares, unique_ptr<Player>& player)
{
    static bool isPropertyOwned[8]{ false };

    for (int propertyColourIndex = 0; propertyColourIndex < 8; propertyColourIndex++)
    {
        bool isOwned = false;
        for (int squareIndex = 0; squareIndex < squares.size(); squareIndex++)
        {
            // check mSquares type is equal to 1 and property colour group is equal to propertyColourGroup to get all same colour group properties 
            if (squares[squareIndex]->getSType() == 1 && squares[squareIndex]->getSColourGroup() == propertyColourIndex)
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
    return isPropertyOwned;
}

// after player gets negative amount of money then players will mortgage their properties
void mortgageProperty(c_square& squares, unique_ptr<Player>& player, unique_ptr<bool> isRentIncreased[])
{
    while (player->getPlayerMoney() <= 0) // continue until player gets positive amount of money
    {
        unsigned short index = findMinimumValueProperty(squares, player, true);

        if (player->getPlayerHavingProperty(index)) // check players' own properties
        {
            player->setPlayerMoney(player->getPlayerMoney() + squares[index]->getSCost()); // add property cost to players' money
            player->setPlayerHavingProperty(index, false); // remove the property ownership from player side
            player->displayPropertyMortgageMessage(squares[index]->getSName()); // display mortgage the property message
        }
        if (index == 0) // check player has no properties to mortgage
        {
            player->setIsBankrupt(); // change the player as bankrupt player
            player->displayPlayerBankruptMessage(); // display player bankrupt message
            break;
        }

        // if player has sold one property that player owned all properties of the same colour then reduce the rent of those properties
        decreaseRent(squares, player, isRentIncreased);
    }
}

// player buys lent properties
void buyMortgageProperties(c_square& squares, unique_ptr<Player>& player)
{
    while (player->getPlayerMoney() > 0)
    {
        unsigned short index = findMinimumValueProperty(squares, player, false);
        
        // check player owned that property previously and not having it now and buying cost will not cause negative amount of money and player is not bankrupted
        if (squares[index]->getSOwnerName() == player->getPlayerName() && !player->getPlayerHavingProperty(index) &&
            (player->getPlayerMoney() - squares[index]->getSCost()) > 0 && !player->getIsBankrupt())
        {
            player->setPlayerHavingProperty(index, true); // buy that property again to player
            player->setPlayerMoney(player->getPlayerMoney() - squares[index]->getSCost()); // deduct the property cost from players' money
        }
        else
        {
            break;
        }
    }
}

// find the lowest valued property
int findMinimumValueProperty(c_square& squares, unique_ptr<Player>& player, bool isSelling)
{
    unsigned short minIndex = 0;
    float minCost = 0;
    bool isFirstLoop = true;
    for (int index = 0; index < squares.size(); ++index)
    {
        //  if player sell the property
        if (squares[index]->getSOwnerName() == player->getPlayerName() && player->getPlayerHavingProperty(index) && isSelling &&
            (squares[index]->getSType() == 1 || squares[index]->getSType() == 3))
        {
            if (isFirstLoop) // assign a value to minCost variable in the first loop 
            {
                minCost = squares[index]->getSCost();
                minIndex = index;
                isFirstLoop = false;
            }
            else if (!isFirstLoop && minCost > squares[index]->getSCost())
            {
                minCost = squares[index]->getSCost();
                minIndex = index;
            }
        }
        
        // if player re buys the property
        if (squares[index]->getSOwnerName() == player->getPlayerName() && !player->getPlayerHavingProperty(index) && !isSelling &&
            (squares[index]->getSType() == 1 || squares[index]->getSType() == 3))
        {
            if (isFirstLoop) // assign a value to minCost variable in the first loop 
            {
                minCost = squares[index]->getSCost();
                minIndex = index;
                isFirstLoop = false;
            }
            else if (!isFirstLoop && minCost > squares[index]->getSCost())
            {
                minCost = squares[index]->getSCost();
                minIndex = index;
            }
        }
    }
    return minIndex;
}

// check whether which player will win when the other 3 players are bankrupted
int checkWinningPlayerWithoutBankrupt(bool player1, bool player2, bool player3, bool player4)
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
void outputFinalWinningPlayer(unique_ptr<Player>& player1, unique_ptr<Player>& player2,
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
