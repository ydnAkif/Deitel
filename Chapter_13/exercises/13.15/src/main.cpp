#include <iostream>
#include "Point.hpp"

int main(int argc, char const *argv[])
{
    Point pt;

    std::cout << "Enter a point in the form (x, y):\n";
    std::cin >> pt;

    std::cout << "Point entered was: " << pt << std::endl;

    return 0;
}
