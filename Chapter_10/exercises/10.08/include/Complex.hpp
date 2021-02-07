#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);

private:
    double real;
    double imaginary;

public:
    explicit Complex(double = 0, double = 0);
    ~Complex();

    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;
    Complex operator/(const Complex &) const;

    bool operator==(const Complex &) const;
    bool operator!=(const Complex &) const;

    double getReal() const;
    double getImaginary() const;

    void setReal(double);
    void setImaginary(double);
    void print() const;
};

#endif