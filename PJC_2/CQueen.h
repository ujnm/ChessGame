//!  klasa opisujaca figure krolowa
/*!
dziedziczy metody i atrybuty po klasie CAPiece
*/
#pragma once
#include "CAPiece.h"
class CQueen : public CAPiece
{
public:
	//! Konstruktor 
	/*!
	\param cColor char zawierajacy kolor jaki ma miec figura, 'w' dla bialego i 'b' dla czarnego
	*/
	CQueen(char cColor);
	//! Destruktor
	~CQueen();
private:
	//! metoda dziedziczona po klasie CAPiece
	virtual char GetPiece();
	//! metoda dziedziczona po klasie CAPiece
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

