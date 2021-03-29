#include <iostream>
#include <cmath>

bool isTriangle(double, double, double);


int main(int argc, char const *argv[])
{
    double a{ 0.0 }, b{ 0.0 }, c{ 0.0 };

    std::cout << "Program to determine if 3 values make a tirangle."
        << std::endl;
    std::cout << "Enter 3 nonzero integers: ";
    std::cin >> a >> b >> c;

    std::cout << a << ","
        << b
        <<","
        << c
        << " could "
        << (isTriangle(a, b, c) ? " ": " not ")
        << "represent a triangle"
        << std::endl;


    return 0;

}

bool isTriangle(double a, double b, double c)
{
    if (((a+b)> c) && ((a+c)> b) && ((b+c)> a) && (abs(a-b)< c) && (abs(a-c)< b) && (abs(c-b)< a))
    {
        return true;
    }

    return false;

}