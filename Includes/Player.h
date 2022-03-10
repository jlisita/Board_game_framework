#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <map>

#include "Piece.h"
#include "Board.h"


class Player
{

public:

	Player(std::string name);

	~Player();

	std::string getName() const;

	void addPiece(std::string name, Piece* piece);

	void placeOnBoard(Board* board);

protected:

	std::string m_name;
	std::map<std::string,Piece*> m_pieces;
};

#endif
