#pragma once
#include <string>
#include "Board.h"
using namespace std;

class Red : public Board
{

public:
	Red();
	~Red();

	double getPos();
	void setPos(int, int);

	bool moveforward(int pos);
	bool jump(int pos);
};

