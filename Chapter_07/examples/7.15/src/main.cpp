#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
    const size_t arrayList = 7;
    std::array<std::string, arrayList> colors = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

    std::cout << "Unsorted array:\n";
    for (std::string color : colors)
        std::cout << color << " ";

    std::sort(colors.begin(), colors.end());
    std::cout << "\nSorted array:\n";
    for (std::string item : colors)
        std::cout << item << " ";

    bool found = std::binary_search(colors.begin(), colors.end(), "indigo");
    std::cout << "\n\n\"indigo\" " << (found ? "was" : "was not") << " found in clors" << std::endl;

    found = std::binary_search(colors.begin(), colors.end(), "cyan");
    std::cout << "\"cyan\" " << (found ? "was" : "was not") << " found in clors" << std::endl;

    return 0;
}
