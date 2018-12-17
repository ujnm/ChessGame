#pragma once
#include "CAPiece.h"
class CKing :public CAPiece
{
public:
	CKing(char cColor);
	~CKing();
private:
	virtual char GetPiece();
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

