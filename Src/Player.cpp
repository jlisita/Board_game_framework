#include <iostream>
#include <string>

#include "Player.h"

using namespace std;


Player::Player(std::string name): m_name(name)
{
}

Player::~Player()
{
}

std::string Player::getName() const
{
	return m_name;
}

void Player::addPiece(std::string name, Piece* piece)
{	
}

void Player::placeOnBoard(Board* board)
{
}
