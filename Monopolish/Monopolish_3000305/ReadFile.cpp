#include <iostream>
#include <fstream>
#include <sstream>
#include "ReadFile.h"
#include "CSquare.h"
#include "CProperties.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"

using namespace std;

// default constructor
FileRead::FileRead(){}

// destructor
FileRead::~FileRead()
{
    //for (auto& obj : squares)
    //{
    //    auto itr = find(begin(squares), end(squares), obj);
    //    if (itr != squares.end())
    //    {
    //        squares.erase(itr); // erase the values
    //    }
    //}
}

//  read monopoly.txt file
bool FileRead::readMonopolyTextFile()
{
    ifstream inputFile("monopoly.txt");
    string* line = new string(" ");

    if (!inputFile.is_open()) { // check whether the file is there and open
        return true; 
    }
    else
    {
        while (getline(inputFile, *line)) {
            vector<string> lineVector = separateLine(*line);
            createSquareObjects(lineVector);
            lineVector.clear();
        }
    }
    delete line; // delete the pointer
    inputFile.close();

    return false;
}

// seperate the line using space and put it to a vector
vector<string> FileRead::separateLine(string line)
{
    stringstream* newLine = new stringstream(line);
    vector<string> wordsVector;
    string word;
    bool isString = true;
    int index = 0;

    while (getline(*newLine, word, ' '))
    {
        if (isdigit(word[0]) != 0) // check is it a number or text
        {
            wordsVector.push_back(word); // push back to vector
            isString = true;
        }
        else
        {
            if (isString) 
            {
                wordsVector.push_back(word); // push back to vector
                index = wordsVector.size() - 1; // get the current index
                isString = false;
            }
            else
            {
                wordsVector[index].append(" " + word); // concatenate with the next word
            }
        }
    }

    delete newLine; // delete the pointer
    return wordsVector; // return the vector
}

// create objects according to the type
void FileRead::createSquareObjects(vector<string> lineVector)
{
    switch (stoi(lineVector[0])) // check the first element of the vector ( type )
    {
    case 1: squares.push_back(make_unique<CProperties>(stoi(lineVector[0]), lineVector[1], stof(lineVector[2]), stof(lineVector[3]), stoi(lineVector[4]))); break; // type 1
    case 2: squares.push_back(make_unique<CSquare>(stoi(lineVector[0]), lineVector[1])); break; // type 2
    case 3: squares.push_back(make_unique<CStation>(stoi(lineVector[0]), lineVector[1], 200, 10)); break; // type 3
    case 4: squares.push_back(make_unique<CBonus>(stoi(lineVector[0]), lineVector[1])); break; // type 4
    case 5: squares.push_back(make_unique<CPenalty>(stoi(lineVector[0]), lineVector[1])); break; // type 5
    case 6: squares.push_back(make_unique<CJail>(stoi(lineVector[0]), lineVector[1])); break; // type 6
    case 7: squares.push_back(make_unique<CGoToJail>(stoi(lineVector[0]), lineVector[1],50)); break; // type 7
    case 8: squares.push_back(make_unique<CFreeParking>(stoi(lineVector[0]), lineVector[1])); break; // type 8
    default: cout << " Error occurs !!" << endl;
    }
}

// read the seed.txt file
bool FileRead::readSeedTextFile(int& seed)
{
    ifstream inputFile("seed.txt");
    string* line = new string(" ");

    if (!inputFile.is_open()) { // check whether the file is there and open
        return true;
    }
	else
    {
        getline(inputFile, *line);
        seed = stoi(*line);
    }
    delete line; // delete the pointer
    inputFile.close();

    return false;
}

// returns method for squares
vector<unique_ptr<CSquare>> const& FileRead::getSquare() const
{
    return squares;
}