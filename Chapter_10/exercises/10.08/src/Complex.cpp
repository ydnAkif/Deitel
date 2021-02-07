#include <iostream>
#include "Complex.hpp"

Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart)
{
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex &right) const
{
    double a = this->getReal();
    double b = this->getImaginary();
    double c = right.getReal();
    double d = right.getImaginary();

    Complex Addition;
    Addition.setReal(a + c);
    Addition.setImaginary(b + d);

    return Addition;
}

Complex Complex::operator-(const Complex &right) const
{
    double a = this->getReal();
    double b = this->getImaginary();
    double c = right.getReal();
    double d = right.getImaginary();

    Complex Subtraction;
    Subtraction.setReal(a - c);
    Subtraction.setImaginary(b - d);

    return Subtraction;
}

Complex Complex::operator*(const Complex &right) const
{
    double a = this->getReal();
    double b = this->getImaginary();
    double c = right.getReal();
    double d = right.getImaginary();

    Complex Multiplication;
    Multiplication.setReal(a * c - b * d);
    Multiplication.setImaginary(a * d + b * c);

    return Multiplication;
}

bool Complex::operator==(const Complex &right) const
{
    if (getReal() != right.getReal() || getImaginary() != right.getImaginary())
    {
        return false;
    }

    return true;
}

bool Complex::operator!=(const Complex &right) const
{
    return !operator==(right);
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImaginary() const
{
    return imaginary;
}

void Complex::setReal(double real)
{
    this->real = real;
}

void Complex::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
}

void Complex::print() const
{
    std::cout << '(' << real << ", " << imaginary << ')';
}

std::ostream &operator<<(std::ostream &output, const Complex &right)
{
    output << '(' << right.getReal() << ", " << right.getImaginary() << ')' << std::endl;

    return output;
}

std::istream &operator>>(std::istream &input, Complex &right)
{
    double real, imaginary;

    input >> real >> imaginary;

    right.setReal(real);
    right.setImaginary(imaginary);

    return input;
}
