#include "pch.h"
#include "RPiece.h"
#include "RKing.h"

RPiece::RPiece() {

}


RPiece::~RPiece() {

}

void RPiece::makeKing() {
	CBoard[xposition][yposition] = "RedKing";
	delete this;
	RKing(xposition, yposition);
}