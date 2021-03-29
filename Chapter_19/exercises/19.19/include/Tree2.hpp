#ifndef TREE_2_HPP
#define TREE_2_HPP

#include <cassert>
#include "TreeNode.hpp"
#include "Tree.hpp"

template <typename NODETYPE>
class Tree2 : public Tree<NODETYPE>
{
public:
    int getDepth() const;

private:
    void determineDepth(TreeNode<NODETYPE> *, int *, int *) const;
};

template <typename NODETYPE>
int Tree2<NODETYPE>::getDepth() const
{
    int totalDepth = 0, currentDepth = 0;

    determineDepth(this->rootPtr, &totalDepth, &currentDepth);

    return totalDepth;
}

template <typename NODETYPE>
void Tree2<NODETYPE>::determineDepth(TreeNode<NODETYPE> *ptr, int *totPtr, int *currPtr) const
{
    if (ptr != nullptr)
    {
        ++(*currPtr);

        if (*currPtr > *totPtr)
            *totPtr = *currPtr;

        determineDepth(ptr->getLeftPtr(), totPtr, currPtr);
        determineDepth(ptr->getRightPtr(), totPtr, currPtr);
        --(*currPtr);
    }
}

#endif