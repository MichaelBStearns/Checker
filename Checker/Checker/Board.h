#pragma once
#include <string>
using namespace std;

class Board{
	
public:
	int xposition;
	int yposition;

	Board();
	~Board();

	string CBoard[9][9];

	friend ostream &operator<< (ostream &output, const Board &CBoard);
};

