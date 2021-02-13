#include <iostream>

int main(int argc, char const *argv[])
{
    const int SIZE = 80;

    char buffer[SIZE];

    std::cout << "Enter a sentence:" << std::endl;
    std::cin.read(buffer, 20);

    std::cout << std::endl
              << "The sentence entered was:" << std::endl;
    std::cout.write(buffer, std::cin.gcount());
    std::cout << std::endl;

    return 0;
}
