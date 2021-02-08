#ifndef HUGE_INTEGER_HPP
#define HUGE_INTEGER_HPP

#include <iostream>
#include <array>
#include <string>

class HugeInteger
{
    friend std::ostream &operator<<(std::ostream &, const HugeInteger &);

public:
    static const int digits = 30;
    HugeInteger(long = 0);
    HugeInteger(const std::string &);
    ~HugeInteger();

    HugeInteger operator+(const HugeInteger &) const;
    HugeInteger operator+(int) const;
    HugeInteger operator+(const std::string &) const;

    HugeInteger operator*(const HugeInteger &) const;
    HugeInteger operator*(int) const;
    HugeInteger operator*(const std::string &) const;

    HugeInteger operator/(const HugeInteger &) const;
    HugeInteger operator/(int) const;
    HugeInteger operator/(const std::string &) const;

    bool operator==(const HugeInteger &) const;
    bool operator!=(const HugeInteger &) const;
    bool operator>(const HugeInteger &) const;
    bool operator>=(const HugeInteger &) const;
    bool operator<(const HugeInteger &) const;
    bool operator<=(const HugeInteger &) const;

private:
    std::array<short, digits> integer;
};

#endif