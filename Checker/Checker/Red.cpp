#include "pch.h"
#include <iostream>
#include "Red.h"
#include "Board.h"
using namespace std;

Red::Red() {

}

Red::~Red() {

}

double Red::getPos() {
	int position = (xposition * 10) + yposition;
	return position;
}

void Red::setPos(int x, int y) {
	xposition = x;
	yposition = y;
}

bool Red::move(int newpos) {
	return 1;
}

bool Red::jump(int newpos) {
	return 1;
}