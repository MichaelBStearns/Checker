#include "pch.h"
#include <iostream>
#include "RPiece.h"
#include "RKing.h"
#include "Board.h"
using namespace std;

RPiece::RPiece() {}
RPiece::RPiece(Board Board) {
	static int i = 1;
	if (i <= 4) {
		xposition = (i * 2);
		yposition = 8;
	}
	else if (i >= 5 && i <= 8) {
		xposition = (((i - 4) * 2) - 1);
		yposition = 7;
	}
	else if (i >= 9 && i <= 12) {
		xposition = ((i - 8) * 2);
		yposition = 6;
	}

	Board.CBoard[yposition][xposition] = "   Red   ";
	++i;
}


RPiece::~RPiece() {

}

double RPiece::getPos() {
	int position = (yposition * 10) + xposition;
	return position;
}

void RPiece::setPos(int y, int x) {
	xposition = x;
	yposition = y;
}

void RPiece::makeKing() {
	CBoard[yposition][xposition] = " RedKing ";
	delete this;
	RKing(yposition, xposition);
}

bool RPiece::move(int newpos, Board Board) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() - 9;
	maybe1 = getPos() - 11;
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
		Board.CBoard[newpos / 10][newpos % 10] = "   Red   ";
		xposition = newpos % 10;
		yposition = newpos / 10;
		return 1;
	}
	else {
		cout << "Invalid move" << endl;
		return 0;
	}
}

bool RPiece::jump(int newpos, Board Board) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 9;
	maybe1 = getPos() - 11;
	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "Red") {
			possibilities[0] = getPos() + 18;
		}
	}
	if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard[maybe1 / 10][maybe1 % 10] == "Red") {
			possibilities[1] = getPos() - 22;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1]) {
		Board.CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		Board.CBoard[xposition][yposition] = "Red";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}