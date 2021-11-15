#include "BlackJack.h"

BlackJack::BlackJack()
{}

void BlackJack::bet()
{
	std::cout << "Bet the money: ";
	std::cin >> user.bet;
	user.coin -= user.bet;
}

void BlackJack::hit()
{
	
}

void BlackJack::stand()
{

}

void BlackJack::doubleDown()
{

}

void BlackJack::split()
{

}

void BlackJack::gameOutcome()
{

}