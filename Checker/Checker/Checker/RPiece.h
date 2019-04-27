#pragma once
#include "Piece.h"

class RPiece: public Piece {

public:
	RPiece();
	RPiece(Board);
	~RPiece();

	double getPos();
	void setPos(int, int);
	virtual bool action(int oldpos, int newpos, Board);
	virtual bool move(int pos, Board);
	virtual bool jump(int pos, Board);
	bool makeKing();
};

