#include <array>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include "cards.h"

void printCardType(const CardType& card)
{
    switch (card.rank)
    {
    case Rank::TWO:
        std::cout << '2';
        break;
    case Rank::THREE:
        std::cout << '3';
        break;
    case Rank::FOUR:
        std::cout << '4';
        break;
    case Rank::FIVE:
        std::cout << '5';
        break;
    case Rank::SIX:
        std::cout << '6';
        break;
    case Rank::SEVEN:
        std::cout << '7';
        break;
    case Rank::EIGHT:
        std::cout << '8';
        break;
    case Rank::NINE:
        std::cout << '9';
        break;
    case Rank::TEN:
        std::cout << 'T';
        break;
    case Rank::JACK:
        std::cout << 'J';
        break;
    case Rank::QUEEN:
        std::cout << 'Q';
        break;
    case Rank::KING:
        std::cout << 'K';
        break;
    case Rank::ACE:
        std::cout << 'A';
        break;
    default:
        std::cout << '???';
        break;
    }
    switch (card.suit)
    {
    case Suit::CLUBS:
        std::cout << 'C';
        break;
    case Suit::DIAMONDS:
        std::cout << 'D';
        break;
    case Suit::SPADES:
        std::cout << 'S';
        break;
    case Suit::HEARTS:
        std::cout << 'H';
        break;
    default:
        std::cout << '???';
        break;
    }
}

int getCardValue(const CardType& card)
{
    if (card.rank <= Rank::TEN)
        return (static_cast<int>(card.rank) + 2);
    switch (card.rank)
    {
        case Rank::JACK:
        case Rank::QUEEN:
        case Rank::KING:
            return 10;
        case Rank::ACE:
            return 11;
    }
}

arr_deck createDeck()
{
    arr_deck deck{};
    index_deck card{ 0 };

    auto lengthS(static_cast<index_deck>(Suit::MAX_SUIT));
    auto lengthR(static_cast<index_deck>(Rank::MAX_RANK));
    //converts interators to enum type value
    for (index_deck suitItr{ 0 }; suitItr < lengthS; ++suitItr)
    {
        for (index_deck rankItr{ 0 }; rankItr < lengthR; ++rankItr)
        {
            deck[card].suit = static_cast<Suit>(suitItr);
            deck[card].rank = static_cast<Rank>(rankItr);
            ++card;
        }
    }
    return deck;
}

void shuffleDeck(arr_deck& deck)
{
    static std::mt19937 seed{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    // mersenne twister random number generator
    std::shuffle(deck.begin(), deck.end(), seed);
}

void printDeck(const arr_deck& deck)
{
    for (const auto& card : deck)
    {
        printCardType(card);
        std::cout << ' ';
    }
}