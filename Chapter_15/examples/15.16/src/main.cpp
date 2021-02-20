#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include <set>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 5;

    std::array<double, SIZE> a = {2.1, 4.2, 9.5, 2.1, 3.7};
    std::set<double, std::less<double>> doubleSet(a.begin(), a.end());
    std::ostream_iterator<double> output(std::cout, " ");

    std::cout << "doubleSet contains: ";
    std::copy(doubleSet.begin(), doubleSet.end(), output);

    auto p = doubleSet.insert(13.8);

    std::cout << std::endl
              << std::endl
              << *(p.first) << (p.second ? " was" : " was not") << " inserted";
    std::cout << std::endl
              << "doubleSet contains: ";
    std::copy(doubleSet.begin(), doubleSet.end(), output);

    p = doubleSet.insert(9.5);

    std::cout << std::endl
              << std::endl
              << *(p.first) << (p.second ? " was" : " was not") << " inserted";
    std::cout << std::endl
              << "doubleSet contains: ";
    std::copy(doubleSet.begin(), doubleSet.end(), output);
    std::cout << std::endl;

    return 0;
}
