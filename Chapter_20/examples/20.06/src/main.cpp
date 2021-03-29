// 20.06 MergeSort.cpp
// Sorting an array into ascending order with sort merge
#include <array>
#include <ctime>
#include <iostream>
#include <random>

template <typename T, size_t size>
void displayElements(const std::array<T, size> &items,
                     size_t low, size_t high)
{
    for (size_t i = 0; i < items.size() && i < low; ++i)
        std::cout << "   ";

    for (size_t i = low; i < items.size() && i <= high; ++i)
        std::cout << items[i] << " ";
    std::cout << std::endl;
}

template <typename T, size_t size>
void merge(std::array<T, size> &items,
           size_t left, size_t middleFirst,
           size_t middleSecond, size_t right)
{
    size_t leftIndex = left;
    size_t rightIndex = middleSecond;
    size_t combinedIndex = left;
    std::array<T, size> combined;

    /* std::cout << "merge:   ";
    displayElements(items, left, middleFirst);
    std::cout << "         ";
    displayElements(items, middleSecond, right);
    std::cout << std::endl; */

    while (leftIndex <= middleFirst && rightIndex <= right)
    {
        if (items[leftIndex] <= items[rightIndex])
            combined[combinedIndex++] = items[leftIndex++];
        else
            combined[combinedIndex++] = items[rightIndex++];
    }

    if (leftIndex == middleSecond)
    {
        while (rightIndex <= right)
            combined[combinedIndex++] = items[rightIndex++];
    }
    else
    {
        while (leftIndex <= middleFirst)
            combined[combinedIndex++] = items[leftIndex++];
    }

    for (size_t i = left; i <= right; ++i)
        items[i] = combined[i];

    /* std::cout << "         ";
    displayElements(items, left, right);
    std::cout << std::endl; */
}

template <typename T, size_t size>
void mergeSort(std::array<T, size> &items, size_t low, size_t high)
{
    if ((high - low) >= 1)
    {
        size_t middleFirst = (low + high) / 2;
        size_t middleSecond = middleFirst + 1;

        /* std::cout << "split:   ";
        displayElements(items, low, high);
        std::cout << "         ";
        displayElements(items, low, middleFirst);
        std::cout << "         ";
        displayElements(items, middleSecond, high);
        std::cout << std::endl;*/

        mergeSort(items, low, middleFirst);
        mergeSort(items, middleSecond, high);

        merge(items, low, middleFirst, middleSecond, high);
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
