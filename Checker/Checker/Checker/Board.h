#pragma once
#include <string>
using namespace std;

class Board{
	
public:

	Board();
	~Board();

	string** CBoard;

	friend ostream &operator<< (ostream &output, const Board &CBoard);
};

