#pragma once
#include "Black.h"

class BKing: public Black{

public:
	BKing(int, int);
	~BKing();

	bool move(int pos);
	bool jump(int pos);
};

