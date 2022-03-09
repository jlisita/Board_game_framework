#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include "Square.h"
#include "Piece.h"

class Board
{

public:

	Board(int nbRaw, int nbColumn );

	~Board();

	bool existSquare(int raw, int column) const;

	Square* getSquare(int raw, int column) const;

	void print(bool reversed) const;


protected:

	int m_nbRaw;
	int m_nbColumn;
	Square **m_squares;

};

#endif
