#include "pch.h"
#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "RPiece.h"
#include "RKing.h"
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

bool RPiece::action(int oldpos, int newpos, Board Board) {
	//TODO make it so you can take multiple actions in the same turn, if circumstances allow
	if (newpos / 10 == 8) {
		return makeKing();
	}
	else if (newpos == oldpos - 11 || newpos == oldpos - 9) {
		return move(newpos, Board);
	}
	else if (newpos == oldpos - 22 || newpos == oldpos - 18) {
		return jump(newpos, Board);
	}
	else {
		cout << "Unknown Error 1" << endl;
	}
}

bool RPiece::makeKing() {
	CBoard.CBoard[yposition][xposition] = " RedKing ";
	delete this;
	RKing(yposition, xposition);
	return 1;
}

bool RPiece::move(int newpos, Board Board) {
	int possibilities[2] = { 0 };
	int maybe0, maybe1;
	maybe0 = getPos() - 9;
	maybe1 = getPos() - 11;

	if (maybe0 / 10 >= 1 && maybe0 / 10 <= 8 && maybe0 % 10 >= 1 && maybe0 % 10 <= 8) {
		if (Board.CBoard[maybe0 / 10][maybe0 % 10] == "         ") {
				possibilities[0] = maybe0;
		}
	}
	if (maybe1 / 10 >= 1 && maybe1 / 10 <= 8 && maybe1 % 10 >= 1 && maybe1 % 10 <= 8) {
		if (Board.CBoard[maybe1 / 10][maybe1 % 10] == "         ") {
			possibilities[1] = maybe1;
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
	double possibilities[2] = { 0 };
	int maybe0, maybe1;
	maybe0 = getPos() - 9;
	maybe1 = getPos() - 11;
	cout << CBoard.CBoard[4][4] << endl;
	if (maybe0 / 10 >= 1 && maybe0 / 10 <= 8 && maybe0 % 10 >= 1 && maybe0 % 10 <= 8) {
		if (Board.CBoard[maybe0 / 10][maybe0 % 10] == "  Black  " || Board.CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			if (Board.CBoard[newpos / 10][newpos % 10] == "         ") {
				possibilities[0] = getPos() + 18;
			}
		}
	}
	if (maybe1 / 10 >= 1 && maybe1 / 10 <= 8 && maybe1 % 10 >= 1 && maybe1 % 10 <= 8) {
		if (Board.CBoard[maybe1 / 10][maybe1 % 10] == "  Black  " || Board.CBoard[maybe1 / 10][maybe1 % 10] == "BlackKing") {
			if (Board.CBoard[newpos / 10][newpos % 10] == "         ") {
				possibilities[1] = getPos() - 22;
			}
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1]) {
		//TODO delete the object that is being jumped, don't just delete the word on the board
			//maybe we don't need to though. if erases from board, then as good as gone
		Board.CBoard[yposition][xposition] = "         ";
		Board.CBoard[(yposition + (newpos / 10)) / 2][(xposition + (newpos % 10)) / 2] = "         ";
		setPos(newpos / 10, newpos % 10);
		Board.CBoard[yposition][xposition] = "   Red   ";
		return 1;
	}
	else {
		cout << "Invalid move" << endl;
		return 0;
	}
}