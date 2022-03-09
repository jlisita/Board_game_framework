#include <iostream>
#include <string>
#include "Square.h"



Square::Square()
{
	m_piece = NULL;
}

bool Square::isOccupied()
{

	return m_piece != NULL;
}


Piece* Square::getPiece()
{
	return m_piece;
}



