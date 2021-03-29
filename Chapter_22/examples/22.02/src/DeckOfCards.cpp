#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards()
{
    static std::array<std::string, suits> suit = {"Hearts", "Diamonds", "Clubs", "Spades"};
    static std::array<std::string, faces> face = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
                                                  "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    for (size_t i = 0; i < deck.size(); ++i)
    {
        deck[i].face = face[i % faces];
        deck[i].suit = suit[i / faces];
    }

    srand(static_cast<size_t>(time(nullptr)));
}

void DeckOfCards::shuffle()
{
    for (size_t i = 0; i < deck.size(); ++i)
    {
        int j = rand() % numberOfCards;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void DeckOfCards::deal() const
{
    for (size_t i = 0; i < deck.size(); ++i)
    {
        std::cout << std::right << std::setw(5) << deck[i].face << " of "
                  << std::left << std::setw(8) << deck[i].suit
                  << ((i + 1) % 2 ? '\t' : '\n');
    }
}