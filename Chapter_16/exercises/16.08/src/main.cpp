#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 20;
    std::array<int, SIZE> integers;
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Input 20 integers that they are duplicate ones in them:\n";

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cin >> integers[i];
    }

    auto result = std::unique(integers.begin(), integers.end());

    std::cout << "You entered:\n";
    std::copy(integers.begin(), result, output);

    return 0;
}
