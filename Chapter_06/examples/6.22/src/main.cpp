#include <iostream>

int number = 7;
int main()
{
    double number = 10.5;

    std::cout << "Local double valur of number = "
              << number
              << std::endl
              << "Global int value of number = "
              << ::number
              << std::endl;
}