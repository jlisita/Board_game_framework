#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game
{

public:

	Game(int i, int j);

	virtual ~Game();

	void print() const;

	int match();

	int turn();

	void rotatePlayer();

	virtual int initialize() = 0;

	virtual bool testEndOfMatch() const = 0;

	virtual bool nextMove() = 0;

	virtual bool getCommand() = 0;


protected:

	Board m_board;
	Player* m_player1;
	Player* m_player2;
	bool m_endOfMatch;
	Player* m_currentPlayer;
	Player* m_nextPlayer;
};


#endif
