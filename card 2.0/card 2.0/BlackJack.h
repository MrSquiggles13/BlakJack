#pragma once
#include "Deck.h"

class BlackJack
{
public:
	struct Dealer
	{
		std::vector<Cards> hand;
	};
	struct Player
	{
		std::vector<Cards> hand;
		int coin;
		int bet;
	};
private:
	Player user;
	Dealer dealer;
public:

	BlackJack();

	void bet();
	void hit();
	void stand();
	void doubleDown();
	void split();
	void gameOutcome();
};

