#include <iostream>
#include <array>

template <typename T, size_t size>
int linearSearch(const std::array<T, size> &items, const T &key)
{
    for (size_t i = 0; i < items.size(); ++i)
        if (key == items[i])
            return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    const size_t arraySize = 100;
    std::array<int, arraySize> arrayToSearch;

    for (size_t i = 0; i < arrayToSearch.size(); ++i)
        arrayToSearch[i] = 2 * i;

    std::cout << "Enter integer to search key: ";
    int searchKey;
    std::cin >> searchKey;

    int element = linearSearch(arrayToSearch, searchKey);

    if (element != -1)
        std::cout << "Found value in element " << element << std::endl;
    else
        std::cout << "Value not found" << std::endl;

    return 0;
}
