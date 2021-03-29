#include "Complex.hpp"

int main(int argc, char const *argv[])
{
    Complex b(1, 7), c(9, 2);

    b.printComplex();
    std::cout << " + ";
    c.printComplex();
    std::cout << " = ";
    b.addition(c);
    b.printComplex();

    std::cout << std::endl;
    b.setComplexNumber(10, 1);
    c.setComplexNumber(11, 5);

    b.printComplex();
    std::cout << " - ";
    c.printComplex();
    std::cout << " = ";
    b.subtraction(c);
    b.printComplex();
    std::cout << std::endl;

    return 0;
}
