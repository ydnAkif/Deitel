#include <iostream>
#include <cstring>
#include "Tree.hpp"
#include "Strings.hpp"

int main(int argc, char const *argv[])
{
    Tree<Strings> stringsTree;
    char sentence[80], *tokenPtr;

    std::cout << "Enter a sentence:\n";
    std::cin.getline(sentence, 80);

    tokenPtr = strtok(sentence, " ");

    while (tokenPtr != nullptr)
    {
        Strings *newStrings = new Strings(tokenPtr);
        stringsTree.insertNode(*newStrings);
        tokenPtr = strtok(0, " ");
    }

    std::cout << "\nPreorder traversal\n";
    stringsTree.preOrderTraversal();

    std::cout << "\nInorder traversal\n";
    stringsTree.inOrderTraversal();

    std::cout << "\nPostorder traversal\n";
    stringsTree.postOrderTraversal();

    std::cout << std::endl;

    return 0;
}
