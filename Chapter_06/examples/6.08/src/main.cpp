#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
    for (unsigned int counter = 1; counter <= 20; ++counter)
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