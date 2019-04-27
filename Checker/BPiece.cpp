#include "pch.h"
#include "BPiece.h"
#include "BKing.h"

BPiece::BPiece(){

}


BPiece::~BPiece(){

}

void BPiece::makeKing() {
	CBoard[xposition][yposition] = "BlackKing";
	delete this;
	BKing(xposition, yposition);
}