#ifndef TREE_2_HPP
#define TREE_2_HPP

#include <iostream>
#include <cassert>
#include "TreeNode.hpp"
#include "Queue.hpp"
#include "Tree.hpp"

template <typename NODETYPE>
class Tree2 : public Tree<NODETYPE>
{
public:
    void levelOrderTraversal();
};

template <typename NODETYPE>
void Tree2<NODETYPE>::levelOrderTraversal()
{
    Queue<TreeNode<NODETYPE> *> queue;
    TreeNode<NODETYPE> *nodePtr;

    if (this->rootPtr != nullptr)
        queue.enqueue(this->rootPtr);

    while (!queue.isEmpty())
    {
        nodePtr = queue.dequeue();
        std::cout << nodePtr->getData() << ' ';

        if (nodePtr->getLeftPtr() != nullptr)
            queue.enqueue(nodePtr->getLeftPtr());
        if (nodePtr->getRightPtr() != nullptr)
            queue.enqueue(nodePtr->getRightPtr());
    }
}

#endif