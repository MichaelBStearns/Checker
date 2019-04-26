#pragma once
#include "Red.h"

class RKing : public Red {

public:
	RKing(int, int);
	~RKing();

	bool move(int newpos);
	bool jump(int newpos);

	
};

