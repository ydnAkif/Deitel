#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int counter = 0;
    int number = 0;
    int largest = 0;

    std::cout << "Program to find the largest of 10 numbers\n"
              << std::endl;

    while (counter < 10)
    {
        std::cout << "Enter number ("
                  << std::setw(2)
                  << (10 - counter)
                  << " remaning ) : ";
        std::cin >> number;

        largest = (largest > number) ? largest : number;

        ++counter;
    }

    std::cout << "Largest Number              : "
              << largest
              << std::endl;

    return 0;
}
