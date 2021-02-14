#include <iostream>
#include "Complex.hpp"

int main(int argc, char const *argv[])
{
    Complex complex;

    std::cout << "Input a complex number in the form A + Bi:\n";
    std::cin >> complex;

    std::cout << "Complex number entered was:\n"
              << complex << std::endl;

    return 0;
}
