#pragma once
#include "BPiece.h"
#include "Black.h"

class BKing: public BPiece{

public:
	BKing(int, int);
	~BKing();

	bool move(int pos);
	bool jump(int pos);
};

