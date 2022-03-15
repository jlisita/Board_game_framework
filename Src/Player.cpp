#include <iostream>
#include <string>
#include <map>

#include "Player.h"

using namespace std;


Player::Player(std::string name, PieceColor color): m_name(name), m_color(color), m_abandonment(false)
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

std::string Player::getCommand() const
{
	return m_command;
}

bool Player::isAbandoning() const
{
	return m_abandonment;
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

void Player::enterCommand()
{
	cout << m_name << ": enter your move:";
	getline(cin, m_command);
	if(m_command == "abandon")
	{
		m_abandonment = true;
	}
}
