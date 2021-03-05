#include <iostream>
#include <iomanip>
#include <Tree.hpp>

int main(int argc, char const *argv[])
{
    Tree<int> intTree;
    int intVal, i;

    std::cout << "Enter 10 integer values:\n";

    for (i = 0; i < 10; ++i)
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

    Tree<double> doubleTree;
    double doubleVal;

    std::cout << "\n\n\nEnter 10 double values:\n"
              << std::setiosflags(std::ios::fixed | std::ios::showpoint)
              << std::setprecision(1);
    for (i = 0; i < 10; ++i)
    {
        std::cin >> doubleVal;
        doubleTree.insertNode(doubleVal);
    }

    std::cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();

    return 0;
}
