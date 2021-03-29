#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

template <typename NODETYPE>
class Tree;

template <typename NODETYPE>
class TreeNode
{
    friend class Tree<NODETYPE>;

private:
    TreeNode<NODETYPE> *leftPtr;
    TreeNode<NODETYPE> *rightPtr;
    NODETYPE data;

public:
    TreeNode(const NODETYPE &d)
        : leftPtr(nullptr), rightPtr(nullptr), data(d)
    {
    }

    NODETYPE getData() const
    {
        return data;
    }
};

#endif