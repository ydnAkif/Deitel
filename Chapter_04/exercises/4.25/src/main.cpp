#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned int counter{0};

    std::cout << "Program yo print a square of asterisks\n"
              << std::endl;

    while (true)
    {
        std::cout << "Enter a number between 1-20 : ";
        std::cin >> counter;

        if (counter > 0 && counter <= 20)
        {
            break;
        }
    }
    for (size_t i = 0; i < counter; ++i)
    {
        if (counter > 1)
        {
            std::cout << "*";
        }
        for (size_t j = 1; j < counter - 1; ++j)
        {
            if (i == 0 || i == counter - 1)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "*"
                  << std::endl;
    }

    return 0;
}
