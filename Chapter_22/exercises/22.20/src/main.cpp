#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

const int SIZE1 = 80;
const int SIZE2 = 26;

int main(int argc, char const *argv[])
{
    char text[3][SIZE1];
    char *searchPtr;
    int characters[SIZE2] = {0};

    std::cout << "Enter three lines of text:\n";

    for (int i = 0; i <= 2; ++i)
        std::cin.getline(&text[i][0], SIZE1);

    for (int i = 0; i <= 2; ++i)
        for (int j = 0; text[i][j] != '\0'; ++j)
        {
            char c = static_cast<char>(tolower(text[i][j]));
            text[i][j] = c;
        }

    for (int i = 0; i < SIZE2; ++i)
    {
        for (int j = 0; j <= 2; ++j)
        {
            searchPtr = &text[j][0];

            while (searchPtr = strchr(searchPtr, 'a' + i))
            {
                ++characters[i];
                ++searchPtr;
            }
        }
    }

    std::cout << "\nThe total number of occurrences of each character:\n";

    for (int i = 0; i < SIZE2; ++i)
        std::cout << std::setw(3) << static_cast<char>('a' + i) << " : "
                  << std::setw(3) << characters[i] << '\n';

    return 0;
}
