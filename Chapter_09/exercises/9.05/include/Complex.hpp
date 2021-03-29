#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
private:
    double realPart;
    double imaginaryPart;

public:
    explicit Complex(double = 0.0, double = 0.0);
    ~Complex();

    void addition(const Complex &);
    void subtraction(const Complex &);
    void printComplex() const;
    void setComplexNumber(double, double);
};

#endif