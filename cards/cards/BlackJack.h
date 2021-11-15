#pragma once
#include "cards.h"

constexpr int blackJack{ 21 };
constexpr int dealerLimit{ 17 };
constexpr int aceSwitchValue{ 10 };
constexpr int firstDraw{ 4 };
constexpr int deckMax{ 51 };
struct Player
{
    int aceCount{};
    int score{};
};

bool playerTurn(const arr_deck& deck, Player& user, Player& dealer, index_deck& carditr);
bool dealerTurn(const arr_deck& deck, Player& user, Player& dealer, index_deck& carditr);
void initialHand(const arr_deck& deck, Player& user, Player& dealer, index_deck& carditr);
void aceCheck(const arr_deck& deck, Player& player, index_deck& carditr);
bool playBlackjack(const arr_deck& deck, index_deck& carditr);