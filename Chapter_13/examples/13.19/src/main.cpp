#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "Printing uppercase letters in scientific" << std::endl
              << "notation exponents and hexadecimal values:" << std::endl;

    std::cout << std::uppercase << 4.345e10 << std::endl
              << std::hex << std::showbase << 123456789 << std::endl;

    return 0;
}
