#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"

class Square
{

public:

	Square();

	bool isOccupied() const;

	Piece* getPiece() const;

	void addPiece(Piece* piece);

	Piece* removePiece();

protected:

	Piece* m_piece;

};


#endif
