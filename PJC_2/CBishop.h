#pragma once
#include <iostream>
using namespace std;
//!  klasa opisujaca figure goniec
/*!
dziedziczy metody i atrybuty po klasie CAPiece
*/
#include "CAPiece.h"
class CBishop : public CAPiece
{
public:
	//! Konstruktor 
	/*!
	\param cColor char zawierajacy kolor jaki ma miec figura, 'w' dla bialego i 'b' dla czarnego
	*/
	CBishop(char cColor);
	//! Destruktor
	~CBishop();
private:
	//! metoda dziedziczona po klasie CAPiece
	virtual char GetPiece();
	//! metoda dziedziczona po klasie CAPiece
	virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
};

