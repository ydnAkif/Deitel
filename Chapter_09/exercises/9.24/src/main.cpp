#include <iostream>
#include <vector>
#include "PokerHand.hpp"

int main(int argc, char const *argv[])
{
    PokerHand hand;
    hand.print();

    hand.contains_a_pair() ? (std::cout << "The hand contains a pair.\n") : (std::cout << "The hand has no pair.\n");
    hand.contains_two_pairs() ? (std::cout << "The hand contains two pairs.\n") : (std::cout << "The hand doesn't contain two pairs.\n");
    hand.contains_n_of_a_kind(3) ? (std::cout << "The hand contains three of a kind.\n") : (std::cout << "The hand doesn't contain three of a kind.\n");
    hand.contains_n_of_a_kind(4) ? (std::cout << "The hand contains four of a kind.\n") : (std::cout << "The hand doesn't contain four of a kind.\n");
    hand.contains_a_flush() ? (std::cout << "The hand contains a flush.\n") : (std::cout << "The hand doesn't contain a flush.\n");
    hand.contains_a_straight() ? (std::cout << "The hand contains a straight.\n") : (std::cout << "The hand doesn't contain a straight.\n");

    return 0;
}
