#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    int widthvalue = 4;
    char sentence[10];

    std::cout << "Enter a sentence:" << std::endl;
    std::cin.width(5);

    while (std::cin >> sentence)
    {
        std::cout.width(widthvalue++);
        std::cout << sentence << std::endl;
        std::cin.width(5);
    }

    return 0;
}
