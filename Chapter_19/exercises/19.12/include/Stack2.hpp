#ifndef STACK_2_HPP
#define STACK_2_HPP

#include <iostream>
#include <cassert>
#include "Stack.hpp"
#include "StackNode.hpp"

template <typename NODETYPE>
class Stack2 : public Stack<NODETYPE>
{
public:
    NODETYPE stackTop() const;
};

template <typename NODETYPE>
NODETYPE Stack2<NODETYPE>::stackTop() const
{
    return !this->isEmpty() ? this->getTopPtr()->getData() : static_cast<NODETYPE>(0);
}

#endif