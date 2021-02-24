#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::cout << "The minumum of 12 and 7 is: " << std::min(12, 7);
    std::cout << "\nThe maximum of 12 and 7 is: " << std::max(12, 7);
    std::cout << "\nThe minumum of 'G' and 'Z' is: " << std::min('G', 'Z');
    std::cout << "\nThe maximum of 'G' and 'Z' is: " << std::max('G', 'Z');

    auto result1 = std::minmax(12, 7);
    std::cout << "\n\nThe minumum of 12 and 7 is: " << result1.first
              << "\nThe maximum of 12 and 7 is " << result1.second;

    std::array<int, 10> items = {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "\n\nArray items contains: ";
    std::copy(items.cbegin(), items.cend(), output);

    auto result2 = std::minmax_element(items.cbegin(), items.cend());
    std::cout << "\nThe minumum element in items is: " << *result2.first
              << "\nThe maximum element in items is: " << *result2.second << std::endl;

    return 0;
}
