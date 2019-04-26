#include "pch.h"
#include <iostream>
#include "RPiece.h"
#include "RKing.h"
using namespace std;

RPiece::RPiece() {

}


RPiece::~RPiece() {

}

void RPiece::makeKing() {
	CBoard[xposition][yposition] = "RedKing";
	delete this;
	RKing(xposition, yposition);
}

bool RPiece::move(int newpos) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 9;
	maybe1 = getPos() - 11;
	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "Empty") {
			possibilities[0] = maybe0;
		}
	}
	if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard[maybe1 / 10][maybe1 % 10] == "Empty") {
			possibilities[1] = maybe1;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1]) {
		CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		CBoard[xposition][yposition] = "Red";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}

bool RPiece::jump(int newpos) {
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
		CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		CBoard[xposition][yposition] = "Red";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}