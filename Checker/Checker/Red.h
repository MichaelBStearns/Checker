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

	virtual bool move(int pos);
	virtual bool jump(int pos);
};

