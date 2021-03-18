#ifndef DECK_OF_CARDS_HPP
#define DECK_OF_CARDS_HPP

#include <string>
#include <array>

struct Card
{
    std::string face;
    std::string suit;
};

class DeckOfCards
{
public:
    static const int numberOfCards = 52;
    static const int faces = 13;
    static const int suits = 4;

    DeckOfCards();
    void shuffle();
    void deal() const;

private:
    std::array<Card, numberOfCards> deck;
};

#endif