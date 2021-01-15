#include "Complex.hpp"

Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}

Complex::~Complex() {}

std::ostream &Complex::printComplex(std::ostream &out)
{
    out << "(" << real << "," << imaginary << ")";
    return out;
}