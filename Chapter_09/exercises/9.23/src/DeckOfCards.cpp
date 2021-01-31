#include <cstdlib>
#include <ctime>
#include "DeckOfCards.hpp"

DeckOfCards::DeckOfCards() : currentCard(0)
{
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < Card::faceStrings.size(); ++i)
    {
        for (size_t j = 0; j < Card::suitStrings.size(); ++j)
        {
            Card newCard = Card(i, j);
            deck.push_back(newCard);
        }
    }
}

DeckOfCards::~DeckOfCards()
{
}

void DeckOfCards::shuffle()
{
    for (size_t index = 0; index < deck.size(); ++index)
    {
        size_t left = index;

        std::vector<size_t> indexVec;

        for (size_t i = 0; i < deck.size(); ++i)
        {
            indexVec.push_back(i);
        }

        indexVec.erase(indexVec.begin() + left);

        size_t right = indexVec.at(rand() % indexVec.size());

        Card temp = deck.at(left);
        deck.at(left) = deck.at(right);
        deck.at(right) = temp;
    }
}

Card DeckOfCards::dealCard()
{
    Card toDeal = deck.at(currentCard);
    deck.erase(deck.begin() + currentCard);
    return toDeal;
}

bool DeckOfCards::moreCards() const
{
    return (deck.size() > 0);
}