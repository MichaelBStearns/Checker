#pragma once
#include <string>
#include "Board.h"
using namespace std;

class Red{

public:
	Red();
	~Red();

	Board CBoard[8][8];

	double getPos();
	void setPos(int, int);

};

