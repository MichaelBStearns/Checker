#pragma once
#include "Red.h"

class RKing : public Red {

public:
	RKing(int, int);
	~RKing();

	bool movebackward(int newpos);
	bool jumpbackward(int newpos);
};

