#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
    unsigned int seed{0};

    std::cout << "Enter seed: ";
    std::cin >> seed;
    srand(seed);

    for (unsigned int counter{1}; counter <= 10; ++counter)
    {
        std::cout << std::setw(10)
                  << (1 + rand() % 6);

        if (counter % 5 == 0)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}