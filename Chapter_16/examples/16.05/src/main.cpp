#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <array>

bool greater9(int);

void outputSquare(int);

int calculateCube(int);

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;

    std::array<int, SIZE> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "a1 before random_shuffle: ";
    std::copy(a1.cbegin(), a1.cend(), output);

    std::random_shuffle(a1.begin(), a1.end());
    std::cout << "\na1 after random_shuffle: ";
    std::copy(a1.cbegin(), a1.cend(), output);

    std::array<int, SIZE> a2 = {100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
    std::cout << "\n\na2 contains: ";
    std::copy(a2.cbegin(), a2.cend(), output);

    int result = std::count(a2.cbegin(), a2.cend(), 8);
    std::cout << "\nNumber of elements matching 8: " << result;

    result = std::count_if(a2.cbegin(), a2.cend(), greater9);
    std::cout << "\nNumber of elements greater than 9: " << result;

    std::cout << "\n\nMinimum element in a2 is: "
              << *(std::min_element(a2.cbegin(), a2.cend()));

    std::cout << "\nMaximum element in a2 is: "
              << *(std::max_element(a2.cbegin(), a2.cend()));

    auto minAndMax = std::minmax_element(a2.cbegin(), a2.cend());
    std::cout << "\nThe minimum and maximum elements in a2 are "
              << *(minAndMax.first) << " and " << *(minAndMax.second)
              << ", respectively";

    std::cout << "\n\nThe total of the elements in a1 is: "
              << std::accumulate(a1.cbegin(), a1.cend(), 0);
    std::cout << "\n\nThe square of every integer in a1 is:\n";
    std::for_each(a1.cbegin(), a1.cend(), outputSquare);

    std::array<int, SIZE> cubes;
    std::transform(a1.cbegin(), a1.cend(), cubes.begin(), calculateCube);
    std::cout << "\n\nThe cube of every integer in a1 is:\n";
    std::copy(cubes.cbegin(), cubes.cend(), output);

    std::cout << std::endl;

    return 0;
}

bool greater9(int x)
{
    return x > 9;
}

void outputSquare(int value)
{
    std::cout << value * value << ' ';
}

int calculateCube(int value)
{
    return value * value * value;
}