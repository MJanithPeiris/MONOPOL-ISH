#pragma once
#include <memory>
#include <vector>
#include "CSquare.h"

using namespace std;

class FileRead
{
private:
	typedef vector<unique_ptr<CSquare>> c_square;
	c_square squares;
	
public:
	FileRead();
	~FileRead();
	bool readMonopolyTextFile();
	bool readSeedTextFile(int& seed);
	void createSquareObjects(vector<string> lineVector);
	vector<string> separateLine(string line);
	vector<unique_ptr<CSquare>> const& getSquare() const;
};