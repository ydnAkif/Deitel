#include <iostream>
#include "DeckOfCards.hpp"

int main(int argc, char const *argv[])
{
    DeckOfCards deckOfCards;
    deckOfCards.shuffle();
    deckOfCards.deal();

    return 0;
}
