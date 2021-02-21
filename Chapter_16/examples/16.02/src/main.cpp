#include <iostream>
#include <iterator>
#include <algorithm>
#include <array>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;

    std::array<int, SIZE> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, SIZE> a2(a1);
    std::array<int, SIZE> a3 = {1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "a1 contains: ";
    std::copy(a1.cbegin(), a1.cend(), output);
    std::cout << "\na2 contains: ";
    std::copy(a2.cbegin(), a2.cend(), output);
    std::cout << "\na3 contains: ";
    std::copy(a3.cbegin(), a3.cend(), output);

    bool result = std::equal(a1.cbegin(), a1.cend(), a2.cbegin());

    std::cout << "\na1 " << (result ? "is" : "is not")
              << " equal to a2.\n";

    result = std::equal(a1.cbegin(), a1.cend(), a3.cbegin());

    std::cout << "\na1 " << (result ? "is" : "is not")
              << " equal to a3.\n";

    auto location = std::mismatch(a1.cbegin(), a1.cend(), a3.cbegin());

    std::cout << "\nThere is a mismatch between a1 and a3 at location "
              << (location.first - a1.begin()) << "\nwhere a1 contains "
              << *(location.first) << " and a3 contains " << *(location.second) << "\n\n";

    char c1[SIZE] = "HELLO";
    char c2[SIZE] = "BYE BYE";

    result = std::lexicographical_compare(std::begin(c1), std::end(c1), std::begin(c2), std::end(c2));

    std::cout << c1 << (result ? " is less than " : " is greater than or equal to ") << c2 << std::endl;

    return 0;
}
