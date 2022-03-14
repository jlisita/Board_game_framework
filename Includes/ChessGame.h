#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Game.h"

class ChessGame: public Game 
{
public:

	ChessGame();

	~ChessGame();

	virtual void print(std::ostream& stream) const;

	virtual bool testEndOfMatch() const;

	virtual bool nextMove();

	virtual void makeMove();

	virtual bool canMove(int i, int j, int k, int l) const;

private:

	std::string RecordedMoves;

};

#endif
