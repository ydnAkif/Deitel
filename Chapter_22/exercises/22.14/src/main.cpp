#include <iostream>
#include <cctype>

const int SIZE = 100;

int main(int argc, char const *argv[])
{
    char s[SIZE];
    int i;

    std::cout << "Enter a line of text:\n";
    std::cin.getline(s, SIZE);

    std::cout << "\nThe line in uppercase is:\n";

    for ( i = 0; s[i] !='\0'; ++i)
        std::cout << static_cast<char>(toupper(s[i]));

    std::cout << "\n\nThe line in lowercase is:\n";

    for ( i = 0; s[i] !='\0'; ++i)
        std::cout << static_cast<char>(tolower(s[i]));

    std::cout << std::endl;

    return 0;
}


