#ifndef CHESSPLAYER_H
#define CHESSPLAYER_H

#include <string>

#include "Player.h"
#include "ChessPiece.h"

class ChessPlayer: public Player
{

public:

	ChessPlayer(std::string name, PieceColor color);
	
	virtual ~ChessPlayer();

	virtual void initializePiecesList();

protected:

	bool m_isChess;
	bool m_isMatt;
	bool m_isStalemate;
	bool m_isCastling;
	bool m_hasCastled;
	
};

#endif
