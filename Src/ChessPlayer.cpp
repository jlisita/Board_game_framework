#include <iostream>
#include <string>

#include "ChessPlayer.h"

using namespace std;

ChessPlayer::ChessPlayer(std::string name, PieceColor color): Player(name, color)
{
	m_isChess = false;
	m_isMatt = false;
	m_isStalemate = false;
	m_isCastling = false;
	m_hasCastled = false;
	m_abandonment = false;	
}

ChessPlayer::~ChessPlayer()
{
}

void ChessPlayer::initializePiecesList()
{
	int firstRank = (m_color == WHITE) ? 0 : 7;
	int secondRank = (m_color == WHITE) ? 1 : 6;

	m_piecesList["King"] = new King(firstRank,3,m_color);
	m_piecesList["Queen"] = new Queen(firstRank,4,m_color);
	m_piecesList["Bishop1"] = new Bishop(firstRank,2,m_color);
	m_piecesList["Bishop2"] = new Bishop(firstRank,5,m_color);
	m_piecesList["Knight1"] = new Knight(firstRank,1,m_color);
	m_piecesList["Knight2"] = new Knight(firstRank,6,m_color);
	m_piecesList["Rook1"] = new Rook(firstRank,0,m_color);
	m_piecesList["Rook2"] = new Rook(firstRank,7,m_color);
	m_piecesList["Pawn1"] = new Pawn(secondRank,0,m_color);
	m_piecesList["Pawn2"] = new Pawn(secondRank,1,m_color);
	m_piecesList["Pawn3"] = new Pawn(secondRank,2,m_color);
	m_piecesList["Pawn4"] = new Pawn(secondRank,3,m_color);
	m_piecesList["Pawn5"] = new Pawn(secondRank,4,m_color);
	m_piecesList["Pawn6"] = new Pawn(secondRank,5,m_color);
	m_piecesList["Pawn7"] = new Pawn(secondRank,6,m_color);
	m_piecesList["Pawn8"] = new Pawn(secondRank,7,m_color);
}

bool ChessPlayer::testCommand()
{
	string rankIndex("12345678");
	string fileIndex("abcdefghABCDEFGH");

	if("abandon" == m_command)
	{
		m_abandonment = true;
		return false;
	}
	if( m_command.size() >= 5 && fileIndex.find(m_command[0]) != string::npos && rankIndex.find(m_command[1]) != string::npos
		&& m_command[2]==' ' && fileIndex.find(m_command[3]) != string::npos && rankIndex.find(m_command[4]) != string::npos )
	{
		return true;
	}
	else
	{
		cout << "Commande invalide" << endl;
		return false;
	}
}

