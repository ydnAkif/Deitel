#include <iostream>
#include <iomanip>
#include <cstring>

const int SIZE = 80;

int main(int argc, char const *argv[])
{
    char string[SIZE];
    int stringLenght;

    std::cout << "Enter a string: ";
    std::cin >> string;

    stringLenght = strlen(string);

    std::cout << "the lenght of the string is " << strlen(string) << std::endl;

    std::cout << std::setw(2 * stringLenght) << string << std::endl;

    return 0;
}
