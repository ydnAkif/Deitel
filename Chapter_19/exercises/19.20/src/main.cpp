#include "List2.hpp"

int main(int argc, char const *argv[])
{
    List2<int> intList;

    for (int i = 1; i <= 10; ++i)
        intList.insertAtBack(i);

    intList.print();
    intList.recursivePrintReverse();

    return 0;
}
