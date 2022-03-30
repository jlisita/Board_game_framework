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

bool Board::existSquare(int raw, int column) const
{
	return raw >= 0 && raw < m_nbRaw && column >= 0  && column < m_nbColumn;

}

bool Board::isOccupied(int raw, int column) const
{

	return m_squares[raw][column].isOccupied();
}

Piece* Board::getPiece(int raw, int column) const
{
	return m_squares[raw][column].getPiece();
}

void Board::addPiece(int raw, int column, Piece* piece)
{
	m_squares[raw][column].addPiece(piece);
}

Piece* Board::removePiece(int raw, int column)
{
	return m_squares[raw][column].removePiece();
}

void Board::update() 
{
	for(int i=0;i<m_nbRaw;i++)
	{
		for(int j=0;j<m_nbColumn;j++)
		{
			if(m_squares[i][j].isOccupied())
			{
				m_squares[i][j].getPiece()->updatePosition(i,j);
			}
		}
	}
}


bool Board::isEmptyBetween(int i, int j, int k, int l) const
{
	int n,m;

	if(k-i==0) // horizontal move
	{
		if(l-j>0) // from left to right
		{
			for(n=j+1;n<l;n++)
			{
				if(isOccupied(i,n))
					return false;
			}
		}
		else // from right to left
		{
			for(n=j-1;n>l;n--)
			{
				if(isOccupied(i,n))
					return false;
			}
		}
	}
	else if(l-j==0) // vertical move
	{
		if(k-i>0) // from down to up
		{
			for(m=i+1;m<k;m++)
			{
				if(isOccupied(m,j))
					return false;	
			}
		}
		else // from up to down
		{
			for(m=i-1;m>k;m--)
			{
				if(isOccupied(m,j))
					return false;			
			}
		}
	}
	else // diagonal move
	{
		if(k-i>0 && l-j>0) // from down/left to up/right
		{
			for(n=1;n<k-i;n++)
			{
				if(isOccupied(i+n,j+n))
					return false;
			}
		}
		else if(k-i>0 && l-j<0) // from down/right to up/left
		{
			for(n=1;n<k-i;n++)
			{
				if(isOccupied(i+n,j-n))
					return false;
			}
		}
		else if(k-i<0 && l-j>0 ) // from up/left to down/right
		{
			for(n=1;n<abs(k-i);n++)
			{
				if(isOccupied(i-n,j+n))
					return false;
			}
		}
		else if(k-i<0 && l-j<0) // from up/right to down/left
		{
			for(n=1;n<abs(k-i);n++)
			{
				if(isOccupied(i-n,j-n))
					return false;
			}
		}
	}
	return true;
}

bool Board::isCapturingPiece(int i, int j, int k, int l) const
{
	if(isOccupied(k,l) && (getPiece(i,j)->getColor() != getPiece(k,l)->getColor()))
	{
		return true;
	}
	return false;
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
					cout << *(m_squares[i][j].getPiece());
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
					cout << *(m_squares[i][j].getPiece());
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

int rankIndexToInt(char c)
{
	int i;
	switch(c)
	{
		case '1':
			i=0;
			break;
		case '2':
			i=1;
			break;
		case '3':
			i=2;
			break;
		case '4':
			i=3;
			break;
		case '5':
			i=4;
			break;
		case '6':
			i=5;
			break;
		case '7':
			i=6;
			break;
		case '8':
			i=7;
			break;
		default:
			i = -1;
	}
	return i;
}

// convert file name to array line index
int fileIndexToInt(char c)
{
	int i;
	switch(c)
	{
		case 'a': case 'A':
			i=0;
			break;
		case 'b': case 'B':
			i=1;
			break;
		case 'c': case 'C':
			i=2;
			break;
		case 'd': case 'D':
			i=3;
			break;
		case 'e': case 'E':
			i=4;
			break;
		case 'f': case 'F':
			i=5;
			break;
		case 'g': case 'G':
			i=6;
			break;
		case 'h': case 'H':
			i=7;
			break;
		default:
			i = -1;
	}
	return i;
}

