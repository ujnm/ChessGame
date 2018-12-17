//!  klasa abstrakcyjna opisujaca figury 
/*!
Zawiera metody wirtualne wykorzystywane przez klasy dziedziczace po niej (klasy konkretnych figur)
*/
#pragma once


class CAPiece
{
public:
	//! Konstruktor.
	/*!
	Tworzy on figure nadajac jej odpowiedni kolor, czyli przypisanie do gracza (czarny,bialy)
	*/
	CAPiece(char cColor);
	//! Destruktor
	~CAPiece();
	//! Metoda wirtualna, ktora daje informacje jaka figure bierze sie aktualnie
	virtual char GetPiece() = 0;
	//! Metoda wirtualna, ktora daje informacje jakiego koloru jest dana figura
	char GetColor();
	//! metoda zwracaca informacje czy ruch podany przez gracza jest poprawny
	/*!
	\param iSrcRow int zawierajacy numer rzedu pozycji poczatkowej.
	\param iSrcCol int zawierajacy numer kolumny pozycji poczatkowej.
	\param iDestRow int zawierajacy numer rzedu pozycji koncowej.
	\param iDestCol int zawierajacy numer kolumny pozycji koncowej.
	\return informacja czy ruch jest legalny (1) czy nie (0)
	*/
	bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]);
private:
	//! metoda wirtualna, ktora zwraca informacje czy miejsca poczatkowe i koncowe ruchu sa poprawne
	/*!
	\param iSrcRow int zawierajacy numer rzedu pozycji poczatkowej.
	\param iSrcCol int zawierajacy numer kolumny pozycji poczatkowej.
	\param iDestRow int zawierajacy numer rzedu pozycji koncowej.
	\param iDestCol int zawierajacy numer kolumny pozycji koncowej.
	\param qpaaBoard wskaznik do tablicy przechowujacej aktualne pozycje wszystkich figur
	\return informacja czy pola sa poprawne (1) czy nie (0)
	*/
	virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) = 0;
	//! atrybut opisujacy jakiego koloru jest dana figura, 'w' dla bialego i 'b' dla czarnego
	char mcColor;

};

