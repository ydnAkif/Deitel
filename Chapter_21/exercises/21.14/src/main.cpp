#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void convertToLower(std::string::iterator, std::string::iterator);

int main(int argc, char const *argv[])
{
    std::string s;
    std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string::iterator is;
    std::string::iterator is2;
    std::string::iterator is3;

    srand(time(0));
    std::cout << "Enter a string: "; // max 26 character
    std::getline(std::cin, s, '\n');
    std::cout << "Original string:      " << s;

    is = s.begin();

    convertToLower(is, s.end());

    std::string s2(s);

    is3 = s2.begin();

    do
    {
        is2 = is3;
        if (*is == ' ')
        {
            ++is;
            continue;
        }

        int x = rand() % alpha.length();
        char c = alpha.at(x);
        alpha.erase(x, 1);

        while (is2 != s2.end())
        {
            if (*is2 == *is)
                *is2 = c;
            ++is2;
        }
        ++is3;
        ++is++;

    } while (is != s.end());

    is3 = s2.begin();
    convertToLower(is3, s2.end());

    std::cout << "\nCryptogram of string: " << s2 << std::endl;

    return 0;
}

void convertToLower(std::string::iterator i, std::string::iterator e)
{
    while (i != e)
    {
        *i = tolower(*i);
        ++i;
    }
}