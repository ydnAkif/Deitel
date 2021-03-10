#include <iostream>
#include <algorithm>
#include <array>
#include <ctime>
#include <random>

template <typename T, size_t size>
void displayElements(const std::array<T, size> &, size_t, size_t);

template <typename T, size_t size>
int recursiveBinarySearch(const std::array<T, size> &, const T &, size_t, size_t);

int main(int argc, char const *argv[])
{
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomInt(10, 99);
    int searchKey;
    int position;
    const size_t arraySize = 15;
    std::array<int, arraySize> data;

    for (int &item : data)
    {
        item = randomInt(engine);
    }

    std::sort(data.begin(), data.end());

    displayElements(data, 0, data.size() - 1);

    std::cout << "\nPlease enter an integer value (-1 to quit): ";

    std::cin >> searchKey;
    std::cout << std::endl;

    while (searchKey != -1)
    {
        position = recursiveBinarySearch(data, searchKey, 0, data.size() - 1);

        if (position == -1)
            std::cout << "The integer " << searchKey << " was not found.\n";
        else
            std::cout << "The integer " << searchKey << " was found in position " << position << ".\n";

        std::cout << "\n\nPlease enter an integer value(-1 to quit): ";
        std::cin >> searchKey;
        std::cout << std::endl;
    }

    return 0;
}

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
int recursiveBinarySearch(const std::array<T, size> &items, const T &key, size_t low, size_t high)
{
    if (low > high)
        return -1;

    displayElements(items, low, high);

    int middle = (low + high + 1) / 2;

    for (int i = 0; i < middle; ++i)
        std::cout << "   ";

    std::cout << " * " << std::endl;

    int location = -1;

    if (key == items[middle])
        location = middle;
    else if (key < items[middle])
        location = recursiveBinarySearch(items, key, low, middle - 1);
    else
        location = recursiveBinarySearch(items, key, middle + 1, high);

    return location;
}