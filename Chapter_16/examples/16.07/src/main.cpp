#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;
    std::array<int, SIZE> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Array a contains:\n    ";
    std::copy(a.cbegin(), a.cend(), output);

    std::swap(a[0], a[1]);

    std::cout << "\nArray a after swapping a[0] and a[1] using swap:\n    ";
    std::copy(a.cbegin(), a.cend(), output);

    std::iter_swap(a.begin(), a.begin() + 1);
    std::cout << "\nArray a after swapping a[0] and a[1] using iter_swap:\n    ";
    std::copy(a.cbegin(), a.cend(), output);

    std::swap_ranges(a.begin(), a.begin() + 5, a.begin() + 5);
    std::cout << "\nArray a after swapping the first five elements\n"
              << "with the last five elements:\n    ";
    std::copy(a.cbegin(), a.cend(), output);
    std::cout << std::endl;

    return 0;
}
