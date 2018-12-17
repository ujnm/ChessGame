#pragma once
#include <iostream>
using namespace std;
#include "CAPiece.h"
class CBishop : public CAPiece
{
public:
	CBishop(char cColor);
	~CBishop();
private:
	virtual char GetPiece();
	virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

