#pragma once
#include "CBoard.h"


class CGame
{
public:
	CGame(char = 'W');
	~CGame();

	void Start();
	void GetNextMove(CAPiece* qpaaBoard[8][8]);
		void AlternateTurn();
		bool IsGameOver();
private:
	CBoard mqGameBoard;
	char PlayerTurn;
};

