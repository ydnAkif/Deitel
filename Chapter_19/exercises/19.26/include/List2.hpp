#ifndef LIST_2_HPP
#define LIST_2_HPP

#include <cassert>
#include "ListNode.hpp"
#include "List.hpp"

template <typename NODETYPE>
class List2 : public List<NODETYPE>
{
public:
    bool deleteNode(const NODETYPE &, NODETYPE &);
};

template <typename NODETYPE>
bool List2<NODETYPE>::deleteNode(const NODETYPE &val, NODETYPE &deletedVal)
{
    if (this->isEmpty())
        return false;
    else
    {
        if (this->firstPtr->getData() == val)
        {
            this->removeFromFront(deletedVal);
            return true;
        }
        else if (this->lastPtr->getData() == val)
        {
            this->removeFromBack(deletedVal);
            return true;
        }
        else
        {
            ListNode<NODETYPE> *currentPtr = this->firstPtr->getNextPtr();
            ListNode<NODETYPE> *previousPtr = this->firstPtr;

            while (currentPtr != this->lastPtr && currentPtr->getData() < val)
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->getNextPtr();
            }

            if (currentPtr->getData() == val)
            {
                ListNode<NODETYPE> *tempPtr = currentPtr;
                deletedVal = currentPtr->getData();
                previousPtr->setNextPtr(currentPtr->getNextPtr());
                delete tempPtr;
                return true;
            }
            else
                return false;
        }
    }
}

#endif