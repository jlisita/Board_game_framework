#include <iostream>
#include <string>

#include "Piece.h"

using namespace std;

Piece::Piece(int initialRaw, int initialColumn): 
m_raw(initialRaw), m_column(initialColumn)
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



