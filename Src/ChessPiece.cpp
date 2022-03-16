#include <iostream>
#include <string>

#include "ChessPiece.h"

using namespace std;

King::King(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

King::~King()
{
}

bool King::isAllowedMove(int i, int j) const
{
	 return isOneSquare(i,j);
}

void King::print(std::ostream& stream) const
{
	string unicode = (m_color == WHITE) ? "\u2654" : "\u265A";
	stream << unicode;
}

std::ostream& operator<<(std::ostream& stream, King& piece)
{
	piece.print(stream);
	return stream;
}


Queen::Queen(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

Queen::~Queen()
{
}

bool Queen::isAllowedMove(int i, int j) const
{
	 return isDiagonal(i,j) || isLateral(i,j);
}

void Queen::print(std::ostream& stream) const
{

	string unicode = (m_color == WHITE) ? "\u2655" : "\u265B";
	stream << unicode;
}

std::ostream& operator<<(std::ostream& stream, Queen& piece)
{
	piece.print(stream);
	return stream;
}

Bishop::Bishop(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

Bishop::~Bishop()
{
}

bool Bishop::isAllowedMove(int i, int j) const
{
	 return isDiagonal(i,j);
}

void Bishop::print(std::ostream& stream) const
{

	string unicode = (m_color == WHITE) ? "\u2657" : "\u265D";
	stream << unicode;
}

std::ostream& operator<<(std::ostream& stream, Bishop& piece)
{
	piece.print(stream);
	return stream;
}

Knight::Knight(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

Knight::~Knight()
{
}

bool Knight::isAllowedMove(int i, int j) const
{
	return ((i==2) && ((j==1) || (j==-1))) || ( (i==-2) && ((j==1) || (j==-1))) || ((i==1) && ((j==2) || (j==-2))) || ((i==-1) && ((j==2) || (j==-2))) ;
}

void Knight::print(std::ostream& stream) const
{

	string unicode = (m_color == WHITE) ? "\u2658" : "\u265E";
	stream << unicode;
}

std::ostream& operator<<(std::ostream& stream, Knight& piece)
{
	piece.print(stream);
	return stream;
}

Rook::Rook(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

Rook::~Rook()
{
}

bool Rook::isAllowedMove(int i, int j) const
{
	 return isLateral(i,j);
}

void Rook::print(std::ostream& stream) const
{

	string unicode = (m_color == WHITE) ? "\u2656" : "\u265C";
	stream << unicode;
}

std::ostream& operator<<(std::ostream& stream, Rook& piece)
{
	piece.print(stream);
	return stream;
}

Pawn::Pawn(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

Pawn::~Pawn()
{
}

bool Pawn::isAllowedMove(int i, int j) const
{
	if(getColor() == WHITE)
	{
		return ( (i==1) || ((i==2) && (!hasMoved()) )) && (j==0);
	}
	else
	{
		return ( (i==-1) || ((i==-2) && (!hasMoved()) )) && (j==0);
	}
}

void Pawn::print(std::ostream& stream) const
{

	string unicode = (m_color == WHITE) ? "\u2659" : "\u265F";
	stream << unicode;
}

std::ostream& operator<<(std::ostream& stream, Pawn& piece)
{
	piece.print(stream);
	return stream;
}







