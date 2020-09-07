#include <iostream>
#include <iomanip>
#include <cmath>

double getHypotenuse(double, double);

int main()
{

    std::cout << "A program to calculate the hypotenuse of a right triangle"
              << std::endl;


    std::cout << std::endl
              << "Triangle"
              << std::setw(10)
              << "Side1"
              << std::setw(10)
              << "Side2"
              << std::setw(15)
              << "Hypotenuse"
              << std::endl;
    std::cout << "1"
              << std::setw(15)
              << "3.0"
              << std::setw(10)
              << "4.0"
              << std::setw(8)
              << getHypotenuse(3.0, 4.0)
              << std::endl;
    std::cout << "2"
              << std::setw(15)
              << "5.0"
              << std::setw(11)
              << "12.0"
              << std::setw(8)
              << getHypotenuse(5.0, 12.0)
              << std::endl;
    std::cout << "3"
              << std::setw(15)
              << "8.0"
              << std::setw(11)
              << "15.0"
              << std::setw(8)
              << getHypotenuse(8.0, 15.0)
              << std::endl;

    return 0;
}

double getHypotenuse(double a, double b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}