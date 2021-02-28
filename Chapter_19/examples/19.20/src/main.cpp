#include <iostream>
#include <iomanip>
#include "Tree.hpp"

int main(int argc, char const *argv[])
{
    Tree<int> intTree;

    std::cout << "Enter 10 integer values:\n";

    for (int i = 0; i < 10; ++i)
    {
        int intValue;
        std::cin >> intValue;
        intTree.insertNode(intValue);
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();

    Tree<double> doubleTree;

    std::cout << std::fixed << std::setprecision(1)
              << "\n\n\nEnter 10 double values:\n";

    for (int j = 0; j < 10; ++j)
    {
        double doubleValue = 0.0;
        std::cin >> doubleValue;
        doubleTree.insertNode(doubleValue);
    }

    std::cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();

    std::cout << std::endl;

    return 0;
}
