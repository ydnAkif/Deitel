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

    std::cout << "\n\nThe level order traversal is:\n";
    intTree.levelOrderTraversal();

    std::cout << std::endl;

    return 0;
}
