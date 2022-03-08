#include <iostream>
#include <string>
#include <vector>

#include "Board.h"

using namespace std;


Board::Board(int nbRaw, int nbColumn ): m_nbRaw(nbRaw), m_nbColumn(nbColumn)
{
	m_squares = new Square*[m_nbRaw];
	if(m_squares == NULL)
	{
		exit(0);
	}
	for(int i=0; i<m_nbRaw; i++)
	{
		m_squares[i]= new Square[m_nbColumn];
		if(m_squares[i]== NULL)
		{
			exit(0);
		}
	}
}

Board::~Board()
{
	for(int i=0; i<m_nbRaw; i++)
	{
		delete m_squares[i]; 
	}
	delete m_squares;
}

Square Board::getSquare(int i, int j) const
{
	return m_squares[i][j];
}

void Board::print(bool reversed) const
{
	vector<int> rankIndex;
	for(int i(0); i < m_nbRaw; i++)
	{
		rankIndex.push_back(i+1);
	}
	vector<char> filesIndex; 
	for(int j(0); j < m_nbColumn; j++)
	{
		filesIndex.push_back(j+97);
	}

	cout << endl << "   |";
	for(int j(0);j<m_nbColumn;j++)
	{
		cout << "----|";
	}
	cout << endl;

	if(!reversed)
	{

		for(int i(m_nbRaw-1); i >= 0 ; i--)
		{
			cout << rankIndex[i];
			if(rankIndex[i]>=10)
			{
				cout << " | ";
			}
			else
			{
				cout << "  | ";
			}
			for(int j(0); j < m_nbColumn; j++)
			{
				if(m_squares[i][j].isOccupied()==true)
				{
					m_squares[i][j].getPiece();
					cout << "  | ";
				}
				else
				{
					cout << "   | ";
				}
			}
			cout << endl << "   |";
			for(int j(0); j < m_nbColumn; j++)
			{
				cout << "----|";
			}
			cout << endl;

		}
		cout << "     ";
		for(int j(0); j<m_nbColumn; j++)
		{
			cout << filesIndex[j] <<  "    ";
		}
		cout << endl;
	}
	else
	{
		for(int i(0); i < m_nbRaw ; i++)
		{
			cout << rankIndex[i];
			if(rankIndex[i]>=10)
			{
				cout << " | ";
			}
			else
			{
				cout << "  | ";
			}
			for(int j(m_nbColumn-1); j >=0 ; j--)
			{
				if(m_squares[i][j].isOccupied()==true)
				{
					m_squares[i][j].getPiece();
					cout << "  | ";
				}
				else
				{
					cout << "   | ";
				}
			}
			cout << endl << "   |";
			for(int j(0); j < m_nbColumn; j++)
			{
				cout << "----|";
			}
			cout << endl;

		}
		cout << "     ";
		for(int j(m_nbColumn-1); j>=0; j--)
		{
			cout << filesIndex[j] <<  "    ";
		}
		cout << endl;	
	}

}

