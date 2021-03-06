#ifndef TREE_2_HPP
#define TREE_2_HPP

#include <iostream>
#include <cassert>
#include "TreeNode.hpp"
#include "Tree.hpp"

template <typename NODETYPE>
class Tree2 : public Tree<NODETYPE>
{
public:
    void outputTree() const;

private:
    void outputTreeHelper(TreeNode<NODETYPE> *, int) const;
};

template <typename NODETYPE>
void Tree2<NODETYPE>::outputTree() const
{
    outputTreeHelper(this->rootPtr, 0);
}

template <typename NODETYPE>
void Tree2<NODETYPE>::outputTreeHelper(TreeNode<NODETYPE> *ptr, int totalSpaces) const
{
    if (ptr != nullptr)
    {
        outputTreeHelper(ptr->getRightPtr(), totalSpaces + 5);

        for (int i = 1; i <= totalSpaces; ++i)
            std::cout << ' ';

        std::cout << ptr->getData() << '\n';
        outputTreeHelper(ptr->getLeftPtr(), totalSpaces + 5);
    }
}
#endif