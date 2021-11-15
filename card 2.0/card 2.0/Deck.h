#pragma once
#include "Cards.h"
class Deck 
{
private:
	std::vector<Cards> m_deck;
	std::vector<Cards>::size_type m_card{ 0 };
public:
	Deck();

	void shuffleDeck()const;
	void printDeck()const;
	Cards drawCard();

	~Deck();
};

