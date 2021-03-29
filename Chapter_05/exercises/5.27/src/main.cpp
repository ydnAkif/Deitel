#include <iostream>

int main()
{
    for (int counter = 1; counter <= 10; ++counter)
    {
        if (counter != 5)
        {
            std::cout << counter << " ";
        }
    }
    std::cout << std::endl
              << "Skipped printing 5 without continue"
              << std::endl;

    return 0;
}