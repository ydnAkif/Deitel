#include <iostream>

int main(int argc, char const *argv[])
{
    const int SIZE = 80;

    char buffer[SIZE];

    std::cout << "Enter a sentence:" << std::endl;
    std::cin.getline(buffer, SIZE);

    std::cout << "\nThe sentence entered is:" << std::endl
              << buffer << std::endl;

    return 0;
}
