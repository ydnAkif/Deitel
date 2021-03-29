#include <iostream>
#include <cstring>

const int SIZE = 20;

int main(int argc, char const *argv[])
{
    int length;
    char array[5][SIZE];

    for (int i = 0; i <= 4; ++i)
    {
        std::cout << "Enter a string: ";
        std::cin.getline(&array[i][0], SIZE);
    }

    std::cout << "\nThe string ending with \"ED\" are:\n";

    for (int i = 0; i <= 4; ++i)
    {
        length = strlen(&array[i][0]);

        if (strcmp(&array[i][length - 2], "ED") == 0)
            std::cout << &array[i][0] << '\n';
    }

    return 0;
}
