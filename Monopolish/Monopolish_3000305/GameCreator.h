#pragma once
// UClan ID : G20924165 / UCL ID : 3000305
// M. Janith Iresha Peiris

#include <memory>
#include <vector>
#include "CSquare.h"

using namespace std;
typedef vector<unique_ptr<CSquare>> c_square;

class GameCreator
{
private:
	c_square mSquares;
	
public:
	GameCreator();
	~GameCreator();
	bool readMonopolyTextFile();
	bool readSeedTextFile(int& seed);
	void createSquareObjects(vector<string> lineVector);
	vector<string> separateLine(string line);
	void getSquares(c_square& squares);
};