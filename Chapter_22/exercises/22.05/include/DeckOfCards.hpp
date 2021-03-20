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
    static const int suits = 4;
    static const int colors = 2;
    static const int numberOfCards = 52;

    DeckOfCards();
    void deal();
    void fillDeck();
    void shuffle();

private:
    std::array<BitCard, numberOfCards> deck;
};

#endif