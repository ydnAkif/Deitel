#include <iostream>
#include <string>
#include "PokerHand.hpp"

PokerHand::PokerHand(int nCards)
    : nPairs(0)
{
    for (size_t i = 0; i < Card::faceStrings.size(); i++)
    {
        std::vector<Card> sameFaceCardVec;
        handCards.push_back(sameFaceCardVec);
    }

    deck.shuffle();
    for (int i = 0; i < nCards; i++)
    {
        try
        {
            Card temp = deck.dealCard();
            size_t face = temp.getFace();
            handCards.at(face).push_back(temp);
        }
        catch (const char *e)
        {
            std::cout << e;
        }
    }

    for (size_t i = 0; i < handCards.size(); i++)
    {
        if (handCards.at(i).size() >= 2)
        {
            nPairs++;
        }
    }
}

PokerHand::~PokerHand()
{
}

bool PokerHand::contains_a_pair() const
{
    return nPairs > 0 ? true : false;
}

bool PokerHand::contains_two_pairs() const
{
    return nPairs >= 2 ? true : false;
}

bool PokerHand::contains_n_of_a_kind(const int n) const
{
    for (size_t i = 0; i < handCards.size(); i++)
    {
        if (handCards.at(i).size() >= n)
        {
            return true;
        }
    }
    return false;
}

bool PokerHand::contains_a_flush() const
{
    int suit = -1;

    // We get the first suit value
    for (size_t i = 0; i < handCards.size(); i++)
    {
        if (handCards.at(i).size() > 0) // there are cards with face i in the inner vec
        {
            suit = handCards.at(i).at(0).getSuit();
            break;
        }
    }

    // If there's a value that is different from the suit we got ealier, return false
    for (size_t i = 0; i < handCards.size(); i++)
    {
        for (size_t j = 0; j < handCards.at(i).size(); j++)
        {
            if (handCards.at(i).at(j).getSuit() != suit)
            {
                return false;
            }
        }
    }

    return true;
}

bool PokerHand::contains_a_straight() const
{
    std::vector<Card> cards;
    for (size_t i = 0; i < handCards.size(); i++)
    {
        for (size_t j = 0; j < handCards.at(i).size(); j++)
        {
            cards.push_back(handCards.at(i).at(j));
        }
    }

    size_t maxFace = cards.at(0).getFace();
    size_t minFace = cards.at(0).getFace();
    for (size_t i = 0; i < cards.size(); i++)
    {
        if (minFace > cards.at(i).getFace())
        {
            minFace = cards.at(i).getFace();
        }
        if (maxFace < cards.at(i).getFace())
        {
            maxFace = cards.at(i).getFace();
        }
    }
    if (0 == nPairs && 4 == (maxFace - minFace))
    {
        return true;
    }

    return false;
}

void PokerHand::print() const
{
    for (size_t i = 0; i < handCards.size(); i++)
    {
        for (size_t j = 0; j < handCards.at(i).size(); j++)
        {
            std::cout << handCards.at(i).at(j).toString() << " ";
        }
        if (handCards.at(i).size() > 0)
        {
            std::cout << std::endl;
        }
    }
}

int PokerHand::getPairNumbers() const
{
    return nPairs;
}
