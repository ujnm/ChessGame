#pragma once
#include "CAPiece.h"
class CQueen : public CAPiece
{
public:
	CQueen(char cColor);
	~CQueen();
private:
	virtual char GetPiece();
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

