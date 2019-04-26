#include "pch.h"
#include <iostream>
#include "RKing.h"
#include "RPiece.h"
using namespace std;

RKing::RKing(int x, int y) {
	xposition = x;
	yposition = y;
}

RKing::~RKing(){

}

bool RKing::move(int newpos) {
	double possibilities[4];
	int maybe0, maybe1, maybe2, maybe3;
	maybe0 = getPos() + 11;
	maybe1 = getPos() - 9;
	maybe2 = getPos() + 9;
	maybe3 = getPos() - 11;

	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "Empty") {
			possibilities[0] = maybe0;
		}
	}
	else if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard.CBoard[maybe1 / 10][maybe1 % 10] == "Empty") {
			possibilities[1] = maybe1;
		}
	}
	else if (maybe2 >= 11 && maybe0 <= 88) {
		if (CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "Empty") {
			possibilities[0] = maybe0;
		}
	}
	else if (maybe3 >= 11 && maybe1 <= 88) {
		if (CBoard.CBoard[maybe1 / 10][maybe1 % 10] == "Empty") {
			possibilities[1] = maybe1;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1] || newpos == possibilities[2] || newpos == possibilities[3]) {
		CBoard.CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		CBoard.CBoard[xposition][yposition] = "RedKing";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}

bool RKing::jump(int newpos) {

	double possibilities[4];
	int maybe0, maybe1, maybe2, maybe3;
	maybe0 = getPos() + 9;
	maybe1 = getPos() - 11;
	maybe2 = getPos() + 11;
	maybe3 = getPos() - 9;
	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "Red" || CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			possibilities[0] = getPos() + 18;
		}
	}
	if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard.CBoard[maybe1 / 10][maybe1 % 10] == "Red" || CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			possibilities[1] = getPos() - 22;
		}
	}
	if (maybe2 >= 11 && maybe2 <= 88) {
		if (CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "Black" || CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			possibilities[0] = getPos() + 22;
		}
	}
	if (maybe3 >= 11 && maybe3 <= 88) {
		if (CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "Black" || CBoard.CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			possibilities[1] = getPos() - 18;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1] || newpos == possibilities[2] || newpos == possibilities[3]) {
		CBoard.CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		CBoard.CBoard[xposition][yposition] = "RedKing";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}

