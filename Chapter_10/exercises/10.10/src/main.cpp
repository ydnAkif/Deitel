#include <iostream>
#include "RationalNumber.hpp"

int main(int argc, char const *argv[])
{
    RationalNumber rn1(1, 3);
    RationalNumber rn2(4, 3);

    (rn1 + rn2).print();
    (rn1 + rn2).printFloat();
    std::cout << std::endl;
    (rn1 - rn2).print();
    (rn1 - rn2).printFloat();
    std::cout << std::endl;
    (rn1 * rn2).print();
    (rn1 * rn2).printFloat();
    std::cout << std::endl;
    (rn1 / rn2).print();
    (rn1 / rn2).printFloat();

    return 0;
}
