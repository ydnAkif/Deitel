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
    explicit ListNode(const NODETYPE &info)
        : data(info), nextPtr(nullptr) {}

    NODETYPE getData() const { return data; }
};

#endif