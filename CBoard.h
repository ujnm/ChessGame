#pragma once
#include "CAPiece.h"
class CBoard
{
public:
	CBoard();
	~CBoard();
	void Print();//interface
	bool IsInCheck(char cColor);
	bool CanMove(char cColor);
	CAPiece* Board[8][8];
};

