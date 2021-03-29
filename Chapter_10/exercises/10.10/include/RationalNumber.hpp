#ifndef RATIONAL_NUMBER_HPP
#define RATIONAL_NUMBER_HPP

class RationalNumber
{
private:
    int numerator;
    int denominator;
    void reduce();
    unsigned int gcd(unsigned int, unsigned int) const;
    unsigned int lcm(unsigned int, unsigned int) const;
    bool isValid() const;

public:
    RationalNumber(const int = 1, const int = 1);
    ~RationalNumber();

    RationalNumber &add(const RationalNumber &);
    RationalNumber &subtract(const RationalNumber &);
    RationalNumber &multiply(const RationalNumber &);
    RationalNumber &divide(const RationalNumber &);

    RationalNumber operator+(const RationalNumber &) const;
    RationalNumber operator-(const RationalNumber &) const;
    RationalNumber operator*(const RationalNumber &) const;
    RationalNumber operator/(const RationalNumber &) const;

    bool operator==(const RationalNumber &) const;
    bool operator!=(const RationalNumber &) const;
    bool operator<(const RationalNumber &) const;
    bool operator<=(const RationalNumber &) const;
    bool operator>(const RationalNumber &) const;
    bool operator>=(const RationalNumber &) const;

    void print() const;
    void printFloat() const;
    int getNumerator() const;
    int getDenominator() const;
};

#endif