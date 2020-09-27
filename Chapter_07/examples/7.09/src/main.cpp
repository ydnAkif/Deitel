#include <iostream>
#include <iomanip>
#include <array>

int main(int argc, char const *argv[])
{

    const size_t arraySize = 11;

    std::array<int, arraySize> n = {0, 0, 0, 0, 0, 0, 1, 2, 4, 2, 1};

    std::cout << "Grade distiribution:"
              << std::endl;
    for (size_t i = 0; i < n.size(); ++i)
    {
        if (0 == i)
        {
            std::cout << "  0-9: ";
        }
        else if (10 == i)
        {
            std::cout << "  100: ";
        }
        else
        {
            std::cout << i * 10
                      << "-"
                      << (i * 10) + 9
                      << ": ";
        }

        for (unsigned int stars = 0; stars < n[i]; ++stars)
        {
            std::cout << '*';
        }

        std::cout << std::endl;
    }

    return 0;
}
