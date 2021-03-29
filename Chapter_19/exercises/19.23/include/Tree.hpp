#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <cassert>
#include "TreeNode.hpp"

template <typename NODETYPE>
class Tree
{
public:
    Tree();
    void insertNode(const NODETYPE &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;

protected:
    TreeNode<NODETYPE> *rootPtr;

    void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);
    void preOrderHelper(TreeNode<NODETYPE> *) const;
    void inOrderHelper(TreeNode<NODETYPE> *) const;
    void postOrderHelper(TreeNode<NODETYPE> *) const;
};

template <typename NODETYPE>
Tree<NODETYPE>::Tree()
{
    rootPtr = nullptr;
}

template <typename NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value)
{
    insertNodeHelper(&rootPtr, value);
}

template <typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversal() const
{
    preOrderHelper(rootPtr);
}

template <typename NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const
{
    inOrderHelper(rootPtr);
}

template <typename NODETYPE>
void Tree<NODETYPE>::postOrderTraversal() const
{
    postOrderHelper(rootPtr);
}

template <typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> **ptr, const NODETYPE &value)
{
    if (*ptr == nullptr)
    {
        *ptr = new TreeNode<NODETYPE>(value);
        assert(*ptr != nullptr);
    }
    else if (value <= (*ptr)->data)
        insertNodeHelper(&((*ptr)->leftPtr), value);
    else
        insertNodeHelper(&((*ptr)->rightPtr), value);
}

template <typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != nullptr)
    {
        std::cout << ptr->data << ' ';
        preOrderHelper(ptr->leftPtr);
        preOrderHelper(ptr->rightPtr);
    }
}

template <typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != nullptr)
    {
        inOrderHelper(ptr->leftPtr);
        std::cout << ptr->data << ' ';
        inOrderHelper(ptr->rightPtr);
    }
}

template <typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != nullptr)
    {
        postOrderHelper(ptr->leftPtr);
        postOrderHelper(ptr->rightPtr);
        std::cout << ptr->data << ' ';
    }
}

#endif