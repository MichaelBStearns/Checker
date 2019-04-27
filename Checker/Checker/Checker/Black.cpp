#include "pch.h"
#include <iostream>
#include "Black.h"
#include "Board.h"
using namespace std;

Black::Black() {

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
	return 1;
}
bool Black::jump(int newpos) {
	return 1;
}