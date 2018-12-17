#include "stdafx.h"
#include "CBoard.h"
#include<iostream>
#include"CAPiece.h"
#include"CRook.h"
#include"CBishop.h"
#include"CKing.h"
#include"CKnight.h"	
#include"CPawn.h"
#include"CQueen.h"
using namespace std;


CBoard::CBoard() 
{
	for (int iRow = 0; iRow < 8; ++iRow) 
	{
		for (int iCol = 0; iCol < 8; ++iCol) 
		{
			Board[iRow][iCol] = 0;
		}
	}
	// Allocate and place black pieces
	for (int iCol = 0; iCol < 8; ++iCol) 
	{
		Board[6][iCol] = new CPawn('B');
	}
	Board[7][0] = new CRook('B');
	Board[7][1] = new CKnight('B');
	Board[7][2] = new CBishop('B');
	Board[7][3] = new CKing('B');
	Board[7][4] = new CQueen('B');
	Board[7][5] = new CBishop('B');
	Board[7][6] = new CKnight('B');
	Board[7][7] = new CRook('B');
	// Allocate and place white pieces
	for (int iCol = 0; iCol < 8; ++iCol) 
	{
		Board[1][iCol] = new CPawn('W');
	}
	Board[0][0] = new CRook('W');
	Board[0][1] = new CKnight('W');
	Board[0][2] = new CBishop('W');
	Board[0][3] = new CKing('W');
	Board[0][4] = new CQueen('W');
	Board[0][5] = new CBishop('W');
	Board[0][6] = new CKnight('W');
	Board[0][7] = new CRook('W');
}
CBoard::~CBoard()
{
	for (int iRow = 0; iRow < 8; ++iRow) {
		for (int iCol = 0; iCol < 8; ++iCol) {
			delete Board[iRow][iCol];
			Board[iRow][iCol] = 0;
		}
	}
}

void CBoard::Print() 
{
	using namespace std;
	const int kiSquareWidth = 4;
	const int kiSquareHeight = 3;
	for (int iRow = 0; iRow < 8 * kiSquareHeight; ++iRow) 
	{
		int iSquareRow = iRow / kiSquareHeight;
		// Print side border with numbering
		if (iRow % 3 == 1) 
		{
			cout << '-' << (char)('1' + 7 - iSquareRow) << '-';
		}
		else 
		{
			cout << "---";
		}
		// Print the chess board
		for (int iCol = 0; iCol < 8 * kiSquareWidth; ++iCol) 
		{
			int iSquareCol = iCol / kiSquareWidth;
			if (((iRow % 3) == 1) && ((iCol % 4) == 1 || (iCol % 4) == 2) && Board[7 - iSquareRow][iSquareCol] != 0)
			{
				if ((iCol % 4) == 1) 
				{
					cout << Board[7 - iSquareRow][iSquareCol]->GetColor();
				}
				else 
				{
					cout << Board[7 - iSquareRow][iSquareCol]->GetPiece();
				}
			}
			else
			{
				if ((iSquareRow + iSquareCol) % 2 == 1) 
				{
					cout << '*';
				}
				else {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	// Print the bottom border with numbers
	for (int iRow = 0; iRow < kiSquareHeight; ++iRow) 
	{
		if (iRow % 3 == 1) 
		{
			cout << "---";
			for (int iCol = 0; iCol < 8 * kiSquareWidth; ++iCol) 
			{
				int iSquareCol = iCol / kiSquareWidth;
				if ((iCol % 4) == 1) {
					cout << (iSquareCol + 1);
				}
				else 
				{
					cout << '-';
				}
			}
			cout << endl;
		}
		else 
		{
			for (int iCol = 1; iCol < 9 * kiSquareWidth; ++iCol) 
			{
				cout << '-';
			}
			cout << endl;
		}
	}
}

bool CBoard::IsInCheck(char cColor) 
{
	// Find the king
	int iKingRow;
	int iKingCol;
	for (int iRow = 0; iRow < 8; ++iRow) {
		for (int iCol = 0; iCol < 8; ++iCol) {
			if (Board[iRow][iCol] != 0) {
				if (Board[iRow][iCol]->GetColor() == cColor) {
					if (Board[iRow][iCol]->GetPiece() == 'K') {
						iKingRow = iRow;
						iKingCol = iCol;
					}
				}
			}
		}
	}
	// Run through the opponent's pieces and see if any can take the king
	for (int iRow = 0; iRow < 8; ++iRow) {
		for (int iCol = 0; iCol < 8; ++iCol) {
			if (Board[iRow][iCol] != 0) {
				if (Board[iRow][iCol]->GetColor() != cColor) 
				{
					if (Board[iRow][iCol]->IsLegalMove(iRow, iCol, iKingRow, iKingCol, Board))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool CBoard::CanMove(char cColor) 
{
	// Run through all pieces
	for (int iRow = 0; iRow < 8; ++iRow)
	{
		for (int iCol = 0; iCol < 8; ++iCol)
		{
			if (Board[iRow][iCol] != 0) 
			{
				// If it is a piece of the current player, see if it has a legal move
				if (Board[iRow][iCol]->GetColor() == cColor) 
				{
					for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow) 
					{
						for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol) 
						{
							if (Board[iRow][iCol]->IsLegalMove(iRow, iCol, iMoveRow, iMoveCol, Board)) 
							{
								// Make move and check whether king is in check
								CAPiece* qpTemp = Board[iMoveRow][iMoveCol];
								Board[iMoveRow][iMoveCol] = Board[iRow][iCol];
								Board[iRow][iCol] = 0;
								bool bCanMove = !IsInCheck(cColor);
								// Undo the move
								Board[iRow][iCol] = Board[iMoveRow][iMoveCol];
								Board[iMoveRow][iMoveCol] = qpTemp;
								if (bCanMove) 
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}


