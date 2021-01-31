#include <iostream>
#include "Card.hpp"

const std::array<std::string, 4> Card::suitStrings = {
    "Spades",
    "Hearts",
    "Diamonds",
    "Clubs"};
const std::array<std::string, 13> Card::faceStrings = {
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Jack",
    "Queen",
    "King",
    "Ace"};

Card::Card(size_t _face, size_t _suit) : face(_face), suit(_suit)
{
}

Card::~Card()
{
}

std::string Card::toString() const
{
    return (faceStrings.at(face) + " of " + suitStrings.at(suit) + ".");
}
