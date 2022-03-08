#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include "Square.h"

class Board
{

public:

	Board(int nbRaw, int nbColumn );

	~Board();

	Square getSquare(int i, int j) const;

	void print(bool reversed) const;


protected:

	int m_nbRaw;
	int m_nbColumn;
	Square **m_squares;

};

#endif
