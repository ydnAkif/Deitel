#ifndef DECK_OF_CARDS_HPP
#define DECK_OF_CARDS_HPP

#include <array>

struct BitCard
{
    unsigned int face : 4;
    unsigned int suit : 2;
    unsigned int color : 1;
};

class DeckOfCards
{
public:
    static const int faces = 13;
    static const int colors = 2;
    static const int numberOfCards = 52;

    DeckOfCards();
    void deal() const;

private:
    std::array<BitCard, numberOfCards> deck;
};

#endif