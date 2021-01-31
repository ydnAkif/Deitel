#ifndef CARD_HPP
#define CARD_HPP
#include <array>

class Card
{
private:
    size_t face;
    size_t suit;

public:
    explicit Card(size_t, size_t);
    ~Card();
    std::string toString() const;
    size_t getFace() const;
    size_t getSuit() const;
    static const std::array<std::string, 4> suitStrings;
    static const std::array<std::string, 13> faceStrings;
};

#endif