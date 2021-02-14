#include <iostream>

int main(int argc, char const *argv[])
{
    int x = 100;

    std::cout << "Printing integers preceeded by their base:" << std::endl
              << std::showbase;

    std::cout << x << std::endl;

    std::cout << std::oct << x << std::endl;
    std::cout << std::hex << x << std::endl;

    return 0;
}
