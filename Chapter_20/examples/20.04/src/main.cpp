// 20.04 InsertionSort.cpp
// Sorting an array into ascending order with insertion sort
#include <array>
#include <iomanip>
#include <iostream>

template <typename T, size_t size>
void insertionSort(std::array<T, size> &items)
{
    for (size_t next = 1; next < items.size(); ++next)
    {
        T insert = items[next];
        size_t moveIndex = next;

        while ((moveIndex > 0) && (items[moveIndex - 1] > insert))
        {
            items[moveIndex] = items[moveIndex - 1];
            --moveIndex;
        }

        items[moveIndex] = insert;
    }
}

int main(int argc, char const *argv[])
{
    const size_t arraySize = 10;

    std::array<int, arraySize> data = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};

    std::cout << "Unsorted array:\n";

    for (size_t i = 0; i < arraySize; ++i)
        std::cout << std::setw(4) << data[i];

    insertionSort(data);

    std::cout << "\nSorted array:\n";

    for (size_t i = 0; i < arraySize; ++i)
        std::cout << std::setw(4) << data[i];

    std::cout << std::endl;
    return 0;
}
