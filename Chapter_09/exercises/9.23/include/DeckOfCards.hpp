#ifndef DECK_OF_CARDS_HPP
#define DECK_OF_CARDS_HPP

#include <vector>
#include "Card.hpp"

class DeckOfCards
{
private:
    int currentCard;
    std::vector<Card> deck;

public:
    explicit DeckOfCards();
    ~DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards() const;
};

#endif