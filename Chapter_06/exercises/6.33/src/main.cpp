#include <iostream>
#include <random>
#include <ctime>

std::default_random_engine engine(static_cast<int>(time(0)));

const int NUM_FLIPS{100};
int flip(void);

int main()
{
    int heads{0}, tails{0};

    std::cout << "Program to simulate coin tossing"
              << std::endl
              << std::endl;

    for (unsigned int i = 1; i <= NUM_FLIPS; ++i)
    {
        std::cout << i
                  << " : ";

        if (flip() == 1)
        {
            std::cout << "heads"
                      << std::endl;
            ++heads;
        }
        else
        {
            std::cout << "tails"
                      << std::endl;
            ++tails;
        }
    }

    std::cout << std::endl
              << "Heads: "
              << heads
              << std::endl
              << "Tails: "
              << tails
              << std::endl;

    return 0;
}

int flip(void)
{
    return std::uniform_int_distribution<int>{0, 1}(engine);
}