#include <iostream>
#include <iomanip>

double minimum(double, double, double);
int main()
{
    double d1, d2, d3;
    std::cout << "A Program to find the smallest of 3 doubles"
              << std::endl
              << std::endl;

    std::cout << "Enter three double values : ";
    std::cin >> d1 >> d2 >> d3;

    std::cout << std::fixed
              << std::setprecision(1)
              << "Smallest: "
              << minimum(d1, d2, d3)
              << std::endl;

    return 0;
}

double minimum(double d1, double d2, double d3)
{
    double min = d1 < d2 ? d1 : d2;
    return (d3 < min ? d3 : min);
}