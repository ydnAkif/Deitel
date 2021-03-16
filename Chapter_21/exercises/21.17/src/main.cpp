#include <iostream>
#include <string>

int vowelCounter(std::string, char);
void convertToLower(std::string::iterator, std::string::iterator);
void printVowels(int, char);

int main(int argc, char const *argv[])
{
    std::string s;

    std::cout << "Enter a string: ";
    std::cin >> s;

    int vowelA = vowelCounter(s, 'a');
    int vowelE = vowelCounter(s, 'e');
    int vowelI = vowelCounter(s, 'i');
    int vowelO = vowelCounter(s, 'o');
    int vowelU = vowelCounter(s, 'u');

    int totalVowels = vowelA + vowelE + vowelI + vowelO + vowelU;

    std::cout << "In "
              << "\"" << s << "\""
              << " there are " << totalVowels << " vowels.\n\n";

    printVowels(vowelA, 'A');
    printVowels(vowelE, 'E');
    printVowels(vowelI, 'I');
    printVowels(vowelO, 'O');
    printVowels(vowelU, 'U');

    return 0;
}

int vowelCounter(std::string s, char vowel)
{
    int vowelCounter = 0;

    std::string::iterator ib = s.begin();
    convertToLower(ib, s.end());
    int i = 0;

    while (ib != s.end())
    {
        if (s[i] == vowel)
            ++vowelCounter;

        ++ib;
        ++i;
    }

    return vowelCounter;
}

void convertToLower(std::string::iterator i, std::string::iterator e)
{
    while (i != e)
    {
        *i = tolower(*i);
        ++i;
    }
}

void printVowels(int vowelNumber, char vowel)
{
    std::cout << "Number of '" << vowel << "' vowel";
    if (vowelNumber > 1)
        std::cout << "s are ";
    else
        std::cout << " is ";
    std::cout << vowelNumber << '\n';
}