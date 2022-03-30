#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include "Square.h"
#include "Piece.h"

class Board
{

public:

	Board(int nbRaw, int nbColumn );

	~Board();

	bool existSquare(int raw, int column) const;

	bool isOccupied(int raw, int column) const;

	Piece* getPiece(int raw, int column) const;

	void addPiece(int raw, int column, Piece* piece);

	Piece* removePiece(int raw, int column);

	void update();

	bool isEmptyBetween(int i, int j, int k, int l) const;

	bool isCapturingPiece(int i, int j, int k, int l) const;

	void print(bool reversed) const;


protected:

	int m_nbRaw;
	int m_nbColumn;
	Square **m_squares;

};

int rankIndexToInt(char c);
int fileIndexToInt(char c);

#endif
