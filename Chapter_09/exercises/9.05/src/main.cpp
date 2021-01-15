#include "Complex.hpp"

int main(int argc, char const *argv[])
{
    Complex complex1;
    Complex complex2(123, 456);

    Complex complex3 = (complex1 + complex2);

    std::cout << "complex1: " << complex1
              << "\ncomplex2: " << complex2
              << "\ncomplex3: " << complex3
              << std::endl;

    return 0;
}
