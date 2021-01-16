#include <iostream>
#include "Rational.hpp"

int main(int argc, char const *argv[])
{
    Rational c(4, 3), d(7, 8), x;

    c.printRational();
    std::cout << " + ";
    d.printRational();
    x = c.addition(d);
    std::cout << " = ";
    x.printRational();
    std::cout << std::endl;
    x.printRational();
    std::cout << " = ";
    x.printRationalAsDouble();
    std::cout << std::endl
              << std::endl;

    c.printRational();
    std::cout << " - ";
    d.printRational();
    x = c.subtraction(d);
    std::cout << " = ";
    x.printRational();
    std::cout << std::endl;
    x.printRational();
    std::cout << " = ";
    x.printRationalAsDouble();
    std::cout << std::endl
              << std::endl;

    c.printRational();
    std::cout << " x ";
    d.printRational();
    x = c.multiplication(d);
    std::cout << " = ";
    x.printRational();
    std::cout << std::endl;
    x.printRational();
    std::cout << " = ";
    x.printRationalAsDouble();
    std::cout << std::endl
              << std::endl;

    c.printRational();
    std::cout << " / ";
    d.printRational();
    x = c.division(d);
    std::cout << " = ";
    x.printRational();
    std::cout << std::endl;
    x.printRational();
    std::cout << " = ";
    x.printRationalAsDouble();
    std::cout << std::endl
              << std::endl;
    return 0;
}
