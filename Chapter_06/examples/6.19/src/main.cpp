#include <iostream>

inline double cube(const double side)
{
    return side * side * side;
}

int main()
{
    double sideValue;

    std::cout << "Enter the side length of cube: ";
    std::cin >> sideValue;

    std::cout << "Volume of cube with side "
              << sideValue
              << " is "
              << cube(sideValue)
              << std::endl;

    return 0;
}