#pragma once
#include "CAPiece.h"
class CKnight : public CAPiece
{
public:
	CKnight(char cColor);
	~CKnight();
private:
	virtual char GetPiece();
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

