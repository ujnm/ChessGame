#include "stdafx.h"
#include "CQueen.h"
#include "CAPiece.h"


CQueen::CQueen(char cColor) : CAPiece(cColor) {}
CQueen::~CQueen() {}

char CQueen::GetPiece() 
{
	return 'Q';
}
bool CQueen::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) 
	{
		if (iSrcRow == iDestRow) 
		{
			// Make sure that all invervening squares are empty
			int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
			for (int iCheckCol = iSrcCol + iColOffset; iCheckCol != iDestCol; iCheckCol = iCheckCol + iColOffset) 
			{
				if (qpaaBoard[iSrcRow][iCheckCol] != 0)
				{
					return false;
				}
			}
			return true;
		}
		else if (iDestCol == iSrcCol) 
		{
			// Make sure that all invervening squares are empty
			int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
			for (int iCheckRow = iSrcRow + iRowOffset; iCheckRow != iDestRow; iCheckRow = iCheckRow + iRowOffset) 
			{
				if (qpaaBoard[iCheckRow][iSrcCol] != 0) 
				{
					return false;
				}
			}
			return true;
		}
		else if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) 
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
