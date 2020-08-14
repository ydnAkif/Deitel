#include <iostream>

int main()
{
    int counter{0};
    int smallest{0};
    int current{0};

    std::cout << "Enter a list of space separated integers to determine smallest one."
              << std::endl;
    std::cout << "First input is number of separate entries..." << std::endl;
    std::cin >> counter;

    for (size_t i = 0; i < counter; ++i)
    {
        std::cin >> current;

        if ((current < smallest) || (i == 0))
        {
            smallest = current;
        }
    }

    std::cout << "Smallest one is " << smallest << std::endl;

    return 0;
}