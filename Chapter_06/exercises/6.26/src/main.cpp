#include <iostream>
#include <iomanip>

double celsiusToFahrenheit(double);
double fahrenheitToCelsius(double);

int main()
{

    // Celcius to Fahrenheit
    std::cout << "Fahrenheit equivalent of Celsius 0 to 100"
              << std::endl
              << std::endl;
    std::cout << std::setw(10)
              << "Celsius"
              << std::setw(18)
              << "Fahrenheit"
              << std::fixed
              << std::setprecision(1)
              << std::endl;

    for (unsigned int c = 0; c <= 100; ++c)
    {
        std::cout << std::setw(10)
                  << static_cast<double>(c)
                  << std::setw(18)
                  << fahrenheitToCelsius(static_cast<double>(c))
                  << std::endl;
    }

    std::cout << std::endl;

    // Fahrenheit to Celsius
    std::cout << "Celsius equivalent of Fahrenheit 32 to 212"
              << std::endl
              << std::endl;
    std::cout << "Fahrenheit"
              << std::setw(18)
              << "Celsius"
              << std::fixed
              << std::setprecision(1)
              << std::endl;

    for (unsigned int f = 32; f <= 212; ++f)
    {
        std::cout << std::setw(10)
                  << static_cast<double>(f)
                  << std::setw(18)
                  << celsiusToFahrenheit(static_cast<double>(f))
                  << std::endl;
    }

    return 0;
}

double celsiusToFahrenheit(double f)
{
    return (((f - 32) / 180) * 100);
}
double fahrenheitToCelsius(double c)
{
    return (((c * 180) / 100) + 32);
}