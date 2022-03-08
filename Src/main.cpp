#include <iostream>
#include <string>
#include <vector>
#include "main.h"
#include "Board.h"


using namespace std;

int main()
{
	Board chessBoard(8,8);
	chessBoard.print(true);

	Board goban(19,19);
	goban.print(false);

	return 0;
}
