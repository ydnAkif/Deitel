#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;
    std::array<int, SIZE> a = {2, 2, 4, 4, 4, 6, 6, 6, 6, 8};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Array a contains:\n";
    std::copy(a.cbegin(), a.cend(), output);

    auto lower = std::lower_bound(a.cbegin(), a.cend(), 6);
    std::cout << "\n\nLower bound of 6 is element "
              << (lower - a.cbegin()) << " of array a";
    auto upper = std::upper_bound(a.cbegin(), a.cend(), 6);
    std::cout << "\nUpper bound of 6 is element "
              << (upper - a.cbegin()) << " of array a";

    auto eq = std::equal_range(a.cbegin(), a.cend(), 6);
    std::cout << "\nUsing equal_range:\n   Lower bound of 6 is element "
              << (eq.first - a.cbegin()) << " of array a";
    std::cout << "\n   Upper bound of 6 is element "
              << (eq.second - a.cbegin()) << " of array a";
    std::cout << "\n\nUse lower_bound to locate the first point\n"
              << "at which 5 can be inserted in order";

    lower = std::lower_bound(a.cbegin(), a.cend(), 5);
    std::cout << "\n   Lower bound of 5 is element "
              << (lower - a.cbegin()) << " of array a";
    std::cout << "\n\nUse upper_bound to locate the last point\n"
              << "at which 7 can be inserted in order";

    upper = std::upper_bound(a.cbegin(), a.cend(), 7);
    std::cout << "\n   Upper bound of 7 is element "
              << (upper - a.cbegin()) << " of array a";
    std::cout << "\n\nUse equal_range to localate the first and\n"
              << "last point at which 5 can be inserted in order";
    eq = std::equal_range(a.cbegin(), a.cend(), 5);
    std::cout << "\n   Lower bound of 5 is element "
              << (eq.first - a.cbegin()) << " of array a";
    std::cout << "\n   Upper bound of 5 is element "
              << (eq.second - a.cbegin()) << " of array a";
    std::cout << std::endl;

    return 0;
}
