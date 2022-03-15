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

	Player(std::string name, PieceColor color);

	virtual ~Player();

	std::string getName() const;

	PieceColor getColor() const;

	std::string getCommand() const;

	bool isAbandoning() const;

	void addPiece(std::string name, Piece* piece);

	void placeOnBoard(Board* board);

	void enterCommand();

	virtual void initializePiecesList() = 0;

protected:

	std::string m_name;
	PieceColor m_color;
	std::map<std::string,Piece*> m_piecesList;
	std::string m_command;
	bool m_abandonment;
};

#endif
