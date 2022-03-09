#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"

class Square
{

public:

	Square();

	bool isOccupied();

	Piece* getPiece();

protected:

	Piece* m_piece;

};


#endif
