#include <iostream>
#include <iomanip>
#include <cstring>

const int SIZE = 6;

int main(int argc, char const *argv[])
{
    char stringValue[SIZE];
    double sum = 0.0;

    for (int i = 1; i <= 4; ++i)
    {
        std::cout << "Enter a floating point value: ";
        std::cin >> stringValue;
        sum += atof(stringValue);
    }

    std::cout << std::fixed << "\nThe total of the values is " << std::setprecision(3) << sum << std::endl;

    return 0;
}
