#include "Cards.h"

Cards::Cards(Rank rank, Suit suit) :
	m_rank{ rank }, m_suit{ suit }
{
}

int Cards::getCardValue()const
{
	if (m_rank <= Rank::TEN)
		return (static_cast<int>(m_rank) + 2);
	switch (m_rank)
	{
	case JACK:
	case QUEEN:
	case KING:
		return 10;
		break;
	case ACE:
		return 11;
		break;
	default:
		return -1;
		break;
	}
}

void Cards::printCard()const
{
	switch (m_rank)
	{
	case ACE:
		std::cout << 'A';
		break;
	case TWO:
		std::cout << '2';
		break;
	case THREE:
		std::cout << '3';
		break;
	case FOUR:
		std::cout << '4';
		break;
	case FIVE:
		std::cout << '5';
		break;
	case SIX:
		std::cout << '6';
		break;
	case SEVEN:
		std::cout << '7';
		break;
	case EIGHT:
		std::cout << '8';
		break;
	case NINE:
		std::cout << '9';
		break;
	case TEN:
		std::cout << 'T';
		break;
	case JACK:
		std::cout << 'J';
		break;
	case QUEEN:
		std::cout << 'Q';
		break;
	case KING:
		std::cout << 'K';
		break;
	}

	switch (m_suit)
	{
	case CLUBS:
		std::cout << 'C';
		break;
	case HEARTS:
		std::cout << 'H';
		break;
	case SPADES:
		std::cout << 'S';
		break;
	case DIAMONDS:
		std::cout << 'D';
		break;
	}
}

Cards::~Cards()
{

}