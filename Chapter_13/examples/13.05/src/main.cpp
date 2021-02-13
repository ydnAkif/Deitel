#include <iostream>

int main(int argc, char const *argv[])
{
    const int SIZE = 80;

    char buffer1[SIZE];
    char buffer2[SIZE];

    std::cout << "Enter a sentence:" << std::endl;
    std::cin >> buffer1;

    std::cout << "\nThe string read with cin was:" << std::endl
              << buffer1 << std::endl
              << std::endl;
    std::cin.get(buffer2, SIZE);

    std::cout << "The string read with cin.get was:" << std::endl
              << buffer2 << std::endl;

    return 0;
}
