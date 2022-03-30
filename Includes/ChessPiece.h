#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Piece.h"

class King: public Piece
{

public:

	King(int raw, int column, PieceColor color);

	virtual ~King();

	virtual bool isAllowedMove(Board const& board, int i, int j, int k, int l) const;

	virtual void print(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, King& piece); 

class Queen: public Piece
{

public:

	Queen(int raw, int column, PieceColor color);

	virtual ~Queen();

	virtual bool isAllowedMove(Board const& board, int i, int j, int k, int l) const;

	virtual void print(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, Queen& piece); 

class Bishop: public Piece
{

public:

	Bishop(int raw, int column, PieceColor color);

	virtual ~Bishop();

	virtual bool isAllowedMove(Board const& board, int i, int j, int k, int l) const;

	virtual void print(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, Bishop& piece); 

class Knight: public Piece
{

public:

	Knight(int raw, int column, PieceColor color);

	virtual ~Knight();

	virtual bool isAllowedMove(Board const& board, int i, int j, int k, int l) const;

	virtual void print(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, Knight& piece); 

class Rook: public Piece
{

public:

	Rook(int raw, int column, PieceColor color);

	virtual ~Rook();

	virtual bool isAllowedMove(Board const& board, int i, int j, int k, int l) const;

	virtual void print(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, Rook& piece); 

class Pawn: public Piece
{

public:

	Pawn(int raw, int column, PieceColor color);

	virtual ~Pawn();

	virtual bool isAllowedMove(Board const& board, int i, int j, int k, int l) const;

	virtual void print(std::ostream& stream) const;

};

std::ostream& operator<<(std::ostream& stream, Pawn& piece); 



#endif
