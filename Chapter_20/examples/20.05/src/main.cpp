// 20.05 SelectionSort.cpp
// Sorting an array into ascending order with selection sort

#include <array>
#include <iomanip>
#include <iostream>

template <typename T, size_t size>
void selectionSort(std::array<T, size> &items)
{
    for (size_t i = 0; i < items.size() - 1; ++i)
    {
        size_t indexOfSmallest = i;

        for (size_t index = i + 1; index < items.size(); ++index)
            if (items[index] < items[indexOfSmallest])
                indexOfSmallest = index;

        T hold = items[i];
        items[i] = items[indexOfSmallest];
        items[indexOfSmallest] = hold;
    }
}

int main(int argc, char const *argv[])
{
    const size_t arraySize = 10;
    std::array<int, arraySize> data = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};

    std::cout << "Unsorted array:\n";

    for (size_t i = 0; i < arraySize; ++i)
    {
        std::cout << std::setw(4) << data[i];
    }

    selectionSort(data);

    std::cout << "\nSorted array:\n";

    for (size_t i = 0; i < arraySize; ++i)
    {
        std::cout << std::setw(4) << data[i];
    }

    std::cout << std::endl;

    return 0;
}
