#include <iostream>

int main()
{
    unsigned int counter{1};

    for (counter = 1; counter <= 10; ++counter)
    {
        if (counter == 5)
        {
            continue;
        }

        std::cout << counter << " ";
    }

    std::cout << "\nUsed continue to skip printing 5" << std::endl;

    return 0;
}