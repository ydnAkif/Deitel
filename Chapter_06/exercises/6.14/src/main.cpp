#include <iostream>
#include <cmath>

double roundToInteger(double);
double roundToTenths(double);
double roundToHundreths(double);
double roundToThousandths(double);

int main()
{
    double num{0.0f};

    std::cout << "Program to round numbers to int, 10s, 100 and 1000"
              << std::endl;
    std::cout << "Enter number to round (-1 to exit): ";
    std::cin >> num;

    while (num != -1)
    {
        std::cout << "Original: "
                  << num
                  << std::endl
                  << "roundToInteger: "
                  << roundToInteger(num)
                  << std::endl
                  << "roundToTenths: "
                  << roundToTenths(num)
                  << std::endl
                  << "roundToHundredths: "
                  << roundToHundreths(num)
                  << std::endl
                  << "roundToThousandths: "
                  << roundToThousandths(num)
                  << std::endl;

        std::cout << "Enter number to round (-1 to exit): ";
        std::cin >> num;
    }

    return 0;
}

double roundToInteger(double num)
{
    return floor(num + 0.5f);
}
double roundToTenths(double num)
{
    return floor(num * 10 + 0.5f) / 10;
}
double roundToHundreths(double num)
{
    return floor(num * 100 + 0.5f) / 100;
}
double roundToThousandths(double num) { return floor(num * 1000 + 0.5f) / 1000; }