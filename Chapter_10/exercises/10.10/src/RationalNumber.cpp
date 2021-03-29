#include <iostream>
#include <cmath>
#include "RationalNumber.hpp"

RationalNumber::RationalNumber(const int _numerator, const int _denominator)
    : numerator(_numerator), denominator(_denominator)
{
    if (!isValid())
    {
        throw "Invalid, zero denominator.";
    }

    reduce();
}

RationalNumber::~RationalNumber()
{
}

RationalNumber &RationalNumber::add(const RationalNumber &b)
{
    unsigned int leastCommonMultiple = lcm(abs(this->denominator), abs(b.numerator));

    this->numerator *= leastCommonMultiple / abs(this->denominator);
    this->numerator += b.numerator * (leastCommonMultiple / abs(b.denominator));
    this->denominator = leastCommonMultiple;

    if (!isValid())
    {
        throw "Invalid, zero denominator.";
    }

    reduce();

    return *this;
}

RationalNumber &RationalNumber::subtract(const RationalNumber &b)
{
    unsigned int leastCommonMultiple = lcm(abs(this->denominator), abs(b.numerator));

    this->numerator *= leastCommonMultiple / abs(this->denominator);
    this->numerator -= b.numerator * (leastCommonMultiple / abs(b.denominator));
    this->denominator = leastCommonMultiple;

    if (!isValid())
    {
        throw "Invalid, zero denominator.";
    }

    reduce();

    return *this;
}

RationalNumber &RationalNumber::multiply(const RationalNumber &b)
{
    this->numerator *= b.numerator;
    this->denominator *= b.denominator;

    if (!isValid())
    {
        throw "Invalid, zero denominator.";
    }

    reduce();

    return *this;
}

RationalNumber &RationalNumber::divide(const RationalNumber &b)
{
    this->numerator *= b.denominator;
    this->denominator *= b.numerator;

    if (!isValid())
    {
        throw "Invalid, zero denominator.";
    }

    reduce();

    return *this;
}

bool RationalNumber::operator==(const RationalNumber &right) const
{
    if ((getDenominator() != right.getDenominator()) || (getNumerator() != right.getNumerator()))
    {
        return false;
    }

    return true;
}

bool RationalNumber::operator!=(const RationalNumber &right) const
{
    return (!operator==(right));
}

bool RationalNumber::operator<(const RationalNumber &right) const
{
    return (!operator>(right) && !operator==(right));
}

bool RationalNumber::operator<=(const RationalNumber &right) const
{
    return (operator<(right) || operator==(right));
}

bool RationalNumber::operator>(const RationalNumber &right) const
{
    RationalNumber temp = *this - right;

    if (temp.getDenominator() * temp.getNumerator() > 0)
    {
        return true;
    }

    return false;
}

bool RationalNumber::operator>=(const RationalNumber &right) const
{
    return (operator>(right) || operator==(right));
}

RationalNumber RationalNumber::operator+(const RationalNumber &right) const
{
    RationalNumber temp(*this);
    temp.add(right);

    return temp;
}

RationalNumber RationalNumber::operator-(const RationalNumber &right) const
{
    RationalNumber temp(*this);
    temp.subtract(right);

    return temp;
}

RationalNumber RationalNumber::operator*(const RationalNumber &right) const
{
    RationalNumber temp(*this);
    temp.multiply(right);

    return temp;
}

RationalNumber RationalNumber::operator/(const RationalNumber &right) const
{
    RationalNumber temp(*this);
    temp.divide(right);

    return temp;
}

void RationalNumber::print() const
{
    if (0 == denominator)
    {
        std::cout << "Error, zero denorminator\n";
    }
    else
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
}

void RationalNumber::printFloat() const
{
    if (0 == denominator)
    {
        std::cout << "Error, zero denorminator\n";
    }
    else
    {
        std::cout << static_cast<double>(numerator) / static_cast<double>(denominator) << std::endl;
    }
}

int RationalNumber::getNumerator() const
{
    return this->numerator;
}

int RationalNumber::getDenominator() const
{
    return this->denominator;
}

void RationalNumber::reduce()
{
    unsigned int greatestCommonDivisor = gcd(abs(numerator), abs(denominator));

    numerator /= static_cast<int>(greatestCommonDivisor);
    denominator /= static_cast<int>(greatestCommonDivisor);

    if (denominator < 0)
    {
        denominator = -denominator;
        numerator = -numerator;
    }
}

unsigned int RationalNumber::gcd(unsigned int n, unsigned int m) const
{
    unsigned int temp = n;
    if (n < m)
    {
        temp = n;
        n = m;
        m = temp;
    }

    unsigned int greatestCommonDivisor = 1;

    for (unsigned int i = 1; i <= m; ++i)
    {
        if (0 == n % i && 0 == m % i)
        {
            greatestCommonDivisor = i;
        }
    }

    return greatestCommonDivisor;
}

unsigned int RationalNumber::lcm(unsigned int a, unsigned int b) const
{
    unsigned int max = 0, min = 0;

    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }

    for (unsigned int i = 1; i <= max; ++i)
    {
        if (0 == ((max % i) % min))
        {
            return max * i;
        }
    }

    return a * b;
}

bool RationalNumber::isValid() const
{
    return (!(0 == denominator));
}
