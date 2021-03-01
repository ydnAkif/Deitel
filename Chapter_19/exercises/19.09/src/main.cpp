#include <iostream>
#include "List.hpp"

template <typename T>
void reverseList(List<T> &first, List<T> &second)
{
    List<T> temp(second);
    T value;

    while (!temp.isEmpty())
    {
        temp.removeFromFront(value);
        first.insertAtFront(value);
    }
}

int main(int argc, char const *argv[])
{
    List<char> list1, list2;

    for (char c = 'a'; c <= 'g'; ++c)
        list1.insertAtBack(c);

    list1.print();

    reverseList(list2, list1);
    std::cout << "After reversing:\n";
    list2.print();

    return 0;
}
