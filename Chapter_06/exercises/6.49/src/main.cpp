#include <iostream>
#include <iomanip>

const double PI{3.14159};

inline double circleArea(double r)
{
    return (PI * (r * r));
}

int main()
{
    double radius;

    std::cout << "A program to print the area of a circle from the radius"
              << std::endl
              << std::endl;

    std::cout << "Enter circle radius : ";
    std::cin >> radius;

    std::cout << std::fixed
              << std::setprecision(2)
              << "Area: "
              << circleArea(radius)
              << std::endl;

    return 0;
}
