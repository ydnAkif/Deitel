#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

template <typename NODETYPE>
class List;

template <typename NODETYPE>
class ListNode
{
    friend class List<NODETYPE>;

private:
    NODETYPE data;
    ListNode<NODETYPE> *nextPtr;

public:
    //NODETYPE data;
    ListNode(const NODETYPE &);
    NODETYPE getData() const;
    void setNextPtr(ListNode<NODETYPE> *);
    ListNode<NODETYPE> *getNextPtr() const;
    NODETYPE *getAddress();
};

template <typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
{
    data = info;
    nextPtr = nullptr;
}

template <typename NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const
{
    return data;
}

template <typename NODETYPE>
void ListNode<NODETYPE>::setNextPtr(ListNode<NODETYPE> *nPtr)
{
    nextPtr = nPtr;
}

template <typename NODETYPE>
ListNode<NODETYPE> *ListNode<NODETYPE>::getNextPtr() const
{
    return nextPtr;
}

template <typename NODETYPE>
NODETYPE *ListNode<NODETYPE>::getAddress()
{
    return &(this->data);
}

#endif