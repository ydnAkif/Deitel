#include <iostream>

int main()
{
    unsigned int counter{1};

    do
    {
        std::cout << counter
                  << " ";
        ++counter;
    } while (counter <= 10);

    std::cout << std::endl;
}