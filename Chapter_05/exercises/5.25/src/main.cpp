#include <iostream>

int main()
{
    int counter{1};
    bool exit{false};

    while (!exit)
    {

        std::cout << counter << " ";
        ++counter;
        exit = (counter == 5);
    }

    std::cout << std::endl
              << "Broke out of loop at count = " << counter << std::endl;

    return 0;
}