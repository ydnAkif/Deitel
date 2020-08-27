#include <iostream>
#include "Maximum.hpp"

int main()
{
    int int1, int2, int3;

    std::cout << "Enter 3 integer values : ";
    std::cin >> int1 >> int2 >> int3;
    std::cout << "The Maximum integer value is "
              << maximum(int1, int2, int3)
              << std::endl
              << std::endl;

    double double1, double2, double3;

    std::cout << "Enter 3 double values : ";
    std::cin >> double1 >> double2 >> double3;
    std::cout << "The Maximum double value is "
              << maximum(double1, double2, double3)
              << std::endl
              << std::endl;

    char char1, char2, char3;

    std::cout << "Enter 3 char values : ";
    std::cin >> char1 >> char2 >> char3;
    std::cout << "The Maximum char value is "
              << maximum(char1, char2, char3)
              << std::endl
              << std::endl;

    return 0;
}