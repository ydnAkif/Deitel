#include <iostream>

int main()
{
    int c = 5;

    std::cout << c
              << std::endl;

    std::cout << c++
              << std::endl;

    std::cout << c
              << std::endl;

    std::cout << std::endl;

    c = 5;

    std::cout << c
              << std::endl;

    std::cout << ++c
              << std::endl;

    std::cout << c
              << std::endl;

    std::cout << std::endl;

    std::cin.get();

    return 0;
}