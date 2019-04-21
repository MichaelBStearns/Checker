#pragma once
#include "Black.h"

class BKing: public Black{

public:
	BKing(int, int);
	~BKing();

	bool movebackward(int newpos);
	bool jumpbackward(int newpos);
};

