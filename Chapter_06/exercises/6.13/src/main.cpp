#include <iostream>
#include <cmath>

int main()
{
    double num{0.0f};

    std::cout << "Program to round number to the nearest integer"
              << std::endl;

    while (num != -1)
    {
        std::cout << "Enter a number to round (-1 to exit): ";
        std::cin >> num;

        if (num == -1)
        {
            break;
        }

        std::cout << "num: "
                  << num
                  << std::endl
                  << "rounded: "
                  << floor(num + 0.5f)
                  << std::endl;
    }

    return 0;
}
