#pragma once
#include <iostream>
#include <ctime>
#include <random>
#include <vector>

class Cards
{
public:
	enum Suit
	{
		CLUBS,
		HEARTS,
		SPADES,
		DIAMONDS,
		MAX_SUIT
	};

	enum Rank
	{
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE,
		MAX_RANK
	};
private:
	Rank m_rank { };
	Suit m_suit { };

public:
	Cards(Rank rank, Suit suit);
	//functions
	int getCardValue()const;
	void  printCard()const;
	//accessors


	~Cards();
};

