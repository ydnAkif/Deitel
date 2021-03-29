#include <iostream>

void printLine(int);
int main()
{
    int counter{5};
    int value{0};

    std::cout << "Program to print bar chart of entered values\n"
              << std::endl;
    while (counter > 0)
    {
        std::cout << "Enter an integer between 1-30 ("
                  << counter
                  << " remaining): ";

        std::cin >> value;

        if (value >= 1 && value <= 30)
        {
            printLine(value);
            counter--;
        }
        else
        {
            std::cout << "Incorrect value entered!"
                      << std::endl;
        }
    }

    return 0;
}

void printLine(int value)
{
    for (int i = 0; i < value; ++i)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}