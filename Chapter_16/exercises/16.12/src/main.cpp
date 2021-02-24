#include <iostream>
#include <algorithm>
#include <string>

bool palindromeTester(std::string);

int main(int argc, char const *argv[])
{

    std::cout << std::boolalpha << palindromeTester("radar") << std::endl;
    std::cout << std::boolalpha << palindromeTester("hello world") << std::endl;
    std::cout << std::boolalpha << palindromeTester(".able was i ere i saw elba.") << std::endl;

    return 0;
}

bool palindromeTester(std::string str)
{
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());

    if (temp == str)
    {
        return true;
    }
    return false;
}
