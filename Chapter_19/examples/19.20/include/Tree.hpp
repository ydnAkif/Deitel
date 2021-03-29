#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include "TreeNode.hpp"

template <typename NODETYPE>
class Tree
{
public:
    Tree() : rootPtr(nullptr) {}

    void insertNode(const NODETYPE &value)
    {
        insertNodeHelper(&rootPtr, value);
    }

    void preOrderTraversal() const
    {
        preOrderHelper(rootPtr);
    }

    void inOrderTraversal() const
    {
        inOrderHelper(rootPtr);
    }

    void postOrderTraversal() const
    {
        postOrderHelper(rootPtr);
    }

private:
    TreeNode<NODETYPE> *rootPtr;

    void insertNodeHelper(
        TreeNode<NODETYPE> **ptr, const NODETYPE &value)
    {
        if (*ptr == nullptr)
            *ptr = new TreeNode<NODETYPE>(value);
        else
        {
            if (value < (*ptr)->data)
                insertNodeHelper(&((*ptr)->leftPtr), value);
            else
            {
                if (value > (*ptr)->data)
                    insertNodeHelper(&((*ptr)->rightPtr), value);
                else
                    std::cout << value << " dup" << std::endl;
            }
        }
    }

    void preOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr)
        {
            std::cout << ptr->data << ' ';

            preOrderHelper(ptr->leftPtr);
            preOrderHelper(ptr->rightPtr);
        }
    }

    void inOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr)
        {
            inOrderHelper(ptr->leftPtr);
            std::cout << ptr->data << ' ';
            inOrderHelper(ptr->rightPtr);
        }
    }

    void postOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr)
        {
            postOrderHelper(ptr->leftPtr);
            postOrderHelper(ptr->rightPtr);
            std::cout << ptr->data << ' ';
        }
    }
};

#endif