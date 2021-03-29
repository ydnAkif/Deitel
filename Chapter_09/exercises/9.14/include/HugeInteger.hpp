#ifndef HUGE_INTEGER_HPP
#define HUGE_INTEGER_HPP
#include <array>
#include <string>

const int nDigits = 40;

class HugeInteger
{
private:
    std::array<int, nDigits> digits;
    char sign;
    HugeInteger &absoluteAdd(const HugeInteger &);
    bool isAbsoluteNotLessThan(const HugeInteger &) const;

public:
    explicit HugeInteger(const std::string &numberString = std::string("0"));
    ~HugeInteger();
    HugeInteger(const HugeInteger &);

    void input(const std::string &numberString = std::string("0"));
    std::string output() const;
    HugeInteger &add(const HugeInteger &);
    HugeInteger &subtract(const HugeInteger &);
    HugeInteger &multiply(const HugeInteger &);
    HugeInteger &divide(const HugeInteger &);
    HugeInteger &modulus(const HugeInteger &);
    HugeInteger &operator=(const HugeInteger &);

    bool isEqualTo(const HugeInteger &) const;
    bool isNotEqualTo(const HugeInteger &) const;
    bool isGreaterThan(const HugeInteger &) const;
    bool isLessThan(const HugeInteger &) const;
    bool isGreaterThanOrEqualTo(const HugeInteger &) const;
    bool isLessThanOrEqualTo(const HugeInteger &) const;
    bool isZero() const;
    const HugeInteger absolute() const;
};

#endif