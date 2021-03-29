#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int counter{0};
    int number{0};
    int firstLargest{0};
    int secondLargest{0};

    std::cout << "Program to find the Largest of 10 numbers\n"
              << std::endl;

    while (counter < 10)
    {
        std::cout << "Enter the number ("
                  << std::setw(2)
                  << 10 - counter
                  << " remaining): ";
        std::cin >> number;

        if (firstLargest <= number)
        {
            secondLargest = firstLargest;
            firstLargest = number;
        }
        else if (secondLargest <= number)
        {
            secondLargest = number;
        }

        ++counter;
    }

    std::cout << "First Largest Number is "
              << firstLargest
              << std::endl;
    std::cout << "Second Largest Number is "
              << secondLargest
              << std::endl;

    return 0;
}
