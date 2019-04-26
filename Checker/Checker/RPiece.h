#pragma once
#include "Red.h"
#include "Piece.h"

class RPiece: public Piece {

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

