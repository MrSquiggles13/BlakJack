#include "Deck.h"

Deck::Deck()
{
	std::vector<Cards>::size_type card{ 0 };
	for (std::vector<Cards>::size_type suit{ 0 }; suit < Cards::MAX_SUIT; ++suit)
		for (std::vector<Cards>::size_type rank{ 0 }; rank < Cards::MAX_RANK; ++rank)
		{
			m_deck.push_back({static_cast<Cards::Rank>(rank), static_cast<Cards::Suit>(suit)});
			++card;
		}
}

void Deck::shuffleDeck()const
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(m_deck.begin(), m_deck.end(), mersenne);
}

void Deck::printDeck()const
{
	for (auto& card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}
	std::cout << '\n';
}

Cards Deck::drawCard()
{
	++m_card;
	std::cout << "You drew ";
	m_deck[m_card].printCard();
	return m_deck[m_card];
}

Deck::~Deck()
{

}