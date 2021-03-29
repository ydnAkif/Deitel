#include <iostream>
#include "Tree2.hpp"

int main(int argc, char const *argv[])
{
    Tree2<int> intTree;
    int intVal;

    std::cout << "Enter 10 integer values:\n";

    for (int i = 0; i < 10; ++i)
    {
        std::cin >> intVal;
        intTree.insertNode(intVal);
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();

    std::cout << "\n\nThere are " << intTree.getDepth()
              << " levels in this binary tree\n";

    return 0;
}
