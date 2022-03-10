#ifndef PIECE_H
#define PIECE_H

#include <fstream>


enum PieceColor
{
	WHITE, BLACK
};

class Piece
{

public:

	Piece(int initialRaw, int initialColumn, PieceColor color);

	virtual ~Piece();

	int getRaw() const;

	int getColumn() const;

	void setRaw(int raw);

	void setColumn(int column);

	PieceColor getColor() const;

	virtual bool isAllowedMove(int i, int j) const = 0;

	virtual void print(std::ostream& stream) const = 0;

protected:

	int m_raw;
	int m_column;
	PieceColor m_color;
};

std::ostream& operator<<(std::ostream& stream, Piece& piece);


#endif
