#pragma once
#include "Board.h"
class Piece
{
public:
	int xposition;
	int yposition;

	Board CBoard;

	Piece();
	~Piece();

	virtual bool action(int oldpos, int newpos, Board);
	virtual bool move(int pos, Board);
	virtual bool jump(int pos, Board);
};

