#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <array>

bool palindromeTester(std::string);
void makeLower(char &);

int main(int argc, char const *argv[])
{

    std::cout << std::boolalpha << palindromeTester("Radar") << std::endl;
    std::cout << std::boolalpha << palindromeTester("Was it a cat I saw?") << std::endl;
    std::cout << std::boolalpha << palindromeTester("(!!able was I ,ere; i:) saw elba.") << std::endl;

    return 0;
}

bool palindromeTester(std::string str)
{
    std::string stripped;
    std::copy_if(str.begin(), str.end(), std::back_inserter(stripped), ::isalpha);
    std::for_each(stripped.begin(), stripped.end(), makeLower);
    std::string temp = stripped;
    std::reverse(temp.begin(), temp.end());

    if (temp == stripped)
    {
        return true;
    }

    return false;
}

void makeLower(char &c)
{
    c = ::tolower(c);
}
