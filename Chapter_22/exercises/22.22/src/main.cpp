#include <iostream>
#include <cstring>

const int SIZE = 20;

int main(int argc, char const *argv[])
{
    char array[5][SIZE];
    int i;

    for (i = 0; i <= 4; ++i)
    {
        std::cout << "Enter a string: ";
        std::cin.getline(&array[i][0], SIZE);
    }

    std::cout << "\nThe string starting with 'b' are:\n";

    for (i = 0; i <= 4; ++i)
        if (array[i][0] == 'b')
            std::cout << &array[i][0] << '\n';

    return 0;
}
