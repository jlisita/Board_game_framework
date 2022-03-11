#include <iostream>
#include <string>

#include "Player.h"

using namespace std;


Player::Player(std::string name, PieceColor color): m_name(name), m_color(color)
{
}

Player::~Player()
{
}

std::string Player::getName() const
{
	return m_name;
}

PieceColor Player::getColor() const
{
	return m_color;
}

void Player::addPiece(std::string name, Piece* piece)
{	
	m_piecesList[name] = piece;
}

void Player::placeOnBoard(Board* board)
{
}

bool Player::enterCommand()
{
	return true;
}
