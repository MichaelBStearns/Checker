#include "pch.h"
#include <iostream>
#include "RKing.h"
#include "Red.h"
using namespace std;

RKing::RKing(int x, int y) {
	xposition = x;
	yposition = y;
}


RKing::~RKing(){

}

bool RKing::movebackward(int newpos) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 11;
	maybe1 = getPos() - 9;
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
		CBoard[xposition][yposition] = "RedKing";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}

bool RKing::jumpbackward(int newpos) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 11;
	maybe1 = getPos() - 9;
	if (maybe0 >= 11 && maybe0 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "Black" || CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			possibilities[0] = getPos() + 22;
		}
	}
	if (maybe1 >= 11 && maybe1 <= 88) {
		if (CBoard[maybe0 / 10][maybe0 % 10] == "Black" || CBoard[maybe0 / 10][maybe0 % 10] == "BlackKing") {
			possibilities[1] = getPos() - 18;
		}
	}
	if (newpos == possibilities[0] || newpos == possibilities[1]) {
		CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		CBoard[xposition][yposition] = "RedKing";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}