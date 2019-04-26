#include "pch.h"
#include "Board.h"
#include <string>
using namespace std;


Board::Board(){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			CBoard[i][j] = { "empty" };
		}
	}
}


Board::~Board()
{
}

ostream &operator<< (ostream &output, const Board &CB) {
	output << "_________________________________________________________________________" << endl << endl;
	for (int i = 0; i < 8; i++) {		//for iterating rows
		for (int j = 0; j < 8; j++) {	//for iterating columns
			output << "|	" << CB.CBoard[i][j] << "	";
		}
		output << endl << endl << "|________|________|________|________|________|________|________|________|" << endl << endl;
	}
	return output;
}