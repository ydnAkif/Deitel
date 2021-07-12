/******************************************************************************
 
 Exercises 4.37
 
(World Population Growth) World population has grown considerably over the 
centuries. Continued growth could eventually challenge the limits of breathable 
air, drinkable water, arable cropland and other precious resources. There is 
evidence that growth has been slowing in recent years and that world population 
could peak some time this century, then start to decline.
For this exercise, research world population growth issues online. Be sure to 
investigate various viewpoints. Get estimates for the current world population 
and its growth rate (the percentage by which it is likely to increase this year). 
Write a program that calculates world population growth each year for the next 
75 years, using the simplifying assumption that the current growth rate will stay 
constant. Print the results in a table. The first column should display the year 
from year 1 to year 75. The second column should display the anticipated world 
population at the end of that year. The third column should display the numerical 
increase in the world population that would occur that year. Using your results, 
determine the year in which the population would be double what it is today, 
if this year’s growth rate were to persist.
  
******************************************************************************/

#include <iostream>
#include <iomanip>
int main()
{
    long long int basePopulation{7804429900};
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
