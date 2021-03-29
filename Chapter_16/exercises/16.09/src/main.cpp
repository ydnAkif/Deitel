#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 20;
    std::array<int, SIZE> integers;
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Input 20 integers that there're duplicate ones in them:\n";

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cin >> integers[i];
    }

    std::vector<int> uniqueInts;

    std::unique_copy(integers.begin(), integers.end(), std::back_inserter(uniqueInts));

    std::cout << "Array integers contains:\n";
    std::copy(integers.cbegin(), integers.cend(), output);
    std::cout << "\nIntegers after unique_copy:\n";
    std::copy(uniqueInts.cbegin(), uniqueInts.cend(), output);
    std::cout << std::endl;

    return 0;
}
