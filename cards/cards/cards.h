#pragma once
#include <array>

enum class Rank
{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
    MAX_RANK,
};

enum class Suit
{
    CLUBS, DIAMONDS,
    SPADES, HEARTS,
    MAX_SUIT,
};

struct CardType
{
    Rank rank{};
    Suit suit{};
};

using arr_deck = std::array<CardType, 52>; // for simplicity
using index_deck = arr_deck::size_type;

void printCardType(const CardType& card);
int getCardValue(const CardType& card);
arr_deck createDeck();
void shuffleDeck(arr_deck& deck);
void printDeck(const arr_deck& deck);

