#include <iostream>
#include <array>
#include <list>
#include <algorithm>
#include <iterator>

template <typename T>
void printList(const std::list<T> &);

int main(int argc, char const *argv[])
{
    const size_t SIZE = 4;

    std::array<int, SIZE> ints = {2, 6, 4, 8};

    std::list<int> values;
    std::list<int> otherValues;

    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);

    std::cout << "values contains: ";
    printList(values);

    values.sort();
    std::cout << "\nvalues after sorting contains: ";
    printList(values);

    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    std::cout << "\nAfter insert, otherValues contains: ";
    printList(otherValues);

    values.splice(values.cend(), otherValues);
    std::cout << "\nAfter splice, values contains: ";
    printList(values);

    values.sort();
    std::cout << "\nAfter sort, values contains: ";
    printList(values);

    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    otherValues.sort();
    std::cout << "\nAfter insert and sort, otherValues contains: ";
    printList(otherValues);

    values.merge(otherValues);
    std::cout << "\nAfter merge:\n  values contains: ";
    printList(values);
    std::cout << "\n    otherValues contains: ";
    printList(otherValues);

    values.pop_front();
    values.pop_back();
    std::cout << "\nAfter pop_front() and pop_back():\n    values contains: ";
    printList(values);

    values.unique();
    std::cout << "\nAfter unique, values contains: ";
    printList(values);

    values.swap(otherValues);
    std::cout << "\nAfter swap:\n   values contains: ";
    printList(values);
    std::cout << "\n    otherValues contains: ";
    printList(otherValues);

    values.assign(otherValues.cbegin(), otherValues.cend());
    std::cout << "\nAfter assign, values contains: ";
    printList(values);

    values.merge(otherValues);
    std::cout << "\nAfter merge, values contains: ";
    printList(values);

    values.remove(4);
    std::cout << "\nAfter remove(4), values contains: ";
    printList(values);
    std::cout << std::endl;

    return 0;
}

template <typename T>
void printList(const std::list<T> &listRef)
{
    if (listRef.empty())
        std::cout << "List is empty";
    else
    {
        std::ostream_iterator<T> output(std::cout, " ");
        std::copy(listRef.cbegin(), listRef.cend(), output);
    }
}