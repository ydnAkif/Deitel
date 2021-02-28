#include <iostream>
#include "List.hpp"

template <typename T>
List<T> &merge(List<T> &first, List<T> &second)
{
    if (first.isEmpty() && second.isEmpty())
    {
        List<T> *ptr = new List<T>;
        return *ptr;
    }

    if (first.isEmpty())
    {
        List<T> *ptr = new List<T>(second);
        return *ptr;
    }

    if (second.isEmpty())
    {
        List<T> *ptr = new List<T>(first);
        return *ptr;
    }

    List<T> tempFirst(first);
    List<T> tempSecond(second);

    List<T> *ptr = new List<T>;
    T value1, value2;

    tempFirst.removeFromFront(value1);
    tempSecond.removeFromFront(value2);

    while (!tempFirst.isEmpty() && !tempSecond.isEmpty())
    {
        if (value1 <= value2)
        {
            ptr->insertAtBack(value1);
            tempFirst.removeFromFront(value1);
        }
        else
        {
            ptr->insertAtBack(value2);
            tempSecond.removeFromFront(value2);
        }
    }

    if (value1 < value2)
    {
        ptr->insertAtBack(value1);
        ptr->insertAtBack(value2);
    }
    else
    {
        ptr->insertAtBack(value2);
        ptr->insertAtBack(value1);
    }

    if (!tempFirst.isEmpty())
    {
        do
        {
            tempFirst.removeFromFront(value1);
            ptr->insertAtBack(value2);
        } while (!tempFirst.isEmpty());
    }
    else
    {
        do
        {
            tempSecond.removeFromFront(value2);
            ptr->insertAtBack(value2);
        } while (!tempSecond.isEmpty());
    }

    return *ptr;
}

int main(int argc, char const *argv[])
{
    List<int> list1, list2;
    int i;

    for (i = 1; i <= 9; i += 2)
        list1.insertAtBack(i);
    list1.print();

    for (i = 2; i <= 10; i += 2)
        list2.insertAtBack(i);
    list2.print();

    List<int> &listRef = merge(list1, list2);

    std::cout << "The merged list is:\n";
    listRef.print();

    delete &listRef;

    return 0;
}
