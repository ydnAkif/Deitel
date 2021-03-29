#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cassert>
#include "StackNode.hpp"

template <typename NODETYPE>
class Stack
{
private:
    StackNode<NODETYPE> *topPtr;

public:
    Stack();
    ~Stack();
    void push(NODETYPE &);
    NODETYPE pop();
    bool isEmpty() const;
    void print() const;
    StackNode<NODETYPE> *getTopPtr() const;
};

template <typename NODETYPE>
Stack<NODETYPE>::Stack() { topPtr = nullptr; }

template <typename NODETYPE>
Stack<NODETYPE>::~Stack()
{
    StackNode<NODETYPE> *tempPtr, *currentPtr = topPtr;

    while (currentPtr != nullptr)
    {
        tempPtr = currentPtr;
        currentPtr = currentPtr->getNextPtr();
        delete tempPtr;
    }
}

template <typename NODETYPE>
void Stack<NODETYPE>::push(NODETYPE &d)
{
    StackNode<NODETYPE> *newPtr = new StackNode<NODETYPE>(d, topPtr);
    assert(newPtr != nullptr);
    topPtr = newPtr;
}

template <typename NODETYPE>
NODETYPE Stack<NODETYPE>::pop()
{
    assert(!isEmpty());

    StackNode<NODETYPE> *tempPtr = topPtr;

    topPtr = topPtr->nextPtr;
    NODETYPE poppedValue = tempPtr->data;
    delete tempPtr;

    return poppedValue;
}

template <typename NODETYPE>
bool Stack<NODETYPE>::isEmpty() const
{
    return topPtr == nullptr;
}

template <typename NODETYPE>
void Stack<NODETYPE>::print() const
{
    StackNode<NODETYPE> *currentPtr = topPtr;

    if (isEmpty())
        std::cout << "Stack is empty\n";
    else
    {
        std::cout << "The stack is:\n";

        while (currentPtr != nullptr)
        {
            std::cout << currentPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
        }

        std::cout << std::endl;
    }
}

template <typename NODETYPE>
StackNode<NODETYPE> *Stack<NODETYPE>::getTopPtr() const
{
    return topPtr;
}

#endif