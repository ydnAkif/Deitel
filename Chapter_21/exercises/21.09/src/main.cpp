#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string s[5];

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Enter a word: ";
        std::cin >> s[i];
    }

    for (int j = 0; j < 5; ++j)
    {
        if ((s[j].rfind("ay") == s[j].length() - 2) || (s[j]).rfind("r") == s[j].length() - 1)
            std::cout << s[j] << std::endl;
    }

    return 0;
}
