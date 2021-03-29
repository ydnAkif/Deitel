#include <iostream>
#include <array>

const size_t SIZE = 15;
const size_t rows = 3;
const size_t columns = 5;
int main()
{
    std::array<std::array<int, rows>, columns> sales;

    std::cout << "A program to label the elements of the array." << std::endl;
    for (auto &row : sales)
    {
        for (auto &column : row)
        {
            column = 0;
            std::cout << column << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
