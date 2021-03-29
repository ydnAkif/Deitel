#include <iostream>
#include <cstring>

const int SIZE1 = 80;
const int SIZE2 = 15;

int main(int argc, char const *argv[])
{
    char text[SIZE1];
    char search[SIZE2];
    char *searchPtr;

    std::cout << "Enter a line of text:\n";
    std::cin.getline(text, SIZE1);

    std::cout << "\nEnter a search string: ";
    std::cin >> search;

    searchPtr = strstr(text, search);

    if (searchPtr)
    {
        std::cout << "\nThe remainder of the line beginning with\n"
                  << "the first occurrence of \"" << search << "\":\n"
                  << searchPtr << '\n';

        searchPtr = strstr(searchPtr + 1, search);
        if (searchPtr)
            std::cout << "\nThe remainder of the line beginning with\n"
                      << "the second occurrence of \"" << search << "\":\n"
                      << searchPtr << '\n';
        else
            std::cout << "\nThe search string appeared only once.\n";
    }
    else
        std::cout << '\"' << search << "\" not found.\n";

    return 0;
}
