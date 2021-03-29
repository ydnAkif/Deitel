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
    TreeNode<NODETYPE> *binarySearch(int) const;

private:
    TreeNode<NODETYPE> *binarySearchHelper(TreeNode<NODETYPE> *, int) const;
};

template <typename NODETYPE>
TreeNode<NODETYPE> *Tree2<NODETYPE>::binarySearch(int val) const
{
    return binarySearchHelper(this->rootPtr, val);
}

template <typename NODETYPE>
TreeNode<NODETYPE> *Tree2<NODETYPE>::binarySearchHelper(TreeNode<NODETYPE> *ptr, int value) const
{
    if (ptr == nullptr)
        return NULL;
    std::cout << "Compairing " << value << " to " << ptr->getData();

    if (value == ptr->getData())
    {
        std::cout << "; search complete\n";
        return ptr;
    }
    else if (value < ptr->getData())
    {
        std::cout << "; smaller, walk left\n";
        return binarySearchHelper(ptr->getLeftPtr(), value);
    }
    else
    {
        std::cout << "; larger, walk right\n";
        return binarySearchHelper(ptr->getRightPtr(), value);
    }
}

#endif