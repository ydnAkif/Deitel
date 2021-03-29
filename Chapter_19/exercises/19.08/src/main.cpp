#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List2.hpp"

int sumList(List2<int> &listRef);

double averageList(List2<int> &listRef);

int main(int argc, char const *argv[])
{
    srand(time(0));

    List2<int> intList;

    for (int i = 1; i <= 25; ++i)
        intList.insertInOrder(rand() % 101);
    intList.print();

    std::cout << "The sum of the elements is: " << sumList(intList) << '\n';
    std::cout << "The average of the elements is " << averageList(intList) << '\n';
    
    return 0;
}

int sumList(List2<int> &listRef)
{
    List2<int> temp(listRef);
    int sum = 0, value;

    while (!temp.isEmpty())
    {
        temp.removeFromFront(value);
        sum += value;
    }

    return sum;
}

double averageList(List2<int> &listRef)
{
    List2<int> temp(listRef);
    int sum = 0, value, count = 0;

    while (!temp.isEmpty())
    {
        temp.removeFromFront(value);
        ++count;
        sum += value;
    }

    return static_cast<double>(sum) / count;
}