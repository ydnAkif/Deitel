#ifndef POKER_HAND_HPP
#define POKER_HAND_HPP

#include <vector>
#include "Card.hpp"
#include "DeckOfCards.hpp"

class PokerHand
{
private:
    int nPairs;
    std::vector<std::vector<Card>> handCards;
    DeckOfCards deck;

public:
    explicit PokerHand(int nCards = 5);
    ~PokerHand();
    bool contains_a_pair() const;
    bool contains_two_pairs() const;
    bool contains_n_of_a_kind(const int) const;
    bool contains_a_flush() const;
    bool contains_a_straight() const;
    void print() const;
    int getPairNumbers() const;
};

#endif