#include <iostream>

unsigned int boxVolume(unsigned int length = 1,
                       unsigned int width = 1,
                       unsigned int height = 1);

int main()
{
    std::cout << "The dafault box volume is: "
              << boxVolume();
    std::cout << std::endl
              << std::endl
              << "The volume of a box with length 10,"
              << std::endl
              << "width 1 and height 1 is: " << boxVolume(10);

    std::cout << std::endl
              << std::endl
              << "The volume of a box with length 10,"
              << std::endl
              << "width 5 and height 1 is: " << boxVolume(10, 5);

    std::cout << std::endl
              << std::endl
              << "The volume of a box with length 10,"
              << std::endl
              << "width 5 and height 2 is: " << boxVolume(10, 5, 2);
}

unsigned int boxVolume(unsigned int length,
                       unsigned int width,
                       unsigned int height)
{
    return length * width * height;
}