#include <iostream>
#include <string>
#include "DeckOfCards.hpp"

int main(int argc, char const *argv[])
{
    DeckOfCards testDesk;
    testDesk.shuffle();

    while (testDesk.moreCards())
    {
        std::cout << testDesk.dealCard().toString();
        std::cout << std::endl;
    }

    return 0;
}
