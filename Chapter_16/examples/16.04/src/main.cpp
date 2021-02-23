#include <iostream>
#include <iterator>
#include <algorithm>
#include <array>

bool greater9(int);

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;

    std::array<int, SIZE> init = {10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
    std::ostream_iterator<int> output(std::cout, " ");

    std::array<int, SIZE> a1(init);
    std::cout << "a1 before replacing all 10s:\n";
    std::copy(a1.cbegin(), a1.cend(), output);

    std::replace(a1.begin(), a1.end(), 10, 100);
    std::cout << "\na1 after replacing 10s with 100s:\n";
    std::copy(a1.cbegin(), a1.cend(), output);

    std::array<int, SIZE> a2(init);
    std::array<int, SIZE> c1;
    std::cout << "\n\na2 before replacing all 10s and copying:\n";
    std::copy(a2.cbegin(), a2.cend(), output);

    std::replace_copy(a2.cbegin(), a2.cend(), c1.begin(), 10, 100);
    std::cout << "\nc1 after replacing all 10s in a2:\n";
    std::copy(c1.cbegin(), c1.cend(), output);

    std::array<int, SIZE> a3(init);
    std::cout << "\n\na3 before replacing values greater than 9:\n";
    std::copy(a3.cbegin(), a3.cend(), output);

    std::replace_if(a3.begin(), a3.end(), greater9, 100);
    std::cout << "\na3 after replacing all values greater"
              << "\nthan 9 with 100s:\n";
    std::copy(a3.cbegin(), a3.cend(), output);

    std::array<int, SIZE> a4(init);
    std::array<int, SIZE> c2;
    std::cout << "\n\na4 before replacing values greater "
              << " than 9 and copying:\n";
    std::copy(a4.cbegin(), a4.cend(), output);

    std::replace_copy_if(a4.cbegin(), a4.cend(), c2.begin(), greater9, 100);
    std::cout << "\nc2 after replacing all values greater than 9 in a4:\n";
    std::copy(c2.begin(), c2.end(), output);
    std::cout << std::endl;

    return 0;
}

bool greater9(int x)
{
    return x > 9;
}