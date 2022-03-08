#ifndef PIECE_H
#define PIECE_H

#include <fstream>


class Piece
{

public:

	Piece();

	virtual ~Piece();

	int getRaw() const;

	int getColumn() const;

	void setRaw(int raw);

	void setColumn(int column);

	virtual bool isAllowedMove(int i, int j) const = 0;

	virtual void print(std::ostream& stream) const = 0;

protected:

	int m_raw;
	int m_column;
};


#endif
