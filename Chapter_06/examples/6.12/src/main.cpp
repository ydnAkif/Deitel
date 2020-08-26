#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>

int main()
{
    std::default_random_engine engine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<unsigned int> randomInt(1, 6);

    for (unsigned int counter = 1; counter <= 10; ++counter)
    {
        std::cout << std::setw(10)
                  << randomInt(engine);

        if (counter % 5 == 0)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}