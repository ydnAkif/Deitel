#include <iostream>

using std::cin;
using std::cout;

#include "List2.hpp"

int main()
{
    List2<int> intList;

    for (int i = 2; i <= 20; i += 2)
        intList.insertAtBack(i);

    intList.print();

    int value, *ptr;

    cout << "Enter a value to search for: ";
    cin >> value;
    ptr = intList.recursiveSearch(value);

    if (ptr != 0)
        cout << *ptr << " was found\n";
    else
        cout << "Element not found\n";

    return 0;
}