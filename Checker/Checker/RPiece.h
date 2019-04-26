#pragma once
#include "Red.h"

class RPiece : public Red {

public:
	RPiece();
	~RPiece();

	bool move(int pos);
	bool jump(int pos);
	void makeKing();
};

