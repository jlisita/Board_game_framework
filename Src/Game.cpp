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

	return 0;
}

int Game::turn()
{

	return 0;
}

void Game::rotatePlayer()
{
}

std::ostream& operator<<(std::ostream& stream, Game& game)
{
	game.print(stream);
	return stream;
}


