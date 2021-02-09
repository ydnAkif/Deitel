#include <iostream>
#include "Polynomial.hpp"

int main(int argc, char const *argv[])
{

    Polynomial a, b, c, t;

    a.enterTerms();
    b.enterTerms();
    t = a;
    std::cout << "First polynomial is:\n";
    a.printPolynomial();

    std::cout << "Second polynomial is:\n";
    b.printPolynomial();
    std::cout << "\nAdding the polynomials yields:\n";
    c = a + b;
    c.printPolynomial();
    std::cout << "\n+= the polynomials yields:\n";
    a += b;
    a.printPolynomial();
    std::cout << "\nSubtracting the polynomials yields:\n";
    a = t;
    c = a - b;
    c.printPolynomial();
    std::cout << "\n-= the polynomials yields:\n";
    a -= b;
    a.printPolynomial();
    std::cout << "\nMultiplying the polynomials yields:\n";
    a = t;
    c = a * b;
    c.printPolynomial();
    std::cout << "\n*= the polynomials yields:\n";
    a *= b;
    a.printPolynomial();
    std::cout << std::endl;

    return 0;
}
