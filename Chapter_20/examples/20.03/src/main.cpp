#include <iostream>
#include <algorithm>
#include <array>
#include <ctime>
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
int binarySearch(const std::array<T, size> &items, const T &key)
{
    int low = 0;
    int high = items.size() - 1;
    int middle = (low + high + 1) / 2;
    int location = -1;

    do
    {
        displayElements(items, low, high);

        for (int i = 0; i < middle; ++i)
            std::cout << "   ";
        std::cout << " * " << std::endl;

        if (key == items[middle])
        {
            location = middle;
        }
        else if (key < items[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }

        middle = (low + high + 1) / 2;

    } while ((low <= high) && (location == -1));

    return location;
}

int main(int argc, char const *argv[])
{
    std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomInt(10, 99);

    const size_t arraySize = 15;
    std::array<int, arraySize> arrayToSearch;

    for (int &item : arrayToSearch)
    {
        item = randomInt(engine);
    }

    std::sort(arrayToSearch.begin(), arrayToSearch.end());

    displayElements(arrayToSearch, 0, arrayToSearch.size() - 1);

    std::cout << "\nPlease enter an integer value (-1 to quit): ";
    int searchKey;
    std::cin >> searchKey;
    std::cout << std::endl;

    while (searchKey != -1)
    {
        int position = binarySearch(arrayToSearch, searchKey);

        if (position == -1)
        {
            std::cout << "The integer " << searchKey << " was not found.\n";
        }
        else
        {
            std::cout << "The integer " << searchKey << " was found in position " << position << ".\n";
        }

        std::cout << "\n\nPlease enter an integer value(-1 to quit): ";
        std::cin >> searchKey;
        std::cout << std::endl;
    }

    return 0;
}
