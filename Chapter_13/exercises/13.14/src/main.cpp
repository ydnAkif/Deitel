#include <iostream>
#include "PhoneNumber.hpp"

int main(int argc, char const *argv[])
{
    PhoneNumber telephone;

    std::cout << "Enter a phone number in the form (123) 456-7890:\n";
    std::cin >> telephone;

    std::cout << "The phone number entered was: " << telephone << std::endl;

    std::cout << "Now enter an invalid phone number:\n";
    std::cin >> telephone;

    return 0;
}
