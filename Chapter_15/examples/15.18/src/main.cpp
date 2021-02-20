#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    std::map<int, double, std::less<int>> pairs;

    pairs.insert(std::make_pair(15, 2.7));
    pairs.insert(std::make_pair(30, 111.11));
    pairs.insert(std::make_pair(5, 1010.1));
    pairs.insert(std::make_pair(10, 22.22));
    pairs.insert(std::make_pair(25, 33.333));
    pairs.insert(std::make_pair(5, 77.54));
    pairs.insert(std::make_pair(20, 9.345));
    pairs.insert(std::make_pair(15, 99.3));

    std::cout << "pairs contains:" << std::endl
              << "Key"
              << "\tValue" << std::endl;

    for (auto mapItem : pairs)
        std::cout << mapItem.first << "\t" << mapItem.second << std::endl;

    pairs[25] = 9999.99;
    pairs[40] = 8765.43;

    std::cout << std::endl
              << "After subscript operations, pair contains:" << std::endl
              << "Key"
              << "\tValue" << std::endl;

    for (auto mapItem : pairs)
        std::cout << mapItem.first << "\t" << mapItem.second << std::endl;

    std::cout << std::endl;

    return 0;
}
