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

    std::cout << "2, 4, 6, 8, 10 : " // 2n
              << getRandomNumber(1, 5) * 2
              << std::endl
              << "3, 5, 7, 9, 11 : " //2n+1
              << getRandomNumber(1, 5) * 2 + 1
              << std::endl
              << "6, 10 ,14 , 18 , 22 : " // 4n+2
              << getRandomNumber(1, 5) * 4 + 2
              << std::endl;

    return 0;
}

int getRandomNumber(const int &min, const int &max)
{
    std::uniform_int_distribution<int> randomInt(min, max);
    return randomInt(engine);
}