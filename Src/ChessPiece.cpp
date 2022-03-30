#include <iostream>
#include <string>

#include "ChessPiece.h"
#include "Board.h"

using namespace std;

King::King(int raw, int column, PieceColor color): Piece(raw, column, color)
{
}

King::~King()
{
}

bool King::isAllowedMove(Board const& board, int i, int j, int k, int l) const
{
	 return isOneSquare(k-i,l-j);
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

bool Queen::isAllowedMove(Board const& board, int i, int j, int k, int l) const
{
	if(!board.isEmptyBetween(i,j,k,l))
	{
		return false;
	}

	return isDiagonal(k-i,l-j) || isLateral(k-i,l-j);
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

bool Bishop::isAllowedMove(Board const& board, int i, int j, int k, int l) const
{
	if(!board.isEmptyBetween(i,j,k,l))
	{
		return false;
	}
	return isDiagonal(k-i,l-j);
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

bool Knight::isAllowedMove(Board const& board, int i, int j, int k, int l) const
{
	return ((k-i==2) && ((l-j==1) || (l-j==-1))) || ( (k-i==-2) && ((l-j==1) || (l-j==-1))) 
	|| ((k-i==1) && ((l-j==2) || (l-j==-2))) || ((k-i==-1) && ((l-j==2) || (l-j==-2))) ;
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

bool Rook::isAllowedMove(Board const& board, int i, int j, int k, int l) const
{
	if(!board.isEmptyBetween(i,j,k,l))
	{
		return false;
	}
	return isLateral(k-i,l-j);
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

bool Pawn::isAllowedMove(Board const& board, int i, int j, int k, int l) const
{
	if(!board.isEmptyBetween(i,j,k,l))
	{
		return false;
	}
	if(!board.isCapturingPiece(i,j,k,l))
	{
		if(getColor() == WHITE)
		{
			return ( (k-i==1) || ((k-i==2) && (!hasMoved()) )) && (l-j==0);
		}
		else
		{
			return ( (k-i==-1) || ((k-i==-2) && (!hasMoved()) )) && (l-j==0);
		}
	}
	else
	{
		if(getColor() == WHITE)
		{
			return (k-i==1) && ((l-j==1) || (l-j==-1)) ;
		}
		else
		{
			return (k-i==-1) && ((l-j==1) || (l-j==-1)) ;
		}
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







