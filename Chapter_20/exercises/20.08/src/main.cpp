#include <iostream>
#include <array>

template <typename T, size_t size>
int recursiveLinearSearch(std::array<T, size> &, T key, int, int);

int main()
{
    const size_t arraySize = 100;
    std::array<int, arraySize> data;
    int searchKey;
    int element;

    for (int loop = 0; loop < arraySize; ++loop)
        data[loop] = 2 * loop;

    std::cout << "Enter the integer search key: ";
    std::cin >> searchKey;

    element = recursiveLinearSearch(data, searchKey, 0, arraySize - 1);

    if (element != -1)
    {
        std::cout << "Found value in element " << element << std::endl;
    }
    else
    {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}
template <typename T, size_t size>
int recursiveLinearSearch(std::array<T, size> &arr, T key, int low, int high)
{
    if (arr[low] == key)
        return low;
    else if (low == high)
        return -1;
    else
        return (recursiveLinearSearch(arr, key, low + 1, high));
}
