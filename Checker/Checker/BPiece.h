#pragma once
#include "Black.h"

class BPiece: public Board{

public:
	BPiece();
	BPiece(Board);
	~BPiece();

	double getPos();
	void setPos(int, int);
	bool move(int pos, Board);
	bool jump(int pos, Board);
	void makeKing();
};

