#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree2.hpp"

int main(int argc, char const *argv[])
{
    srand(time(0));

    Tree2<int> intTree;
    int intVal;

    std::cout << "The values being placed int the tree are:\n";

    for (int i = 1; i <= 15; ++i)
    {
        intVal = rand() % 100;
        std::cout << intVal << ' ';
        intTree.insertNode(intVal);
    }

    std::cout << "\n\nEnter a value to search for: ";
    std::cin >> intVal;

    TreeNode<int> *ptr = intTree.binarySearch(intVal);

    if (ptr != nullptr)
        std::cout << ptr->getData() << " was found\n";
    else
        std::cout << "Element was not found\n";

    std::cout << std::endl;

    return 0;
}
