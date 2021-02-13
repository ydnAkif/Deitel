#include <iostream>

int main(int argc, char const *argv[])
{
    int character;

    std::cout << "Before input, std::cin.eof() is " << std::cin.eof() << std::endl
              << "Enter a sentence followed by end-of-file:" << std::endl;
    while ((character = std::cin.get()) != EOF)
        std::cout.put(character);

    std::cout << "\nEOF in this system is: " << character << std::endl;
    std::cout << "After input of EOF, std::cin.eof() is " << std::cin.eof() << std::endl;

    return 0;
}
