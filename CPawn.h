#pragma once
#include "CAPiece.h"
class CPawn : public CAPiece
{
public:
	CPawn(char cColor);
	~CPawn();
private:
	virtual char GetPiece();
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

