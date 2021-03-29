#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    std::array<int, 5> items = {1, 2, 3, 4, 5};

    std::cout << "items before modification: ";
    for (int item : items)
        std::cout << item << " ";

    for (int &itemRef : items)
        itemRef *= 2;
    std::cout << "\nitems after modification: ";

    for (int item: items)
        std::cout << item << " ";

    std::cout << std::endl;
}
