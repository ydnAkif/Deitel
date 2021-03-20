#include <iostream>
#include <cstring>

const int SIZE = 6;

int main(int argc, char const *argv[])
{
    char stringValue[SIZE];
    int sum = 0;

    for (int i = 1; i <=4; ++i)
    {
        std::cout << "Enter an integer string: ";
        std::cin >> stringValue;
        sum += atoi(stringValue);
    }

    std::cout << "The total of the values is " << sum << std::endl; 

    return 0;
}
