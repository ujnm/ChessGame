#include "stdafx.h"
#include "CPawn.h"
#include "CAPiece.h"


CPawn::CPawn(char cColor) : CAPiece(cColor) {}
CPawn::~CPawn() {}

char CPawn::GetPiece()
{
	return 'P';
}
bool CPawn::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) {
		CAPiece* qpDest = qpaaBoard[iDestRow][iDestCol];
		if (qpDest == 0) {
			// Destination square is unoccupied
			if (iSrcCol == iDestCol) {
				if (GetColor() == 'W') {
					if (iDestRow == iSrcRow + 1) {
						return true;
					}
				}
				else {
					if (iDestRow == iSrcRow - 1) {
						return true;
					}
				}
			}
		}
		else {
			// Dest holds piece of opposite color
			if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) {
				if (GetColor() == 'W') {
					if (iDestRow == iSrcRow + 1) {
						return true;
					}
				}
				else {
					if (iDestRow == iSrcRow - 1) {
						return true;
					}
				}
			}
		}
		return false;
}