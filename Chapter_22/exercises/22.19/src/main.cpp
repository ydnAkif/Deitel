#include <iostream>
#include <cstring>
#include <cctype>

const int SIZE = 80;

int main(int argc, char const *argv[])
{
    char text[3][SIZE];
    char search;
    char *searchPtr;
    int count = 0;
    int i;

    std::cout << "Enter three lines of text:\n";

    for (i = 0; i <= 2; ++i)
        std::cin.getline(&text[i][0], SIZE);

    for (i = 0; i <= 2; ++i)
        for (int j = 0; text[i][j] != '\0'; ++j)
        {
            char c = static_cast<char>(tolower(text[i][j]));
            text[i][j] = c;
        }

    std::cout << "\nEnter a search character: ";
    std::cin >> search;

    for (i = 0; i <= 2; ++i)
    {
        searchPtr = &text[i][0];

        while (searchPtr = strchr(searchPtr, search))
        {
            ++count;
            ++searchPtr;
        }
    }

    std::cout << "\nThe total number of occurrences of \'" << search
              << "\' in the text is: " << count << std::endl;

    return 0;
}
