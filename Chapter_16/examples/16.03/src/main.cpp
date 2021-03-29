#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>

bool greater9(int);

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;

    std::array<int, SIZE> init = {10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::array<int, SIZE> a1(init);
    std::cout << "a1 before removing all 10s:\n";
    std::copy(a1.cbegin(), a1.cend(), output);

    auto newLastElement = std::remove(a1.begin(), a1.end(), 10);
    std::cout << "\na1 after removing all 10s:\n";
    std::copy(a1.begin(), newLastElement, output);

    std::array<int, SIZE> a2(init);
    std::array<int, SIZE> c = {0};

    std::cout << "\n\na2 before removing all 10s and copying:\n";
    std::copy(a2.cbegin(), a2.cend(), output);

    std::remove_copy(a2.cbegin(), a2.cend(), c.begin(), 10);
    std::cout << "\nc after removing all 10s from a2:\n";
    std::copy(c.cbegin(), c.cend(), output);

    std::array<int, SIZE> a3(init);
    std::cout << "\n\na3 before removing all elements greater than 9:\n";
    std::copy(a3.cbegin(), a3.cend(), output);

    newLastElement = std::remove_if(a3.begin(), a3.end(), greater9);
    std::cout << "\na3 after removing all elements greater than 9:\n";
    std::copy(a3.begin(), newLastElement, output);

    std::array<int, SIZE> a4(init);
    std::array<int, SIZE> c2 = {0};

    std::cout << "\n\na4 before removing all elements"
              << "\ngreater than 9 and copying:\n";
    std::copy(a4.cbegin(), a4.cend(), output);

    std::remove_copy_if(a4.cbegin(), a4.cend(), c2.begin(), greater9);

    std::cout << "\nc2 after removing all elements"
              << "\ngreater than 9 from a4:\n";
    std::copy(c2.cbegin(), c2.cend(), output);
    std::cout << std::endl;

    return 0;
}

bool greater9(int x)
{
    return x > 9;
}