#include <iostream>
#include <string>
#include "List.hpp"

void instructions()
{
    std::cout << "Enter one of the following:\n"
              << " 1 to insert at beginning of list\n"
              << " 2 to insert at end of list\n"
              << " 3 to delete from beginning of list\n"
              << " 4 to delete from end of list\n"
              << " 5 to end list processing\n";
}

template <typename T>
void testList(List<T> &listobject, const std::string &typeName)
{
    std::cout << "Testing a List of " << typeName << " values\n";
    instructions();

    int choice;
    T value;
    do
    {
        std::cout << "? ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter " << typeName << ": ";
            std::cin >> value;
            listobject.insertAtFront(value);
            listobject.print();
            break;
        case 2:
            std::cout << "Enter " << typeName << ": ";
            std::cin >> value;
            listobject.insertAtBack(value);
            listobject.print();
            break;
        case 3:
            if (listobject.removeFromFront(value))
                std::cout << value << " removed from list\n";

            listobject.print();
            break;
        case 4:
            if (listobject.removeFromBack(value))
                std::cout << value << " removed from list\n";

            listobject.print();
            break;
        }

    } while (choice < 5);

    std::cout << "End list test\n\n";
}


int main(int argc, char const *argv[])
{
    List<int> integerList;
    testList(integerList, "integer");

    List<double> doubleList;
    testList(doubleList, "double");

    return 0;
}
