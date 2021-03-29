#ifndef LIST_2_HPP
#define LIST_2_HPP

#include <iostream>
#include <cassert>
#include "List.hpp"
#include "ListNode.hpp"

template <typename NODETYPE>
class List2 : public List<NODETYPE>
{
public:
    void recursivePrintReverse() const;

private:
    void recursivePrintReverseHelper(ListNode<NODETYPE> *) const;
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
    std::cout << currentPtr->getData() << ' ';
}

#endif