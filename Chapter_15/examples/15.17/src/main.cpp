#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    std::multimap<int, double, std::less<int>> pairs;

    std::cout << "There are currently " << pairs.count(15)
              << " pairs with key 15 in the multimap" << std::endl;

    pairs.insert(std::make_pair(15, 2.7));
    pairs.insert(std::make_pair(15, 99.3));

    std::cout << "After insert, there are " << pairs.count(15)
              << " pairs with key 15" << std::endl
              << std::endl;
    pairs.insert(std::make_pair(30, 111.11));
    pairs.insert(std::make_pair(10, 22.22));
    pairs.insert(std::make_pair(25, 33.33));
    pairs.insert(std::make_pair(20, 9.345));
    pairs.insert(std::make_pair(5, 77.54));

    std::cout << "Multimap pairs contains:" << std::endl
              << "Key"
              << "\tValue" << std::endl;

    for (auto mapItem : pairs)
        std::cout << mapItem.first << "\t" << mapItem.second << std::endl;

    std::cout << std::endl;

    return 0;
}
