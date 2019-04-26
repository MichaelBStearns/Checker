#include "pch.h"
#include "Piece.h"
#include "BPiece.h"
#include "BKing.h"
#include <iostream>
using namespace std;

BPiece::BPiece() {}
BPiece::BPiece(Board Board){
	static int i = 1;
	if (i <= 4) {
		xposition = ((i * 2) - 1);
		yposition = 1;
	}
	else if (i >= 5 && i <= 8) {
		xposition = ((i - 4) * 2);
		yposition = 2;
	}
	else if (i >= 9 && i <= 12) {
		xposition = (((i - 8) * 2) - 1);
		yposition = 3;
	}

	Board.CBoard[yposition][xposition] = "  Black  ";
	++i;
}


BPiece::~BPiece(){

}

double BPiece::getPos() {
	int position = (yposition * 10) + xposition;
	return position;
}

void BPiece::setPos(int y, int x) {
	xposition = x;
	yposition = y;
}

void BPiece::makeKing() {
	CBoard[yposition][xposition] = "BlackKing";
	delete this;
	BKing(yposition, xposition);
}

bool BPiece::move(int newpos, Board Board) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 11;
	maybe1 = getPos() + 9;
	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "         ") {
			possibilities[0] = maybe0;
		}
		else { 
			cout << "Invalid move" << endl;
			return 0;
		}
	}
	if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard[maybe1 / 10][maybe1 % 10] == "         ") {
			possibilities[1] = maybe1;
		}
		else {
			cout << "Invalid move" << endl;
			return 0;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1]) {
		Board.CBoard[yposition][xposition] = "         ";
		Board.CBoard[newpos / 10][newpos % 10] = "  Black  ";
		xposition = newpos % 10;
		yposition = newpos / 10;
		return 1;
	}
	else {
		cout << "Invalid move" << endl;
		return 0;
	}
}
bool BPiece::jump(int newpos, Board Board) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 11;
	maybe1 = getPos() + 9;
	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "Red" || CBoard[maybe0 / 10][maybe0 % 10] == "RedKing") {
			possibilities[0] = getPos() + 22;
		}
	}
	if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "Red" || CBoard[maybe0 / 10][maybe0 % 10] == "RedKing") {
			possibilities[1] = getPos() - 18;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1]) {
		Board.CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		Board.CBoard[xposition][yposition] = "Black";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}