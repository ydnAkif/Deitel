#include <iostream>
#include <iomanip>
#include <cstring>

const int SIZE = 20;

int main(int argc, char const *argv[])
{
    int c;

    std::cout << "Enter an ASCII character code(-1 to end): ";
    std::cin >> c;

    while (c != -1)
    {
        if (c >= 0 && c <= 255)
            std::cout << "The corresponding character is '"
                      << static_cast<char>(c) << "\'\n";
        else
            std::cout << "Invalid character code\n";

        std::cout << "\nEnter an ASCII character code(-1 to end): ";
        std::cin >> c;
    }

    for (int c = 0; c <= 255; ++c)
    {
        if (c % 7 == 0)
            std::cout << '\n';
        std::cout << std::setw(6) << c << std::setw(3) << static_cast<char>(c);
    }

    std::cout << std::endl;

    return 0;
}
