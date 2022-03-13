#ifndef PIECE_H
#define PIECE_H

#include <fstream>
#include <vector>


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

	int getLastRaw() const;

	int getLastColumn() const;

	PieceColor getColor() const;

	void updatePosition(int i, int j);

	virtual bool isAllowedMove(int i, int j) const = 0;

	virtual void print(std::ostream& stream) const = 0;


protected:

	int m_raw;
	int m_column;
	std::vector<int> m_historyRaw;
	std::vector<int> m_historyColumn;
	PieceColor m_color;
};

std::ostream& operator<<(std::ostream& stream, Piece& piece);

bool isForward(int i, int j);

bool isBack(int i, int j);

bool isLeft(int i, int j);

bool isRight(int i, int j);

bool isForwardRight(int i, int j);

bool isForwardLeft(int i, int j);

bool isBackRight(int i, int j);

bool isBackLeft(int i, int j);

bool isDiagonal(int i, int j);

bool isLateral(int i, int j);

bool isOneSquare(int i, int j);



#endif
