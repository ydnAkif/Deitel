#include <iostream>
#include <iomanip>
#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards()
{
    fillDeck();
    srand(static_cast<size_t>(time(nullptr)));
}

void DeckOfCards::deal()
{
    static std::array<std::string, suits> suitArr = {"Hearts", "Diamonds", "Clubs", "Spades"};
    static std::array<std::string, faces> faceArr = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
                                                     "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    static std::array<std::string, colors> colorArr = {"Red", "Black"};

    for (size_t i = 0; i < deck.size(); ++i)
    {
        std::cout << std::setw(5) << colorArr[deck[i].color] << ": "
                  << std::setw(8) << faceArr[deck[i].face] << " of "
                  << std::setiosflags(std::ios::left) << std::setw(8)
                  << suitArr[deck[i].suit] << std::resetiosflags(std::ios::left)
                  << ((i + 1) % 2 ? '\t' : '\n');
        }
}

void DeckOfCards::fillDeck()
{
    for (size_t i = 0; i < deck.size(); ++i)
    {
        deck[i].face = i % faces;
        deck[i].suit = i / faces;
        deck[i].color = i / (faces * colors);
    }
}

void DeckOfCards::shuffle()
{
    for (size_t i = 0; i < deck.size(); ++i)
    {
        int j = rand() % numberOfCards;
        BitCard temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}