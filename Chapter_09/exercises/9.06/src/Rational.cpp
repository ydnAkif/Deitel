#include <iostream>
#include "Rational.hpp"

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
}

Rational::~Rational() {}

Rational Rational::addition(const Rational &a)
{
    Rational t;
    t.numerator = numerator * a.denominator + denominator * a.numerator;
    t.denominator = a.denominator * denominator;
    t.reduction();

    return t;
}

Rational Rational::subtraction(const Rational &s)
{
    Rational t;
    t.numerator = numerator * s.denominator - denominator * s.numerator;
    t.denominator *= s.denominator * denominator;
    t.reduction();

    return t;
}

Rational Rational::multiplication(const Rational &m)
{
    Rational t;
    t.numerator = m.numerator * numerator;
    t.denominator = m.denominator * denominator;
    t.reduction();

    return t;
}

Rational Rational::division(const Rational &q)
{
    Rational t;
    t.numerator = q.denominator * numerator;
    t.denominator = q.numerator * denominator;
    t.reduction();

    return t;
}

void Rational::printRational(void) const
{
    if (denominator == 0)
        std::cout << "\nDIVIDE BY ZERO ERROR!!!" << std::endl;
    else if (numerator == 0)
        std::cout << 0;
    else
        std::cout << numerator << '/' << denominator;
}

void Rational::printRationalAsDouble(void) const
{
    std::cout << static_cast<double>(numerator) / denominator;
}

void Rational::reduction(void)
{
    int largest;

    largest = numerator > denominator ? numerator : denominator;

    int gcd = 0;

    for (int loop = 2; loop <= largest; ++loop)
        if (numerator % loop == 0 && denominator % loop == 0)
            gcd = loop;

    if (gcd != 0)
    {
        numerator /= gcd;
        denominator /= gcd;
    }
}
