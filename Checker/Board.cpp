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
