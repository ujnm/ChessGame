#pragma once
#include "CAPiece.h"
class CRook : public CAPiece
{
public:
	CRook(char cColor);
	~CRook();
private:
	virtual char GetPiece();
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

