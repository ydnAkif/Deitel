#include <iostream>
#include <random>
#include <ctime>

std::default_random_engine engine(static_cast<int>(time(0)));

int getRandomNumber(const int &, const int &);

int main()
{
    std::cout << "Program to assign random integers to variables in the "
                 "following ranges"
              << std::endl;

    std::cout << "1 <= n <= 2: "
              << getRandomNumber(1, 2)
              << std::endl
              << "1 <= n <= 100: "
              << getRandomNumber(1, 100)
              << std::endl
              << "0 <= n <= 9: "
              << getRandomNumber(0, 9)
              << std::endl
              << "1000 <= n <= 1112: "
              << getRandomNumber(1000, 1112)
              << std::endl
              << "-1 <= n <= 1: "
              << getRandomNumber(-1, 1)
              << std::endl
              << "-3 <= n <= 11: "
              << getRandomNumber(-3, 11)
              << std::endl;

    return 0;
}

int getRandomNumber(const int &min, const int &max)
{
    std::uniform_int_distribution<int> randomInt(min, max);
    return randomInt(engine);
}