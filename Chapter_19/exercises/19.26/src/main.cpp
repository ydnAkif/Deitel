#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List2.hpp"

int main(int argc, char const *argv[])
{
    srand(time(0));

    List2<int> intList;

    for (int i = 1; i <= 10; ++i)
        intList.insertInOrder(rand() % 101);

    intList.print();

    int value, deletedValue;

    std::cout << "Enter an integer to delete (-1 to end): ";
    std::cin >> value;

    while (value != -1)
    {
        if (intList.deleteNode(value, deletedValue))
        {
            std::cout << deletedValue << " was deleted from the list\n";
            intList.print();
        }
        else
            std::cout << "Element was not found";

        std::cout << "Enter an integer to delete (-1 to end): ";
        std::cin >> value;
    }

    return 0;
}
