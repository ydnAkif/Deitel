#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

int sumSquares(int, int);

template <typename T>
class SumSquaresClass
{
    public:
        T operator()(const T & total, const T &value)
        {
            return total + value * value;
        }
};

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;
    std::array<int, SIZE> integers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "Array integers contains:\n";
    std::copy(integers.cbegin(), integers.cend(), output);

    int result = std::accumulate(integers.cbegin(), integers.cend(), 0, sumSquares);

    std::cout << "\n\nSum of squares of elements in integers using "
              << "binary\nfunction sumSquares:" << result;

    result = std::accumulate(integers.cbegin(), integers.cend(), 0, SumSquaresClass<int>());
    std::cout << "\n\nSum of squares elements in integers using "
              << "binary\nfunction object of type "
              << "SumSquaresClass<int>: " << result << std::endl;

    return 0;
}

int sumSquares(int total, int value)
{
    return (total + (value * value));
}