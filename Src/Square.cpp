#include <iostream>
#include <string>
#include "Square.h"



Square::Square()
{
	m_piece = NULL;
}

bool Square::isOccupied() const
{

	return m_piece != NULL;
}

Piece* Square::getPiece() const
{
	return m_piece;
}

void Square::addPiece(Piece* piece)
{
	if(!isOccupied())
	m_piece = piece;
}

Piece* Square::removePiece()
{
	Piece* piece = m_piece;
	m_piece = NULL;
	return piece;
}



