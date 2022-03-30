#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <typeinfo>

#include "ChessGame.h"
#include "ChessPlayer.h"

using namespace std;

ChessGame::ChessGame():Game(8,8)
{
	m_player1 = new ChessPlayer("White player",WHITE);
	m_player2 = new ChessPlayer("Black player",BLACK);
	m_currentPlayer = m_player1;
	m_nextPlayer = m_player2;
	m_endOfMatch = false;
	m_indexMoves = 0;
}

ChessGame::~ChessGame()
{
	delete m_player1;
	delete m_player2;
}

void ChessGame::print(std::ostream& stream) const
{
	m_board.print(m_currentPlayer->getColor()==BLACK);
	stream << m_recordedMoves;
}

bool ChessGame::testEndOfMatch() const
{
	return false;
}

bool ChessGame::nextMove()
{
	string command = m_currentPlayer->getCommand();
	int i,j,k,l;

	i = rankIndexToInt((command)[1]);
	j = fileIndexToInt((command)[0]);
	k = rankIndexToInt((command)[4]);
	l = fileIndexToInt((command)[3]);

	if(!canMove(i,j,k,l))
	{
		return false;
	}

	makeMove(i,j,k,l);
	updateRecordedMoves();
	return true;
}

void ChessGame::makeMove(int i, int j, int k, int l)
{
	Piece* piece = m_board.removePiece(i,j);
	if(m_board.isOccupied(k,l))
	{
		m_board.removePiece(k,l);
	}
	m_board.addPiece(k,l,piece);

}

bool ChessGame::canMove(int i, int j, int k, int l) const
{
	if(!m_board.isOccupied(i,j))
	{
		cout << "This square is empty" << endl;
		return false;
	}

	Piece* piece = m_board.getPiece(i,j);
	if(piece->getColor() != m_currentPlayer->getColor())
	{
		cout << "This is an adverssary piece" << endl;
		return false;
	}
	if(m_board.isOccupied(k,l) && m_board.getPiece(k,l)->getColor() == m_currentPlayer->getColor())
	{
		cout << "impossible to capture its own piece" << endl;
		return false;
	}
	if(!m_board.getPiece(i,j)->isAllowedMove(m_board,i,j,k,l))
	{
		cout << "This move is not allowed for this piece" << endl;
		return false;
	}
	return true;
}

bool ChessGame::testCommand(string command)
{
	string rankIndex("12345678");
	string fileIndex("abcdefghABCDEFGH");

	if( command.size() >= 5 && fileIndex.find(command[0]) != string::npos && rankIndex.find(command[1]) != string::npos
		&& command[2]==' ' && fileIndex.find(command[3]) != string::npos && rankIndex.find(command[4]) != string::npos )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ChessGame::updateRecordedMoves()
{
	stringstream ss;
	if(m_currentPlayer->getColor()==WHITE)
	{
		m_indexMoves++;
		ss << m_indexMoves << ". ";
		m_recordedMoves += ss.str();

	}
	m_recordedMoves += tolower(m_currentPlayer->getCommand()[0]);
	m_recordedMoves += tolower(m_currentPlayer->getCommand()[1]);
	m_recordedMoves += tolower(m_currentPlayer->getCommand()[3]);
	m_recordedMoves += tolower(m_currentPlayer->getCommand()[4]);
	m_recordedMoves += " ";
}




