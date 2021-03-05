#ifndef LIST_2_HPP
#define LIST_2_HPP

#include <iostream>
#include <cassert>
#include "ListNode.hpp"
#include "List.hpp"

template <typename NODETYPE>
class List2 : public List<NODETYPE>
{
public:
    void recursivePrintReverse() const;
    NODETYPE *recursiveSearch(NODETYPE &) const;

private:
    void recursivePrintReverseHelper(ListNode<NODETYPE> *) const;
    NODETYPE *recursiveSearhHelper(ListNode<NODETYPE> *, NODETYPE &) const;
};

template <typename NODETYPE>
void List2<NODETYPE>::recursivePrintReverse() const
{
    std::cout << "The list printed recursively backwards is:\n";
    recursivePrintReverseHelper(this->firstPtr);
    std::cout << std::endl;
}

template <typename NODETYPE>
void List2<NODETYPE>::recursivePrintReverseHelper(ListNode<NODETYPE> *currentPtr) const
{
    if (currentPtr == nullptr)
        return;
    recursivePrintReverseHelper(currentPtr->getNextPtr());
    std::cout << currentPtr->data << ' ';
}

template <typename NODETYPE>
NODETYPE *List2<NODETYPE>::recursiveSearch(NODETYPE &val) const
{
    return recursiveSearhHelper(this->firstPtr, val);
}

template <typename NODETYPE>
NODETYPE *List2<NODETYPE>::recursiveSearhHelper(ListNode<NODETYPE> *currentPtr, NODETYPE &value) const
{
    if (currentPtr == nullptr)
        return NULL;

    if (currentPtr->getData() == value)
        return currentPtr->getAddress();
    return recursiveSearhHelper(currentPtr->getNextPtr(), value);
}

#endif