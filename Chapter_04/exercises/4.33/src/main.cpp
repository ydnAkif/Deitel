#include <iostream>
#include <cmath>

bool isRightTriangle(int, int, int);


int main(int argc, char const *argv[])
{
    int a{ 0 }, b{ 0 }, c{ 0 };

    std::cout << "Program to determine if 3 values make a right triangle."
        << std::endl;
    std::cout << "Enter 3 nonzero integers: ";
    std::cin >> a >> b >> c;

    std::cout << a << ","
        << b
        <<","
        << c
        << " could "
        << (isRightTriangle(a, b, c) ? " ": " not ")
        << "represent a right triangle"
        << std::endl;

    return 0;

}

bool isRightTriangle(int a, int b, int c)
{
    if ((a*a+b*b==c*c)||(c*c+b*b==a*a)||(a*a+c*c==b*b))
    {
        return true;
    }

    return false;

}