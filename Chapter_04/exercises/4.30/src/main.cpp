#include <iostream>

const static double PI = 3.14159;

double getCircleCircumference(double);
double getCircleArea(double);
double getDiameter(double);
void printCircle(double);


int main(int argc, char const *argv[])
{
    double radius{ 0 };
    std::cout << "Program to calculate a Circle's Diameter, Circumference and Area"
        << std::endl
        << std::endl;
    std::cout << "Enter the radius of circle : ";
    std::cin >> radius;

    printCircle(radius);

    return 0;

}

double getCircleCircumference(double r)
{
    return (2*PI*r);
}

double getCircleArea(double r)
{
    return (PI*r*r);
}

double getDiameter(double r)
{
    return 2*r;
}

void printCircle(double r)
{
    std::cout << std::endl
        << "Circle's Diameter          : "
        << getDiameter(r)
        << std::endl;

    std::cout << "Circle's Circumference     : "
        << getCircleCircumference(r)
        << std::endl;

    std::cout << "Circle's Area              : "
        << getCircleArea(r)
        << std::endl;
}