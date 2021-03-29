#include <array>
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
    const size_t SIZE = 10;

    std::array<int, SIZE> a = {7, 22, 9, 1, 18, 30, 100, 22, 85, 13};

    std::multiset<int, std::less<int>> intMultiset;

    std::ostream_iterator<int> output(std::cout, " ");

    std::cout << "There are currently " << intMultiset.count(15)
              << " values of 15 in the multiset" << std::endl;

    intMultiset.insert(15);
    intMultiset.insert(15);

    std::cout << "After inserts, there are " << intMultiset.count(15)
              << " values of 15 in the multiset" << std::endl
              << std::endl;

    auto result = intMultiset.find(15);

    if (result != intMultiset.end())
        std::cout << "Found value 15" << std::endl;

    result = intMultiset.find(20);

    if (result == intMultiset.end())
        std::cout << "Did not find value 20" << std::endl;

    intMultiset.insert(a.cbegin(), a.cend());

    std::cout << std::endl
              << "After insert, intMultiset contains:" << std::endl;
    std::copy(intMultiset.begin(), intMultiset.end(), output);

    std::cout << std::endl
              << std::endl
              << "Lower bound of 22: "
              << *(intMultiset.lower_bound(22));
    std::cout << std::endl
              << "Upper bound of 22: " << *(intMultiset.upper_bound(22));

    auto p = intMultiset.equal_range(22);

    std::cout << std::endl
              << std::endl
              << "equal_range of 22:"
              << std::endl
              << "    Lower bond: " << *(p.first) << std::endl
              << "    Upper bond: " << *(p.second);
    std::cout << std::endl;

    return 0;
}
