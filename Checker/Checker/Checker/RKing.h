#pragma once
#include "RPiece.h"

class RKing : public RPiece {

public:
	RKing(int, int);
	~RKing();

	bool move(int newpos);
	bool jump(int newpos);
};

