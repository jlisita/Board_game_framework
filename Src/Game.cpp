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

	initialize();
	
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
			m_currentPlayer->enterCommand();
			validCommand = testCommand(m_currentPlayer->getCommand());

			if(!validCommand)
			{
				cout << "invalid command" << endl;
			}

		}while(!validCommand && !m_currentPlayer->isAbandoning());

		if(m_currentPlayer->isAbandoning())
		{
			return 0;
		}
		else
		{
			validMove = nextMove();
		}


	}while(!validMove);

	m_board.update();

	return 0;
}

void Game::rotatePlayer()
{
	Player* tmp(m_currentPlayer);
	m_currentPlayer = m_nextPlayer;
	m_nextPlayer = tmp;
}


void Game::initialize()
{
	m_player1->initializePiecesList();
	m_player2->initializePiecesList();
	m_player1->placeOnBoard(&m_board);
	m_player2->placeOnBoard(&m_board);
}

std::ostream& operator<<(std::ostream& stream, Game& game)
{
	game.print(stream);
	return stream;
}


