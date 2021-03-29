#include <iostream>
#include <iterator>
#include <algorithm>
#include <array>
#include <vector>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;
    std::array<int, SIZE> a1 = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Array a1 contains: ";
    std::copy(a1.cbegin(), a1.cend(), output);

    std::inplace_merge(a1.begin(), a1.begin() + 5, a1.end());
    std::cout << "\nAfter inplace_merge, a1 contains: ";
    std::copy(a1.cbegin(), a1.cend(), output);

    std::vector<int> results1;
    std::unique_copy(a1.cbegin(), a1.cend(), std::back_inserter(results1));
    std::cout << "\nAfter unique_copy, results1 contains: ";
    std::copy(results1.cbegin(), results1.cend(), output);

    std::vector<int> results2;
    std::reverse_copy(a1.cbegin(), a1.cend(), std::back_inserter(results2));
    std::cout << "\nAfter reverse_copy, results2 contains: ";
    std::copy(results2.cbegin(), results2.cend(), output);
    std::cout << std::endl;

    return 0;
}
