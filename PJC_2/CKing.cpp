#include "stdafx.h"
#include "CKing.h"
#include "CAPiece.h"

CKing::CKing(char cColor) : CAPiece(cColor) {}
CKing::~CKing() {}
 char CKing::GetPiece()
{
	return 'K';
}
bool CKing::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
{
		int iRowDelta = iDestRow - iSrcRow;
		int iColDelta = iDestCol - iSrcCol;
		if (((iRowDelta >= -1) && (iRowDelta <= 1)) && ((iColDelta >= -1) && (iColDelta <= 1)))
		{
			return true;
		}
		else
		return false;
}