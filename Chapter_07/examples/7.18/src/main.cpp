#include <iostream>
#include <array>

const size_t rows = 2;
const size_t columns = 3;

void printArray(const std::array<std::array<int, columns>, rows> &);

int main(int argc, char const *argv[])
{
    std::array<std::array<int, columns>, rows> array1 = {1, 2, 3, 4, 5, 6};
    std::array<std::array<int, columns>, rows> array2 = {1, 2, 3, 4, 5};

    std::cout << "Values in array1 by row are:" << std::endl;
    printArray(array1);

    std::cout << "\nValues in array2 by row are:" << std::endl;
    printArray(array2);

    return 0;
}

void printArray(const std::array<std::array<int, columns>, rows> &a)
{
    for (auto const &row : a)
    {
        for (auto const &element : row)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
}
