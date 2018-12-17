#include "stdafx.h"
#include "CInterface.h"
#include <iostream>
#include"CBoard.h"



CInterface::CInterface()
{
}


CInterface::~CInterface()
{
}

void CInterface::Print()
{
	//using namespace std;
	//const int kiSquareWidth = 4;
	//const int kiSquareHeight = 3;
	//for (int iRow = 0; iRow < 8 * kiSquareHeight; ++iRow)
	//{
	//	int iSquareRow = iRow / kiSquareHeight;
	//	// Print side border with numbering
	//	if (iRow % 3 == 1)
	//	{
	//		cout << '-' << (char)('1' + 7 - iSquareRow) << '-';
	//	}
	//	else
	//	{
	//		cout << "---";
	//	}
	//	// Print the chess board
	//	for (int iCol = 0; iCol < 8 * kiSquareWidth; ++iCol)
	//	{
	//		int iSquareCol = iCol / kiSquareWidth;
	//		if (((iRow % 3) == 1) && ((iCol % 4) == 1 || (iCol % 4) == 2) && Board[7 - iSquareRow][iSquareCol] != 0)
	//		{
	//			if ((iCol % 4) == 1)
	//			{
	//				cout << Board[7 - iSquareRow][iSquareCol]->GetColor();
	//			}
	//			else
	//			{
	//				cout << Board[7 - iSquareRow][iSquareCol]->GetPiece();
	//			}
	//		}
	//		else
	//		{
	//			if ((iSquareRow + iSquareCol) % 2 == 1)
	//			{
	//				cout << '*';
	//			}
	//			else {
	//				cout << ' ';
	//			}
	//		}
	//	}
	//	cout << endl;
	//}
	//// Print the bottom border with numbers
	//for (int iRow = 0; iRow < kiSquareHeight; ++iRow)
	//{
	//	if (iRow % 3 == 1)
	//	{
	//		cout << "---";
	//		for (int iCol = 0; iCol < 8 * kiSquareWidth; ++iCol)
	//		{
	//			int iSquareCol = iCol / kiSquareWidth;
	//			if ((iCol % 4) == 1) {
	//				cout << (iSquareCol + 1);
	//			}
	//			else
	//			{
	//				cout << '-';
	//			}
	//		}
	//		cout << endl;
	//	}
	//	else
	//	{
	//		for (int iCol = 1; iCol < 9 * kiSquareWidth; ++iCol)
	//		{
	//			cout << '-';
	//		}
	//		cout << endl;
	//	}
	//}
}
