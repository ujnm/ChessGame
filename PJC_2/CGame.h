//!  klasa oblsugujaca dzialanie gry
#pragma once
#include "CBoard.h"


class CGame
{
public:
	//! Konstruktor 
	/*!
	metoda przyjmuje domyslna wartosc W, poniewaz na poczatku gre zaczyna gracz bialy
	*/
	CGame(char = 'W');
	//! Destruktor
	~CGame();
	//! metoda inicjalizuje gre oraz ja prowadzi
	void Start();
	//! metoda pobiera z konsoli ruch od aktualnego gracza
	/*!
	\param qpaaBoard wskaznik zawierajacy aktualny uklad figur na planszy
	*/
	void GetNextMove(CAPiece* qpaaBoard[8][8]);
	//! metoda zmienia kolej gracza na drugiego
		void AlternateTurn();
		//! metoda sprawdza czy gra nie jest skonczona poprzez sprawdzenie czy gracz moze sie poruszyc
		bool IsGameOver();
private:
	//! atrybut przechowujacy stan gry i sluzacy do jego zmiany
	CBoard mqGameBoard;
	//! atrybut informujacy o tym czyja jest teraz kolej
	char PlayerTurn;
};

