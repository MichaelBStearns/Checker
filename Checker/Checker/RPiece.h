#pragma once
#include "Red.h"
#include "Board.h"

class RPiece: public Board {

public:
	RPiece();
	RPiece(Board);
	~RPiece();

	double getPos();
	void setPos(int, int);
	virtual bool move(int pos, Board);
	virtual bool jump(int pos, Board);
	void makeKing();
};

