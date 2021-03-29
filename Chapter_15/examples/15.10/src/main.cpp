#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T> &integers2);

int main(int argc, char const *argv[])
{
    const size_t SIZE = 6;

    int values[SIZE] = {1, 2, 3, 4, 5, 6};

    std::vector<int> integers;

    std::cout << "The initial size of integers is: " << integers.size()
              << "\nThe initial capacity of integers is: " << integers.capacity();

    integers.push_back(2);
    integers.push_back(3);
    integers.push_back(4);

    std::cout << "\nThe size of integers is: " << integers.size()
              << "\nThe capacity of integers is: " << integers.capacity();
    std::cout << "\n\nOutput built-in array using pointer notation: ";

    for (const int *ptr = std::begin(values); ptr != std::end(values); ++ptr)
        std::cout << *ptr << ' ';

    std::cout << "\nOutput vector using iterator notation: ";
    printVector(integers);
    std::cout << "\nReversed contents of vector integers: ";

    for (auto reserveIterator = integers.crbegin(); reserveIterator != integers.crend(); ++reserveIterator)
        std::cout << *reserveIterator << ' ';

    std::cout << std::endl;

    return 0;
}

template <typename T>
void printVector(const std::vector<T> &integers2)
{
    for (auto consIterator = integers2.cbegin(); consIterator != integers2.cend(); ++consIterator)
        std::cout << *consIterator << ' ';
}