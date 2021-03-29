#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string string1("The airplane landed on time.");

    std::cout << string1.substr(7, 5) << std::endl;

    return 0;
}
