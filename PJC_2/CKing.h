#pragma once
//!  klasa opisujaca figure krol
/*!
dziedziczy metody i atrybuty po klasie CAPiece
*/
#include "CAPiece.h"
class CKing :public CAPiece
{
public:
	//! Konstruktor 
	/*!
	\param cColor char zawierajacy kolor jaki ma miec figura, 'w' dla bialego i 'b' dla czarnego
	*/
	CKing(char cColor);
	//! Destruktor
	~CKing();
private:
	//! metoda dziedziczona po klasie CAPiece
	virtual char GetPiece();
	//! metoda dziedziczona po klasie CAPiece
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

