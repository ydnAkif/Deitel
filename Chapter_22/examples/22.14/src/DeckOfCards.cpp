#include <iostream>
#include <iomanip>
#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards()
{
    for (size_t i = 0; i < deck.size(); ++i)
    {
        deck[i].face = i % faces;
        deck[i].suit = i / faces;
        deck[i].color = i / (faces * colors);
    }
}

void DeckOfCards::deal() const
{
    for (size_t k1 = 0, k2 = k1 + (deck.size() / 2); k1 <= (deck.size() / 2) - 1; ++k1, ++k2)
    {
        std::cout << "Card:" << std::setw(3) << deck[k1].face
                  << "  Suit:" << std::setw(2) << deck[k1].suit
                  << "  Color:" << std::setw(2) << deck[k1].color
                  << "   "
                  << "Card:" << std::setw(3) << deck[k2].face
                  << "  Suit:" << std::setw(2) << deck[k2].suit
                  << "  Color:" << std::setw(2) << deck[k2].color << std::endl;
    }
}