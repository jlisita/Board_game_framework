#ifndef GAME_H
#define GAME_H

#include <fstream>

#include "Player.h"
#include "Board.h"

class Game
{

public:

	Game(int i, int j);

	virtual ~Game();

	virtual void print(std::ostream& stream) const = 0;

	int match();

	int turn();

	void rotatePlayer();

	virtual bool testEndOfMatch() const = 0;

	virtual bool nextMove() = 0;

	virtual int updateGame() = 0;


protected:

	Board m_board;
	Player* m_player1;
	Player* m_player2;
	bool m_endOfMatch;
	Player* m_currentPlayer;
	Player* m_nextPlayer;
};


#endif

std::ostream& operator<<(std::ostream& stream, Game& game);
