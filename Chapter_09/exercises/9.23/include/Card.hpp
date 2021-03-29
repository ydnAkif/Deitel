#ifndef CARD_HPP
#define CARD_HPP
#include <array>

class Card
{
private:
    size_t face;
    size_t suit;

public:
    static const std::array<std::string, 4> suitStrings;
    static const std::array<std::string, 13> faceStrings;
    explicit Card(size_t, size_t);
    ~Card();
    std::string toString() const;
};

#endif