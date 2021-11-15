#include "BlackJack.h"
#include "cards.h"

int main()
{
    auto deck{ createDeck() };
    shuffleDeck(deck);
    bool gameOver{};
    index_deck carditr{ 0 };
    do
    {
        gameOver = playBlackjack(deck, carditr);
        shuffleDeck(deck);
    } while (!gameOver);

    //printDeck(deck);
    return 0;
}