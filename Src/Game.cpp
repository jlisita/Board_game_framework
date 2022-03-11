#include <iostream>
#include <string>

#include "Game.h"

using namespace std;

Game::Game(int i, int j): m_board(i,j)
{
}

Game::~Game()
{
}

int Game::match()
{
	m_player1->initializePiecesList();
	m_player2->initializePiecesList();

	m_player1->placeOnBoard(&m_board);
	m_player2->placeOnBoard(&m_board);
	
	do
	{
		cout << *this << endl;
		
		turn();

		m_endOfMatch = testEndOfMatch();

		if(!m_endOfMatch)
		{
			rotatePlayer();
		}

	}while(!m_endOfMatch);

	return 0;
}

int Game::turn()
{
	bool validMove(false);
	bool validCommand(false); 
	do
	{
		do
		{
			validCommand = m_currentPlayer->enterCommand();

		}while(!validCommand);


		validMove = nextMove();


	}while(!validMove);

	updateGame();

	return 0;
}

void Game::rotatePlayer()
{
	Player* tmp(m_currentPlayer);
	m_currentPlayer = m_nextPlayer;
	m_nextPlayer = tmp;
}

std::ostream& operator<<(std::ostream& stream, Game& game)
{
	game.print(stream);
	return stream;
}


