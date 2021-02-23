#include <iostream>
#include <iterator>
#include <array>
#include <algorithm>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 5;
    std::array<int, SIZE> a1 = {1, 3, 5, 7, 9};
    std::array<int, SIZE> a2 = {2, 4, 5, 7, 9};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Array a1 contains: ";
    std::copy(a1.cbegin(), a1.cend(), output);
    std::cout << "\nArray a2 contains: ";
    std::copy(a2.cbegin(), a2.cend(), output);

    std::array<int, SIZE> results;

    std::copy_backward(a1.cbegin(), a1.cend(), results.end());
    std::cout << "\n\nAfter copy_backward, results contains: ";
    std::copy(results.cbegin(), results.cend(), output);

    std::array<int, SIZE + SIZE> results2;

    std::merge(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), results2.begin());
    std::cout << "\n\nAfter merge of a1 and a2 results2 contains: ";
    std::copy(results2.cbegin(), results2.cend(), output);

    auto endLocation = std::unique(results2.begin(), results2.end());
    std::cout << "\n\nAfter unique results2 contains: ";
    std::copy(results2.begin(), endLocation, output);

    std::cout << "\n\nArray a1 after reverse: ";
    std::reverse(a1.begin(), a1.end());
    std::copy(a1.cbegin(), a1.cend(), output);
    std::cout << std::endl;

    return 0;
}
