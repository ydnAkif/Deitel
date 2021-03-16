#include <iostream>
#include <string>

void deleteBy(std::string &, std::string);

int main(int argc, char const *argv[])
{
    std::string s;

    std::cout << "Enter a string: ";
    std::cin >> s;

    deleteBy(s, "by");
    deleteBy(s, "BY");

    std::cout << s << std::endl;

    return 0;
}

void deleteBy(std::string &sRef, std::string z)
{
    int x = sRef.find(z);

    while (x <= sRef.length())
    {
        sRef.erase(x, 2);
        x = sRef.find(z);
    }
}