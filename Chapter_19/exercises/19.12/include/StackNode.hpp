#ifndef STACK_NODE_HPP
#define STACK_NODE_HPP

template <typename NODETYPE>
class Stack;

template <typename NODETYPE>
class StackNode
{
    friend class Stack<NODETYPE>;

private:
    NODETYPE data;
    StackNode<NODETYPE> *nextPtr;

public:
    StackNode(const NODETYPE &, StackNode<NODETYPE> *);
    NODETYPE getData() const;
    void setNextPtr(StackNode<NODETYPE> *);
    StackNode<NODETYPE> *getNextPtr() const;
};

template <typename NODETYPE>
StackNode<NODETYPE>::StackNode(const NODETYPE &d, StackNode<NODETYPE> *ptr)
{
    data = d;
    nextPtr = ptr;
}

template <typename NODETYPE>
NODETYPE StackNode<NODETYPE>::getData() const { return data; }

template <typename NODETYPE>
void StackNode<NODETYPE>::setNextPtr(StackNode<NODETYPE> *nPtr) { nextPtr = nPtr; }

template <typename NODETYPE>
StackNode<NODETYPE> *StackNode<NODETYPE>::getNextPtr() const
{
    return nextPtr;
}

#endif