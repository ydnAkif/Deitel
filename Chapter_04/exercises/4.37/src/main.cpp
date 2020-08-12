#include <iostream>
#include <iomanip>
int main()
{
    long long int basePopulation{7'804'429'900};
    long long int population = basePopulation;
    long long int increase{0};

    double growthRate{0.0113f};
    int sample{0};

    std::cout << "Program to project world population"
              << std::endl
              << std::endl;
    std::cout << "Enter a sample size: ";
    std::cin >> sample;

    std::cout << std::endl
              << "*** Population projection for "
              << sample
              << " years ***"
              << std::endl;
    std::cout << std::setw(4)
              << "Year"
              << std::setw(18)
              << "Population"
              << std::setw(16)
              << "Increase"
              << std::endl;
    for (int i = 1; i <= sample; ++i)
    {
        increase = population * growthRate;
        if (population > basePopulation * 2)
        {
            std::cout << std::setw(4)
                      << i
                      << std::setw(18)
                      << population
                      << std::setw(16)
                      << increase
                      << std::setw(16)
                      << " - Population Doubled"
                      << std::endl;
        }
        else
        {
            std::cout << std::setw(4)
                      << i
                      << std::setw(18)
                      << population
                      << std::setw(16)
                      << increase
                      << std::endl;
        }

        population += increase;
    }

    return 0;
}
