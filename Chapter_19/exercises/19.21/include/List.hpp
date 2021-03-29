#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <cassert>
#include "ListNode.hpp"

template <typename NODETYPE>
class List
{
protected:
    ListNode<NODETYPE> *firstPtr;
    ListNode<NODETYPE> *lastPtr;

    ListNode<NODETYPE> *getNewNode(const NODETYPE &);

public:
    List();
    List(const List<NODETYPE> &);
    ~List();
    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront(NODETYPE &);
    bool removeFromBack(NODETYPE &);
    bool isEmpty() const;
    void print() const;
};

template <typename NODETYPE>
List<NODETYPE>::List()
{
    firstPtr = lastPtr = nullptr;
}

template <typename NODETYPE>
List<NODETYPE>::List(const List<NODETYPE> &copy)
{
    firstPtr = lastPtr = nullptr;

    ListNode<NODETYPE> *currentPtr = copy.firstPtr;

    while (currentPtr != nullptr)
    {
        insertAtBack(currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
}

template <typename NODETYPE>
List<NODETYPE>::~List()
{
    if (!isEmpty())
    {
        std::cout << "Destroying nodes ... \n";

        ListNode<NODETYPE> *currentPtr = firstPtr;
        ListNode<NODETYPE> *tempPtr;

        while (currentPtr != nullptr)
        {
            tempPtr = currentPtr;
            std::cout << tempPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }

    std::cout << "\nAll nodes destroyed\n\n";
}

template <typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value)
{
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;
    else
    {
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }
}

template <typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value)
{
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;
    else
    {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
}

template <typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value)
{
    if (isEmpty())
        return false;
    else
    {
        ListNode<NODETYPE> *tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = nullptr;
        else
            firstPtr = firstPtr->nextPtr;

        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

template <typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value)
{
    if (isEmpty())
        return false;
    else
    {
        ListNode<NODETYPE> *tempPtr = lastPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = nullptr;
        else
        {
            ListNode<NODETYPE> *currentPtr = firstPtr;

            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr;

            lastPtr = currentPtr;
            currentPtr->nextPtr = nullptr;
        }

        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
    return firstPtr == nullptr;
}

template <typename NODETYPE>
ListNode<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &value)
{
    ListNode<NODETYPE> *ptr = new ListNode<NODETYPE>(value);
    assert(ptr != nullptr);

    return ptr;
}

template <typename NODETYPE>
void List<NODETYPE>::print() const
{
    if (isEmpty())
    {
        std::cout << "The list is empty\n\n";
        return;
    }

    ListNode<NODETYPE> *currentPtr = firstPtr;

    std::cout << "The list is: ";

    while (currentPtr != nullptr)
    {
        std::cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    }

    std::cout << std::endl
              << std::endl;
}

#endif
