#include <iostream>

int main(int argc, char const *argv[])
{
    bool booleanValue = true;

    std::cout << "booleanValue is " << booleanValue << std::endl;

    std::cout << "booleanValue (after using boolalpha) is "
              << std::boolalpha << booleanValue << std::endl
              << std::endl;

    std::cout << "switch booleanValue and use noboolalpha" << std::endl;
    booleanValue = false;

    std::cout << std::noboolalpha << std::endl;

    std::cout << "booleanValue is " << booleanValue << std::endl;

    std::cout << "booleanValue (after using boolalpha) is "
              << std::boolalpha << booleanValue << std::endl;

    return 0;
}
