#include "Deck.h"

int main()
{
    //Cards cards{ Cards::Rank::SEVEN, Cards::Suit::DIAMONDS };
    //cards.getCardValue();
    Deck deck{};
    deck.printDeck();
    deck.shuffleDeck();
    deck.printDeck();


}
