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

int main() {
	int startloc, newloc, done = 0, correct = 0;

	cout << "Welcome to Checkers\n";
	Board Board;

	RPiece red1(Board), red2(Board), red3(Board), red4(Board), red5(Board), red6(Board), red7(Board), red8(Board), red9(Board), red10(Board), red11(Board), red12(Board);
	BPiece black1(Board), black2(Board), black3(Board), black4(Board), black5(Board), black6(Board), black7(Board), black8(Board), black9(Board), black10(Board), black11(Board), black12(Board);

	while (!done) {
		cout << Board;

		while (!correct) {
			cout << "Black's Turn:" << endl;
			cin >> startloc;
			cout << "to" << endl;
			cin >> newloc;
			//TODO clean up this mess, maybe move ot class?
			//TODO clean up output window when errors are given
			if (Board.CBoard[startloc / 10][startloc % 10] == "  Black  ") {
				if (black1.getPos() == startloc) {
					correct = black1.action(startloc, newloc, Board);
				}
				else if (black2.getPos() == startloc) {
					correct = black2.action(startloc, newloc, Board);
				}
				else if (black3.getPos() == startloc) {
					correct = black3.action(startloc, newloc, Board);
				}
				else if (black4.getPos() == startloc) {
					correct = black4.action(startloc, newloc, Board);
				}
				else if (black5.getPos() == startloc) {
					correct = black5.action(startloc, newloc, Board);
				}
				else if (black6.getPos() == startloc) {
					correct = black6.action(startloc, newloc, Board);
				}
				else if (black7.getPos() == startloc) {
					correct = black7.action(startloc, newloc, Board);
				}
				else if (black8.getPos() == startloc) {
					correct = black8.action(startloc, newloc, Board);
				}
				else if (black9.getPos() == startloc) {
					correct = black9.action(startloc, newloc, Board);
				}
				else if (black10.getPos() == startloc) {
					correct = black10.action(startloc, newloc, Board);
				}
				else if (black11.getPos() == startloc) {
					correct = black11.action(startloc, newloc, Board);
				}
				else if (black12.getPos() == startloc) {
					correct = black12.action(startloc, newloc, Board);
				}
				else {
					cout << endl << "Error. Try Again." << endl;
				}
			}
			else {
				cout << "That's not one of your pieces. Try Again." << endl;
			}
		}
		correct = 0;
		system("CLS");
		cout << Board;
		while (!correct) {
			cout << "Red's Turn:" << endl;
			cin >> startloc;
			cout << "to" << endl;
			cin >> newloc;
			if (Board.CBoard[startloc / 10][startloc % 10] == "   Red   ") {
				if (red1.getPos() == startloc) {
					correct = red1.action(startloc, newloc, Board);
				}
				else if (red2.getPos() == startloc) {
					correct = red2.action(startloc, newloc, Board);
				}
				else if (red3.getPos() == startloc) {
					correct = red3.action(startloc, newloc, Board);
				}
				else if (red4.getPos() == startloc) {
					correct = red4.action(startloc, newloc, Board);
				}
				else if (red5.getPos() == startloc) {
					correct = red5.action(startloc, newloc, Board);
				}
				else if (red6.getPos() == startloc) {
					correct = red6.action(startloc, newloc, Board);
				}
				else if (red7.getPos() == startloc) {
					correct = red7.action(startloc, newloc, Board);
				}
				else if (red8.getPos() == startloc) {
					correct = red8.action(startloc, newloc, Board);
				}
				else if (red9.getPos() == startloc) {
					correct = red9.action(startloc, newloc, Board);
				}
				else if (red10.getPos() == startloc) {
					correct = red10.action(startloc, newloc, Board);
				}
				else if (red11.getPos() == startloc) {
					correct = red11.action(startloc, newloc, Board);
				}
				else if (red12.getPos() == startloc) {
					correct = red12.action(startloc, newloc, Board);
				}
				else {
					cout << endl << "Error. Try Again." << endl;
				}
			}

			else {
				cout << "That's not one of your pieces. Try Again." << endl;
			}
		}
		correct = 0;
		system("CLS");
	}
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu