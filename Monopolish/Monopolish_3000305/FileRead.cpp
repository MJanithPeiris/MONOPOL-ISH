#include <iostream>
#include <fstream>
#include <sstream>
#include "FileRead.h"
#include "CSquare.h"
#include "CProperties.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"

using namespace std;

FileRead::FileRead(){}

FileRead::~FileRead()
{
    cout << " Destructor " << endl;
    for (auto& obj : square)
    {
        auto itr = find(begin(square), end(square), obj);
        if (itr != square.end())
        {
            square.erase(itr);
        }
    }
}

bool FileRead::readMonopolyTextFile()
{
    ifstream inputFile("monopoly.txt");
    string* line = new string(" ");

    if (!inputFile.is_open()) {
        return true;
    }
    else
    {
        while (getline(inputFile, *line)) {
            vector<string> lineVector = separateLine(*line);
            switch(stoi(lineVector[0]))
            {
	            case 1: square.push_back(make_unique<CProperties>(stoi(lineVector[0]), lineVector[1], stof(lineVector[2]), stof(lineVector[3]), stoi(lineVector[4]))); break;
	            case 2: square.push_back(make_unique<CSquare>(stoi(lineVector[0]), lineVector[1])); break;
	            case 3: square.push_back(make_unique<CStation>(stoi(lineVector[0]), lineVector[1], 200, 10)); break;
                case 4: square.push_back(make_unique<CBonus>(stoi(lineVector[0]), lineVector[1])); break;
                case 5: square.push_back(make_unique<CPenalty>(stoi(lineVector[0]), lineVector[1])); break;
	            case 6: square.push_back(make_unique<CJail>(stoi(lineVector[0]), lineVector[1])); break;
	            case 7: square.push_back(make_unique<CGoToJail>(stoi(lineVector[0]), lineVector[1])); break;
	            case 8: square.push_back(make_unique<CFreeParking>(stoi(lineVector[0]), lineVector[1])); break;
                default: cout << " Error occurs !!" << endl;;
            }
            lineVector.clear();
        }
    }
    delete line;
    inputFile.close();

    return false;
}

vector<string> FileRead::separateLine(string line)
{
    stringstream* ss = new stringstream(line);

    int type = 0, colorCode = 0;
    int cost = 0, rent = 0;
    string name1 = " ", name2 = " ", name3 = " ";
    vector<string> word;

    if (line[0] == '1')
    {
        *ss >> type >> name1 >> name2 >> cost >> rent >> colorCode;

        word.push_back(std::to_string(type));
        word.push_back(name1 + " " + name2);
        word.push_back(std::to_string(cost));
        word.push_back(std::to_string(rent));
        word.push_back(std::to_string(colorCode));
    }
    else {
        *ss >> type >> name1 >> name2 >> name3;

        word.push_back(std::to_string(type));
        word.push_back(name1 + " " + name2 + " " + name3);
    }

    delete ss;
    return word;
}

bool FileRead::readSeedTextFile(int& seed)
{
    ifstream inputFile("seed.txt");
    string line;

    if (!inputFile.is_open()) {
        return true;
    }
	else
    {
        getline(inputFile, line);
        seed = stoi(line);
    }
    inputFile.close();

    return false;
}

vector<unique_ptr<CSquare>> const& FileRead::getSquare() const
{
    return square;
}