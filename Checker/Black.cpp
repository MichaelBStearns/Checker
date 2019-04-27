#include "pch.h"
#include <iostream>
#include "Black.h"
#include "Board.h"
using namespace std;

Black::Black() {
	static int i = 1;
	if(i <= 4){
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

	CBoard[xposition][yposition] = "Black";
	++i;
}


Black::~Black(){

}

double Black::getPos() {
	int position = (xposition * 10) + yposition;
	return position;
}

void Black::setPos(int x, int y) {
	xposition = x;
	yposition = y;
}
bool Black::moveforward(int newpos) {
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
		CBoard[xposition][yposition] = "Black";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}
bool Black::jump(int newpos) {
	double possibilities[2];
	int maybe0, maybe1;
	maybe0 = getPos() + 11;
	maybe1 = getPos() - 9;
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
		CBoard[xposition][yposition] = "Empty";
		setPos(newpos / 10, newpos % 10);
		CBoard[xposition][yposition] = "Black";
		return 1;
	}
	else {
		cout << "Invalid move";
		return 0;
	}
}