#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    const size_t arraySize = 4;

    std::array<int, arraySize> a = {10, 20, 30, 40};

    int total = 0;

    for (size_t i = 0; i < a.size(); ++i)
    {
        total += a[i];
    }

    std::cout << "Total of array elements : "
              << total
              << std::endl;

    return 0;
}
