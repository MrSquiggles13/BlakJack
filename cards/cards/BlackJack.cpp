#include <iostream>
#include "BlackJack.h"
#include "cards.h"

int money{100};
int bet;

bool playerTurn(const arr_deck& deck, Player& user, Player& dealer, index_deck& carditr)
{
    char userIn{};
    do
    {
        if (user.score > blackJack)
        {
            std::cout << "You Lost =( ";
            return true;
        }
        else if (userIn == 'D' || userIn == 'd')
            return false;
        std::cout << "[H]it [S]tand? or [D]ouble down?: ";
        std::cin >> userIn;
        if (userIn == 'H' || userIn == 'h')
        {
            // user hits
            std::cout << "Your New Card: ";
            printCardType(deck[carditr]); std::cout << '\n';
            if (deck[carditr].rank == Rank::ACE)
            {
                ++user.aceCount;
            }
            user.score += (getCardValue(deck[carditr++]));
            if (user.aceCount > 0 && user.score > blackJack)
            {
                user.score -= aceSwitchValue;
                --user.aceCount;
            }
            if (carditr > deckMax)
            {
                carditr = 0;
            }
            std::cout << "Your New Score: " << user.score << '\n';
        }
        else if (userIn == 'D' || userIn == 'd')
        {
            bet = bet * 2;
            std::cout << "Your New Card: ";
            printCardType(deck[carditr]); std::cout << '\n';
            if (deck[carditr].rank == Rank::ACE)
            {
                ++user.aceCount;
            }
            user.score += (getCardValue(deck[carditr++]));
            if (user.aceCount > 0 && user.score > blackJack)
            {
                user.score -= aceSwitchValue;
                --user.aceCount;
            }
            if (carditr > deckMax)
            {
                carditr = 0;
            }
            std::cout << "Your New Score: " << user.score << '\n';

        }
        else if (userIn == 'S' || userIn == 's')
        {
            return false;
        }
    } while (true);

}

bool dealerTurn(const arr_deck& deck, Player& user, Player& dealer, index_deck& carditr)
{
    while (true)
    {
        if (dealer.score > blackJack)
        {
            std::cout << "You Won!! ";
            money += (bet * 2);
            return true;
        }
        else if (dealer.score < dealerLimit)
        {
            std::cout << "Dealer Hits: ";
            printCardType(deck[carditr]); std::cout << '\n';
            if (deck[carditr].rank == Rank::ACE)
            {
                ++dealer.aceCount;
            }
            dealer.score += (getCardValue(deck[carditr++]));
            if (dealer.aceCount > 0 && dealer.score > blackJack)
            {
                dealer.score -= aceSwitchValue;
                --dealer.aceCount;
            }
            if (carditr > deckMax)
            {
                carditr = 0;
            }
            std::cout << "Dealer score: " << dealer.score << '\n';
        }
        else if (dealer.score > user.score)
        {
            std::cout << "You Lost =( "; return true;
        }
        else if (dealer.score < user.score)
        {
            std::cout << "You Won!! ";
            money += (bet * 2);
            return true;
        }
        else
        {
            std::cout << "Draw =/ ";
            money += bet;
            return true;
        }
    }
}

void initialHand(const arr_deck& deck, Player& user, Player& dealer, index_deck& carditr)
{
    for (int iii{ 0 }; iii < 2; ++iii)
    {
        printCardType(deck[carditr]); std::cout << ' ';
        if ((deck[carditr].rank == Rank::ACE) && (user.score > blackJack))
        {
            user.score -= aceSwitchValue;
        }
        if (deck[carditr].rank == Rank::ACE)
        {
            ++user.aceCount;
        }
        user.score += (getCardValue(deck[carditr++]));
        if (carditr > deckMax)
        {
            carditr = 0;
        }
        aceCheck(deck, dealer, carditr);
        dealer.score += (getCardValue(deck[carditr++]));
        if (carditr > deckMax)
        {
            carditr = 0;
        }
    }
}

void aceCheck(const arr_deck& deck, Player& player, index_deck& carditr)
{
    if ((deck[carditr].rank == Rank::ACE) && (player.score > blackJack))
    {
        player.score -= aceSwitchValue;
    }
    if (deck[carditr].rank == Rank::ACE)
    {
        ++player.aceCount;
    }
}

bool playBlackjack(const arr_deck& deck, index_deck& carditr)
{
    std::cout << "Welcome to BlackJack! \n";
    do
    {
        if (money <= 0)
        {
            std::cout << "You went bust!! we do the money give you\n";
            money = 20;
        }
        std::cout << "You have: " << money << " coins\nHow much would you like to bet?: ";
        std::cin >> bet;
    } while ((bet <= 0) || (bet > money));
    money -= bet;

    bool gameOver{ false };
    Player dealer{ 0 };
    Player user{ 0 };
    
    std::cout << "Here are your cards: ";
    initialHand(deck, user, dealer, carditr);
    std::cout << "\nDealer card showing: ";
    printCardType(deck[--carditr]);
    std::cout << '\n' << "Your Score: " << user.score << '\n';

    while (!gameOver)
    {
        gameOver = playerTurn(deck, user, dealer, ++carditr);
        if (!gameOver)
        {
            std::cout << "Dealer has: " << dealer.score << '\n';
            gameOver = dealerTurn(deck, user, dealer, carditr);
        }
        char choice{};
        while (gameOver)
        {
            std::cout << "Play Again? [y/n]: ";
            std::cin >> choice;

            if (choice == 'Y' || choice == 'y')
            {
                return !gameOver;
            }
            else if (choice == 'N' || choice == 'n')
                break;
        }
    }
    return gameOver;
}