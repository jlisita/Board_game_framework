#include <iostream>
#include <string>

#include "Piece.h"

using namespace std;

Piece::Piece(int initialRaw, int initialColumn, PieceColor color): 
m_raw(initialRaw), m_column(initialColumn), m_color(color)
{
}

Piece::~Piece()
{
}

int Piece::getRaw() const
{
	return m_raw;
}

int Piece::getColumn() const
{
	return m_column;
}

void Piece::setRaw(int raw) 
{
	m_raw = raw;
}

void Piece::setColumn(int column)
{
	m_column = column;
}

PieceColor Piece::getColor() const
{
	return m_color;
}

std::ostream& operator<<(std::ostream& stream, Piece& piece)
{
	piece.print(stream);
	return stream;
}



