#include "stdafx.h"
#include "CKnight.h"
#include "CAPiece.h"

CKnight::CKnight(char cColor) : CAPiece(cColor) {}
CKnight::~CKnight() {}
char CKnight::GetPiece() 
{
		return 'N';
}
bool CKnight::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) 
{
		// Destination square is unoccupied or occupied by opposite color
		if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) 
		{
			if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2)) 
			{
				return true;
			}
		}
		if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2)) 
		{
			if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1)) 
			{
				return true;
			}
		}
		return false;
}
