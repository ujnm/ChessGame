#include "stdafx.h"
#include "CAPiece.h"


CAPiece::CAPiece(char cColor)
{
	mcColor = cColor;
}
CAPiece::~CAPiece() {}

char CAPiece::GetColor() 
{
	return mcColor;
}
bool CAPiece::IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) {
	CAPiece* qpDest = qpaaBoard[iDestRow][iDestCol];
	if ((qpDest == 0) || (mcColor != qpDest->GetColor())) {
		return AreSquaresLegal(iSrcRow, iSrcCol, iDestRow, iDestCol, qpaaBoard);
	}
	return false;
}
