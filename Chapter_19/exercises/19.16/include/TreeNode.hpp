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
    NODETYPE data;
    TreeNode<NODETYPE> *rightPtr;

public:
    TreeNode(const NODETYPE &);
    NODETYPE getData() const;
    TreeNode<NODETYPE> *getLeftPtr() const;
    TreeNode<NODETYPE> *getRightPtr() const;
    void setLeftPtr(TreeNode<NODETYPE> *);
    void setRightPtr(TreeNode<NODETYPE> *);
};

template <typename NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &d)
{
    data = d;
    leftPtr = rightPtr = nullptr;
}

template <typename NODETYPE>
NODETYPE TreeNode<NODETYPE>::getData() const
{
    return data;
}

template <typename NODETYPE>
TreeNode<NODETYPE> *TreeNode<NODETYPE>::getLeftPtr() const
{
    return leftPtr;
}

template <typename NODETYPE>
TreeNode<NODETYPE> *TreeNode<NODETYPE>::getRightPtr() const
{
    return rightPtr;
}

template <typename NODETYPE>
void TreeNode<NODETYPE>::setLeftPtr(TreeNode<NODETYPE> *ptr)
{
    leftPtr = ptr;
}

template <typename NODETYPE>
void TreeNode<NODETYPE>::setRightPtr(TreeNode<NODETYPE> *ptr)
{
    rightPtr = ptr;
}

#endif