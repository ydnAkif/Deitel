#ifndef STACK_COMPOSITION_HPP
#define STACK_COMPOSITION_HPP

#include "List.hpp"

template <typename STACKTYPE>
class Stack
{
public:
    void push(const STACKTYPE &data)
    {
        stackList.insertAtFront(data);
    }

    bool pop(STACKTYPE &data)
    {
        return stackList.removeFromFront(data);
    }

    bool isStackEmpty() const
    {
        return stackList.isEmpty();
    }

    void printStack() const
    {
        stackList.print();
    }

private:
    List<STACKTYPE> stackList;
};
#endif // STACK_COMPOSITION_HPP
