#pragma once
#include "Black.h"

class BPiece: public Black{

public:
	BPiece();
	~BPiece();

	bool move(int pos);
	bool jump(int pos);
	void makeKing();
};

