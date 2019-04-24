#pragma once
#include <string>
#include "Board.h"
using namespace std;

class Black: public Board
{
public:
	Black();
	~Black();

	double getPos();
	void setPos(int, int);

	bool moveforward(int newpos);
	bool jump(int newpos);
};

