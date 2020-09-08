#include <iostream>

bool isEven(int); // inline bool isEven(int x) {return (x%2==0);}
int main()
{
    int input = 0;

    std::cout << "A program to determine whether an integer is even"
              << std::endl
              << std::endl;

    while (input >= 0)
    {
        std::cout << "Enter an integer (-1 to quit): ";
        std::cin >> input;
        if (input >= 0)
        {
            std::cout << input
                      << " : "
                      << (isEven(input) ? "" : " not")
                      << " even"
                      << std::endl;
        }
    }

    return 0;
}

bool isEven(int x)
{
    return (x % 2 == 0);
}