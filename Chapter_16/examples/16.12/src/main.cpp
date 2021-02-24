#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;
    std::array<int, SIZE> init = {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
    std::array<int, SIZE> a(init);
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Array a before make_heap:\n";
    std::copy(a.cbegin(), a.cend(), output);

    std::make_heap(a.begin(), a.end());
    std::cout << "\nArray a after make_heap:\n";
    std::copy(a.cbegin(), a.cend(), output);

    std::sort_heap(a.begin(), a.end());
    std::cout << "\nArray a after sort_heap:\n";
    std::copy(a.cbegin(), a.cend(), output);

    std::cout << "\n\nArray init contains: ";
    std::copy(init.cbegin(), init.cend(), output);
    std::cout << std::endl;

    std::vector<int> v;

    for (size_t i = 0; i < SIZE; ++i)
    {
        v.push_back(init[i]);
        std::push_heap(v.begin(), v.end());
        std::cout << "\nv after push_heap(init[" << i << "]): ";
        std::copy(v.cbegin(), v.cend(), output);
    }
    std::cout << std::endl;

    for (size_t j = 0; j < SIZE; ++j)
    {
        std::cout << "\nv after " << v[0] << " popped from heap\n";
        std::pop_heap(v.begin(), v.end() - j);
        std::copy(v.cbegin(), v.cend(), output);
    }
    std::cout << std::endl;

    return 0;
}
