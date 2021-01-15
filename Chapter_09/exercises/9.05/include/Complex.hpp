#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
private:
    double real;
    double imaginary;

    std::ostream &printComplex(std::ostream &);

public:
    explicit Complex(double = 0, double = 0);
    ~Complex();

    Complex operator+(Complex c) const
    {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex operator-(Complex c) const
    {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    friend std::ostream &operator<<(std::ostream &out, Complex &c)
    {
        return c.printComplex(out);
    }
};

#endif