#pragma once
#include "Black.h"
#include "Piece.h"

class BPiece: public Piece{

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

