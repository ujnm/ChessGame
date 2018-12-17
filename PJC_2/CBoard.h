//!  klasa oblsugujaca dzialania na planszy 

#pragma once
#include "CAPiece.h"
class CBoard
{
public:
	//! Konstruktor
	CBoard();
	//! Destruktor
	~CBoard();
	//! metoda wypisujaca aktualny uklad planszy do konsoli
	void Print();//interface
	//! metoda sprawdzajaca czy dany gracz nie jest w szachu
	/*!
	\param cColor char zawierajacy kolor gracza, 'w' dla bialego i 'b' dla czarnego
	*/
	bool IsInCheck(char cColor);
	//! metoda sprawdzajaca czy gracz moze wykonac podany ruch a nastepnie go wykonuje
	/*!
	\param cColor char zawierajacy kolor gracza, 'w' dla bialego i 'b' dla czarnego
	*/
	bool CanMove(char cColor);
	//! atrybut publiczny przechowujacy aktualny uklad figur na planszy
	CAPiece* Board[8][8];
};

