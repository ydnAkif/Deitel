#ifndef LIST_2_HPP
#define LIST_2_HPP

#include "List.hpp"
#include "ListNode.hpp"

template <typename NODETYPE>
class List2 : public List<NODETYPE>
{
public:
    void insertInOrder(const NODETYPE &);
};

template <typename NODETYPE>
void List2<NODETYPE>::insertInOrder(const NODETYPE &value)
{
    if (this->isEmpty())
    {
        ListNode<NODETYPE> *newPtr = this->getNewNode(value);
        this->firstPtr = this->lastPtr = newPtr;
    }
    else
    {
        if (this->firstPtr->getData() > value)
        {
            this->insertAtFront(value);
        }
        else if (this->lastPtr->getData() < value)
        {
            this->insertAtBack(value);
        }
        else
        {
            ListNode<NODETYPE> *currentPtr = this->firstPtr->getNextPtr();
            ListNode<NODETYPE> *previousPtr = this->firstPtr;
            ListNode<NODETYPE> *newPtr = this->getNewNode(value);

            while (currentPtr != this->lastPtr && currentPtr->getData() < value)
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->getNextPtr();
            }

            previousPtr->setNextPtr(newPtr);
            newPtr->setNextPtr(currentPtr);
        }
    }
}

#endif