#include <iostream>
#include <cmath>

bool isTriangle(int, int, int);


int main(int argc, char const *argv[])
{
    int a{ 0 }, b{ 0 }, c{ 0 };

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

bool isTriangle(int a, int b, int c)
{
    if (((a+b)> c) && ((a+c)> b) && ((b+c)> a) && (abs(a-b)< c) && (abs(a-c)< b) && (abs(c-b)< a))
    {
        return true;
    }

    return false;

}