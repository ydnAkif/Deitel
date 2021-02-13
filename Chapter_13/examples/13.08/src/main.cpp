#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int number;

    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    std::cout << number << " in hexadecimal is "
              << std::hex << number << std::endl;

    std::cout << std::dec << number << " in octal is "
              << std::oct << number << std::endl;

    std::cout << std::setbase(10) << number << " in decimal is: " << number << std::endl;

    return 0;
}
