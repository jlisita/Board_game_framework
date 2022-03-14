#include <iostream>
#include <string>

#include "ChessGame.h"
#include "ChessPlayer.h"

using namespace std;

ChessGame::ChessGame():Game(8,8)
{
	m_player1 = new ChessPlayer("White_player",WHITE);
	m_player2 = new ChessPlayer("Black_player",BLACK);
	m_currentPlayer = m_player1;
	m_nextPlayer = m_player2;
	m_endOfMatch = false;
}

ChessGame::~ChessGame()
{
	delete m_player1;
	delete m_player2;
}

void ChessGame::print(std::ostream& stream) const
{
	m_board.print(m_currentPlayer->getColor()==BLACK);
}

bool ChessGame::testEndOfMatch() const
{
	return true;
}

bool ChessGame::nextMove()
{
	return true;
}

void ChessGame::makeMove()
{
}

bool ChessGame::canMove(int i, int j, int k, int l) const
{
	if(!m_board.isOccupied(i,j))
	{
		return false;
	}
	Piece* piece = m_board.getPiece(i,j);
	if(piece->getColor() != m_currentPlayer->getColor())
	{
		return false;
	}
	if(!m_board.isEmptyBetween(i,j,k,l))
	{
		return false;
	}
	if(m_board.isOccupied(k,l) && m_board.getPiece(k,l)->getColor() == m_currentPlayer->getColor())
	{
		return false;
	}
	if(m_board.getPiece(i,j)->isAllowedMove(k-i,l-j))
	{
		return false;
	}
	return true;
}


