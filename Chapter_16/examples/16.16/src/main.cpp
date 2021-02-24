#include <array>
#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 4;
    std::array<int, SIZE> values = {1, 2, 3, 4};

    std::for_each(values.cbegin(), values.cend(),
                  [](int i) { std::cout << i * 2 << std::endl; });

    int sum = 0;

    std::for_each(values.cbegin(), values.cend(),
                  [&sum](int i) { sum += i; });

    std::cout << "sum is " << sum << std::endl;

    return 0;
}
