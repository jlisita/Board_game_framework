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

int Piece::getLastRaw() const
{
	return m_historyRaw.back();
}

int Piece::getLastColumn() const
{
	return m_historyColumn.back();
}

void Piece::updatePosition(int i, int j)
{
	m_historyRaw.push_back(m_raw);
	m_historyColumn.push_back(m_column);
	m_raw = i;
	m_column = j;
}

std::ostream& operator<<(std::ostream& stream, Piece& piece)
{
	piece.print(stream);
	return stream;
}

bool isForward(int i, int j)
{
	return	(i>0) && (j==0);
}

bool isBack(int i, int j)
{
	return (i<0) && (j==0);
}

bool isLeft(int i, int j)
{
	return (i==0) && (j<0);
}

bool isRight(int i, int j)
{
	return (i==0) && (j>0);
}

bool isForwardRight(int i, int j)
{
	return (i>0) && (j>0) && (i==j);
}

bool isForwardLeft(int i, int j)
{
	return (i>0) && (j<0) && (i==-j);
}

bool isBackRight(int i, int j)
{
	return (i<0) && (j>0) && (i==-j);
}

bool isBackLeft(int i, int j)
{
	return (i<0) && (j<0) && (i==j);
}

bool isDiagonal(int i, int j)
{
	return isForwardRight(i,j) && isForwardLeft(i,j) && isBackRight(i,j) && isBackLeft(i,j);
}

bool isLateral(int i, int j)
{
	return isForward(i,j) && isBack(i,j) && isLeft(i,j) && isBack(i,j);
}

bool isOneSquare(int i, int j)
{
	return  ( ((i==1) || (i==-1))  && ( (j==0) || (j==1) || (j==-1) ) )  ||  ( (i==0) && ((j==1) || (j==-1)) );
}



