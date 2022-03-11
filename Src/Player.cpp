#include <iostream>
#include <string>
#include <map>

#include "Player.h"

using namespace std;


Player::Player(std::string name, PieceColor color): m_name(name), m_color(color)
{
}

Player::~Player()
{
	map<string,Piece*>::iterator it;
	for(it = m_piecesList.begin(); it != m_piecesList.end(); it++) 
	{
		delete it->second;
	}
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
	map<string,Piece*>::iterator it; 
	for(it = m_piecesList.begin(); it != m_piecesList.end(); it++)
	{
		board->addPiece(it->second->getRaw(),it->second->getColumn(), it->second);
	}
}

bool Player::enterCommand()
{
	cout << m_name << ": enter your move:";
	cin >> m_command;
	return testCommand();
}
