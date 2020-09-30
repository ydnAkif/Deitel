#include <iostream>
#include <array>

const size_t SIZE = 15;
const size_t rows = 3;
const size_t columns = 5;
int main()
{
    std::array<std::array<int, columns>, rows> sales;

    std::cout << "A program to label the elements of the array." << std::endl;
    for (size_t row = 0; row < sales.size(); ++row)
    {
        for (size_t column = 0; column < sales[row].size(); ++column)
            sales[row][column] = 0;
    }

    for (size_t i = 0; i < sales.size(); ++i)
    {
        for (size_t j = 0; j < sales[i].size(); ++j)
        {
            std::cout << sales[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
