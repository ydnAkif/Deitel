#ifndef QUEUE_NODE_HPP
#define QUEUE_NODE_HPP

template <typename NODETYPE>
class Queue;

template <typename NODETYPE>
class QueueNode
{
    friend class Queue<NODETYPE>;

public:
    QueueNode(const NODETYPE & = 0);
    NODETYPE getData() const;

private:
    NODETYPE data;
    QueueNode<NODETYPE> *nextPtr;
};

template <typename NODETYPE>
QueueNode<NODETYPE>::QueueNode(const NODETYPE &d)
{
    data = d;
    nextPtr = nullptr;
}

template <typename NODETYPE>
NODETYPE QueueNode<NODETYPE>::getData() const { return data; }

#endif