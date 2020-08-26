#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
    unsigned int frequency1{0};
    unsigned int frequency2{0};
    unsigned int frequency3{0};
    unsigned int frequency4{0};
    unsigned int frequency5{0};
    unsigned int frequency6{0};

    for (unsigned int roll{1}; roll < 6'000'000; ++roll)
    {
        unsigned int face = 1 + rand() % 6;

        switch (face)
        {
        case 1:
            ++frequency1;
            break;
        case 2:
            ++frequency2;
            break;
        case 3:
            ++frequency3;
            break;
        case 4:
            ++frequency4;
            break;
        case 5:
            ++frequency5;
            break;
        case 6:
            ++frequency6;
            break;
        default:
            std::cout << "Program should never get here!";
        }
    }

    std::cout << "Face"
              << std::setw(13)
              << "Frequency"
              << std::endl;
    std::cout << "   1"
              << std::setw(13)
              << frequency1
              << std::endl;
    std::cout << "   2"
              << std::setw(13)
              << frequency2
              << std::endl;
    std::cout << "   3"
              << std::setw(13)
              << frequency3
              << std::endl;
    std::cout << "   4"
              << std::setw(13)
              << frequency4
              << std::endl;
    std::cout << "   5"
              << std::setw(13)
              << frequency5
              << std::endl;
    std::cout << "   6"
              << std::setw(13)
              << frequency6
              << std::endl;
    return 0;
}