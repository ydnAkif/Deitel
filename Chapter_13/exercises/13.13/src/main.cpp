#include <iostream>

using std::cin;
using std::cout;

const int SIZE = 80;

int main(int argc, char const *argv[])
{
    char string[SIZE];

    for (size_t i = 0; i < 3; ++i)
    {
        cout << "Enter a string: ";
        cin >> string;
        cout << "String is " << string << '\n';
    }

    return 0;
}
