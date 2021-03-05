#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <new>
#include <cstdlib>
#include "QueueNode.hpp"

template <typename NODETYPE>
class Queue
{
public:
    Queue();
    ~Queue();

    void enqueue(NODETYPE);
    NODETYPE dequeue();
    bool isEmpty() const;
    void print() const;

private:
    QueueNode<NODETYPE> *headPtr;
    QueueNode<NODETYPE> *tailPtr;
};

template <typename NODETYPE>
Queue<NODETYPE>::Queue()
{
    headPtr = tailPtr = nullptr;
}

template <typename NODETYPE>
Queue<NODETYPE>::~Queue()
{
    QueueNode<NODETYPE> *tempPtr, *currentPtr = headPtr;

    while (currentPtr != nullptr)
    {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        delete tempPtr;
    }
}

template <typename NODETYPE>
void Queue<NODETYPE>::enqueue(NODETYPE d)
{
    QueueNode<NODETYPE> *newPtr = new QueueNode<NODETYPE>(d);
    assert(newPtr != nullptr);

    if (isEmpty())
        headPtr = tailPtr = newPtr;
    else
    {
        tailPtr->nextPtr = newPtr;
        tailPtr = newPtr;
    }
}

template <typename NODETYPE>
NODETYPE Queue<NODETYPE>::dequeue()
{
    assert(!isEmpty());

    QueueNode<NODETYPE> *tempPtr = headPtr;

    headPtr = headPtr->nextPtr;
    NODETYPE value = tempPtr->data;
    delete tempPtr;

    if (headPtr == nullptr)
        tailPtr = nullptr;

    return value;
}

template <typename NODETYPE>
bool Queue<NODETYPE>::isEmpty() const { return headPtr == nullptr; }

template <typename NODETYPE>
void Queue<NODETYPE>::print() const
{
    QueueNode<NODETYPE> *currentPtr = headPtr;

    if (isEmpty())
        std::cout << "Queue is empty\n";
    else
    {
        std::cout << "The queue is:\n";

        while (currentPtr != nullptr)
        {
            std::cout << currentPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
        }

        std::cout << std::endl;
    }
}

#endif