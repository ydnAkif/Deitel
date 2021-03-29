#include "Complex.hpp"

Complex::Complex(double r, double i)
{
    setComplexNumber(r, i);
}

Complex::~Complex() {}

void Complex::addition(const Complex &a)
{
    realPart += a.realPart;
    imaginaryPart += a.imaginaryPart;
}

void Complex::subtraction(const Complex &s)
{
    realPart -= s.realPart;
    imaginaryPart -= s.imaginaryPart;
}

void Complex::printComplex() const
{
    std::cout << '(' << realPart << ',' << imaginaryPart << ')';
}

void Complex::setComplexNumber(double r, double i)
{
    realPart = r;
    imaginaryPart = i;
}