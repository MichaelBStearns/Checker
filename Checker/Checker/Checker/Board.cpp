#include "pch.h"
#include "Board.h"
#include <string>
using namespace std;


Board::Board(){
	string** arr;
	arr = new string*[9];
	for (int i = 0; i < 9; i++) {
		arr[i] = new string[9];
	}
	Matrix:CBoard = arr;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			CBoard[i][j] = { "         " };
		}
	}
}


Board::~Board()
{
}


ostream &operator<< (ostream &output, const Board &CB) {
	output << endl << "     1         2         3         4         5         6         7         8" << endl;
	output << "  _______________________________________________________________________________" << endl;
	for (int i = 1; i < 9; i++) {		//for iterating rows
		output << " |         |         |         |         |         |         |         |         |" << endl;
		output << " |         |         |         |         |         |         |         |         |" << endl << i;
		for (int j = 1; j < 9; j++) {	//for iterating columns
			output << "|" << CB.CBoard[i][j];
		}
		output << "|" << endl << " |         |         |         |         |         |         |         |         |" << endl 
					<< " |_________|_________|_________|_________|_________|_________|_________|_________|" <<  endl;
	}
	return output;
}