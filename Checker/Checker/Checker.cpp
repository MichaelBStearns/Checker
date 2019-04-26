// Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Red.h"
#include "RPiece.h"
#include "RKing.h"
#include "Black.h"
#include "BPiece.h"
#include "BKing.h"

using namespace std;

int main(){
	
	cout << "Welcome to Checkers\n";
	Board Board;

	RPiece red1, red2, red3, red4, red5, red6, red7, red8, red9, red10, red11, red12;
	BPiece black1, black2, black3, black4, black5, black6, black7, black8, black9, black10, black11, black12;
	cout << "|	" << Board.CBoard[2][1] << "	";

	cout << Board;

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu