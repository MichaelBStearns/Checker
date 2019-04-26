#pragma once
#include <string>
using namespace std;

class Board{
	
public:
	int xposition;
	int yposition;

	Board();
	~Board();

	string** CBoard;

	friend ostream &operator<< (ostream &output, const Board &CBoard);
};

