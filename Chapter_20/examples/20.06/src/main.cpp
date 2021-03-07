// 20.06 MergeSort.cpp
// Sorting an array into ascending order with sort merge
#include <array>
#include <ctime>
#include <iostream>
#include <random>

template <typename T, size_t size>
void displayElements(const std::array<T, size> &items, size_t low, size_t high)
{
    for (size_t i = 0; i < items.size() && i < low; ++i)
        std::cout << "   ";
    for (size_t i = low; i < items.size() && i <= high; ++i)
        std::cout << items[i] << " ";
    std::cout << std::endl;
}

template <typename T, size_t size>
void merge(std::array<T, size> &items, size_t left, size_t middle1, size_t middle2, size_t right)
{
    size_t leftIndex = left;
    size_t rightIndex = middle2;
    size_t combinedIndex = left;
    std::array<T, size> combined;

    std::cout << "merge:   ";
    displayElements(items, left, middle1);
    std::cout << "         ";
    displayElements(items, middle2, right);
    std::cout << std::endl;

    while (leftIndex <= middle1 && rightIndex <= right)
    {
        if (items[leftIndex] <= items[rightIndex])
            combined[combinedIndex++] = items[leftIndex++];
        else
            combined[combinedIndex++] = items[rightIndex++];
    }

    if (leftIndex == middle2)
    {
        while (rightIndex <= right)
            combined[combinedIndex++] = items[rightIndex++];
    }
    else
    {
        while (leftIndex <= middle1)
            combined[combinedIndex++] = items[leftIndex++];
    }

    for (size_t i = left; i <= right; ++i)
        items[i] = combined[i];
    std::cout << "          ";
    displayElements(items, left, right);
    std::cout << std::endl;
}

template <typename T, size_t size>
void mergeSort(std::array<T, size> &items, size_t low, size_t high)
{
    if ((high - low) >= 1)
    {
        int middle1 = (low + high) / 2;
        int middle2 = middle1 + 1;

        std::cout << "split:   ";
        displayElements(items, low, high);
        std::cout << "         ";
        displayElements(items, low, middle1);
        std::cout << "         ";
        displayElements(items, middle2, high);
        std::cout << std::endl;

        mergeSort(items, low, middle1);
        mergeSort(items, middle2, high);

        merge(items, low, middle1, middle2, high);
    }
}

int main(int argc, char const *argv[])
{
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomInt(10, 99);

    const size_t arraySize = 10;
    std::array<int, arraySize> data;

    for (int &item : data)
        item = randomInt(engine);

    std::cout << "Unsorted array:" << std::endl;
    displayElements(data, 0, data.size() - 1);
    std::cout << std::endl;

    mergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:" << std::endl;
    displayElements(data, 0, data.size() - 1);

    return 0;
}
