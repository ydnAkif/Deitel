#include <iostream>

int main()
{
    unsigned int counter{1};

    while (counter <= 10)
    {
        std::cout << counter << " ";
        ++counter;
    }
    std::cout << std::endl;

    return 0;
}