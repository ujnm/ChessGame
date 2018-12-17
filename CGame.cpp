#include "stdafx.h"
#include "CGame.h"
#include "CBoard.h"
using namespace std;
#include <iostream>
#include "CAPiece.h"

CGame::CGame(char player)
{
	PlayerTurn = player;
}
CGame::~CGame() {}

void CGame::Start()
{
	do 
	{
		GetNextMove(mqGameBoard.Board);
		AlternateTurn();
	} while (!IsGameOver());
	mqGameBoard.Print();
}

void CGame::GetNextMove(CAPiece* qpaaBoard[8][8]) 
{
	
	bool bValidMove = false;
	do 
	{
		mqGameBoard.Print();

		// Getting input and converting to coordinates
		cout << PlayerTurn << "'s Move: ";
		int iStartMove;
		cin >> iStartMove;
		int iStartRow = (iStartMove / 10) - 1;
		int iStartCol = (iStartMove % 10) - 1;

		cout << "To: ";
		int iEndMove;
		cin >> iEndMove;
		int iEndRow = (iEndMove / 10) - 1;
		int iEndCol = (iEndMove % 10) - 1;

		// Check that the indices are in range
		// and that the source and destination are different
		if ((iStartRow >= 0 && iStartRow <= 7) &&
			(iStartCol >= 0 && iStartCol <= 7) &&
			(iEndRow >= 0 && iEndRow <= 7) &&
			(iEndCol >= 0 && iEndCol <= 7)) 
		{
			// Additional checks in here
			CAPiece* qpCurrPiece = qpaaBoard[iStartRow][iStartCol];
			// Check that the piece is the correct color
			if ((qpCurrPiece != 0) && (qpCurrPiece->GetColor() == PlayerTurn)) 
			{
				// Check that the destination is a valid destination
				if (qpCurrPiece->IsLegalMove(iStartRow, iStartCol, iEndRow, iEndCol, qpaaBoard)) 
				{
					// Make the move
					CAPiece* qpTemp = qpaaBoard[iEndRow][iEndCol];
					qpaaBoard[iEndRow][iEndCol] = qpaaBoard[iStartRow][iStartCol];
					qpaaBoard[iStartRow][iStartCol] = 0;
					// Make sure that the current player is not in check
					if (!mqGameBoard.IsInCheck(PlayerTurn)) 
					{
						delete qpTemp;
						bValidMove = true;
					}
					else // Undo the last move
					{ 
						qpaaBoard[iStartRow][iStartCol] = qpaaBoard[iEndRow][iEndCol];
						qpaaBoard[iEndRow][iEndCol] = qpTemp;
					}
				}
			}
		}
		if (!bValidMove) {
			cout << "Invalid Move!" <<endl;
		}
	} while (!bValidMove);
}

void CGame::AlternateTurn()
{
	PlayerTurn = (PlayerTurn == 'W') ? 'B' : 'W';
}

bool CGame::IsGameOver() 
{
	// Check that the current player can move
	// If not, we have a stalemate or checkmate
	bool bCanMove(false);
	bCanMove = mqGameBoard.CanMove(PlayerTurn);
	if (!bCanMove) 
	{
		if (mqGameBoard.IsInCheck(PlayerTurn)) 
		{
			AlternateTurn();
			std::cout << "Checkmate, " << PlayerTurn << " Wins!" << std::endl;
		}
		else 
		{
			std::cout << "Stalemate!" << std::endl;
		}
	}
	return !bCanMove;
}
