#include "stdafx.h"
#include "CBishop.h"
#include <iostream>
using namespace std;
CBishop::CBishop(char cColor) : CAPiece(cColor) {}
CBishop::~CBishop() {}


 char CBishop::GetPiece() 

{
	return 'B';
}
bool CBishop::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) 
{
	if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) 
	{
		// Make sure that all invervening squares are empty
		int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
		int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
		int iCheckRow;
		int iCheckCol;
		for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
			iCheckRow != iDestRow;
			iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
		{
			if (qpaaBoard[iCheckRow][iCheckCol] != 0) 
			{
				return false;
			}
		}
		return true;
	}
	return false;
}